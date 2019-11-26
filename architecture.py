import torch
import torch.nn as nn
import torchvision.datasets as datasets
import torchvision.transforms as transforms
import matplotlib.pyplot as plt
import random


class CNN(nn.Module):
    def __init__(self):
        super(CNN, self).__init__()
        # L1 ImgIn shape=(?, 28, 28, 1)
        #    Conv     -> (?, 28, 28, 10)
        #    Pool     -> (?, 14, 14, 10)
        self.layer1 = nn.Sequential(
            nn.Conv2d(1, 10, kernel_size=3, stride=1, padding=1),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2, stride=2))
        # L2 ImgIn shape=(?, 14, 14, 10)
        #    Conv      ->(?, 14, 14, 20)
        #    Pool      ->(?, 7, 7, 20)
        self.layer2 = nn.Sequential(
            nn.Conv2d(10, 20, kernel_size=3, stride=1, padding=1),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2, stride=2))
        # Final FC 7x7x20 inputs -> 10 outputs
        self.fc = nn.Linear(7 * 7 * 20, 10, bias=True)
        nn.init.kaiming_uniform_(self.fc.weight)

    def forward(self, x):
        out = self.layer1(x)
        out = self.layer2(out)
        out = out.view(out.size(0), -1)   # Flatten them for FC
        out = self.fc(out)
        return out


class CustomFullyConnected(nn.Module):
    def __init__(self):
        super(CustomFullyConnected, self).__init__()
        self.fc1 = nn.Linear(28*28, 300, bias=True)
        nn.init.kaiming_uniform_(self.fc1.weight)

        self.fc2 = nn.Linear(300, 100, bias=True)
        nn.init.kaiming_uniform_(self.fc2.weight)

        self.fc3 = nn.Linear(100, 10, bias=True)
        nn.init.kaiming_uniform_(self.fc3.weight)

    def forward(self, x):
        out = self.fc1(x)
        out = self.fc2(out)
        out = self.fc3(out)
        return out


def mnist_dataset():
    mnist_train = datasets.MNIST(root='../data/',
                                 train=True,
                                 transform=transforms.ToTensor(),
                                 download=True)

    mnist_test = datasets.MNIST(root='../data/',
                                train=False,
                                transform=transforms.ToTensor(),
                                download=True)
    return mnist_train, mnist_test

def test_CNN(mnist_test, model, device):
    with torch.no_grad():
        X_test = mnist_test.test_data.view(len(mnist_test), 1, 28, 28).float().to(device)
        Y_test = mnist_test.test_labels.to(device)

        prediction = model(X_test)
        correct_prediction = torch.argmax(prediction, 1) == Y_test
        accuracy = correct_prediction.float().mean()
        print('Accuracy:', accuracy.item())

        # Get one and predict
        r = random.randint(0, len(mnist_test) - 1)
        X_single_data = mnist_test.test_data[r:r + 1].view(1, 1, 28, 28).float().to(device)
        Y_single_data = mnist_test.test_labels[r:r + 1].to(device)

        single_prediction = model(X_single_data)

        plt.imshow(mnist_test.test_data[r:r + 1].view(28, 28), cmap='Greys', interpolation='nearest')
        plt.title('Label: {}, Prediction: {}'.format(Y_single_data.item(), torch.argmax(single_prediction, 1).item()))
        plt.show()


def test_FullyConnected(mnist_test, model, device):
    with torch.no_grad():
        X_test = mnist_test.test_data.view(-1, 28 * 28).float().to(device)
        Y_test = mnist_test.test_labels.to(device)

        prediction = model(X_test)
        correct_prediction = torch.argmax(prediction, 1) == Y_test
        accuracy = correct_prediction.float().mean()
        print('Accuracy:', accuracy.item())

        # Get one and predict
        r = random.randint(0, len(mnist_test) - 1)
        X_single_data = mnist_test.test_data[r:r + 1].view(-1, 28 * 28).float().to(device)
        Y_single_data = mnist_test.test_labels[r:r + 1].to(device)

        single_prediction = model(X_single_data)

        plt.imshow(mnist_test.test_data[r:r + 1].view(28, 28), cmap='Greys', interpolation='nearest')
        plt.title('Label: {}, Prediction: {}'.format(Y_single_data.item(), torch.argmax(single_prediction, 1).item()))
        plt.show()
