import cv2
import glob
import math
import numpy as np

from PIL import Image


img_folder="/Users/jeffl/PycharmProjects/Opencv/0"


def im_trim1(img):
    x = 0
    y = 0
    w = 64
    h = 64
    img_trim1 = img[y:y + h, x:x + w]
    return img_trim1

def im_trim2(img):
    x = 0
    y = 64
    w = 64
    h = 64
    img_trim2 = img[y:y + h, x:x + w]
    return img_trim2


def im_corr(img_trim1, img_trim2):
    temp1=0
    temp2=0
    temp3=0
    temp4=0
    temp5=0
    temp=0
    for i in range(64):
        for j in range(64):
            temp1 += (img_trim1[i, j]-np.mean(img_trim1))*(img_trim2[i, j]-np.mean(img_trim2))
            temp2 = img_trim1[i, j] - np.mean(img_trim1)
            temp3 = img_trim2[i, j] - np.mean(img_trim2)
            temp4 += temp2*temp2
            temp5 += temp3*temp3
    temp = temp1 / np.sqrt(temp4 * temp5)
    return temp

def im_corr2(img_trim1, img_trim2):
    temp1=0
    temp2=0
    temp3=0
    temp4=0
    temp5=0
    temp=0
    for i in range(64):
        for j in range(64):
            img_trim1[i, j]=0
            img_trim2[i, j]=255

    for i in range(64):
        for j in range(64):
            temp1 += (img_trim1[i, j]-np.mean(img_trim1))*(img_trim2[i, j]-np.mean(img_trim2))
            temp2 = img_trim1[i, j] - np.mean(img_trim1)
            temp3 = img_trim2[i, j] - np.mean(img_trim2)
            temp4 += temp2*temp2
            temp5 += temp3*temp3
    temp = temp1 / np.sqrt(temp4 * temp5)
    return temp

f = open("/Users/jeffl/PycharmProjects/Opencv/Correlation.txt", 'w')
for i in range(4360):
    if i <10:
        org_image = cv2.imread('0000000'+str(i)+'.bmp', cv2.IMREAD_GRAYSCALE)
    elif i<100:
        org_image = cv2.imread('000000' + str(i) + '.bmp', cv2.IMREAD_GRAYSCALE)
    elif i<1000:
        org_image = cv2.imread('00000' + str(i) + '.bmp', cv2.IMREAD_GRAYSCALE)
    else:
        org_image = cv2.imread('0000' + str(i) + '.bmp', cv2.IMREAD_GRAYSCALE)
    image1 = im_trim1(org_image)
    image2 = im_trim2(org_image)
    image=im_corr(image1, image2)
    #same=im_corr(image1, image1)
    #diff=im_corr2(image1, image2)

    f.write(str(image))
    f.write('\n')

    #f.write(str(image))
f.close()
    #print(same)
    #print(diff)