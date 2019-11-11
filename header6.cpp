#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>

#include "header.h"
using namespace std;

void IceCreamSundae::OutputDescription()
{
	
	cout << "���̽�ũ�� ������ ����\n";
	cout << "1. ���ݸ� ���̽�ũ�� ���� \n";
	cout << "2. �ٴҶ� ���̽�ũ�� ���� \n";
	cout << "3. ���� ���̽�ũ�� ���� \n";
	cout << "���̽�ũ�� ������ ����(���ݸ�, �ٴҶ�, ����)�� �����Ͻÿ� : ";
	cin >> kind;
	cout << "\n";

	if (kind != 1 && kind != 2 && kind != 3)
	{
		cout << "���̽�ũ�� ������ ������ �ٽ� ������ �ּ���. \n" << endl;
		OutputDescription();
	}

	else
	{
		cout << "���̽�ũ�� ������ ũ��(1. ��($10),   2. ��($14),   3. ��($17))�� �����Ͻÿ� : ";
		cin >> size;

		while (size != 1 && size != 2 && size != 3)
		{
			cout << "���̽�ũ�� ������ ũ�⸦ �ٽ� �������ּ���. \n";
			cout << "���̽�ũ�� ������ ũ��(1. ��($10),   2. ��($14),   3. ��($17))�� �����Ͻÿ� : ";
			cin >> size;
			cout << "\n";
		}

		if (size == 1 || size == 2 || size == 3)
		{
			cout << "������ ����(���δ� $2)�� �����Ͻÿ� : ";
			cin >> topp;
			cout << "\n";
		}
	}
}

int IceCreamSundae::ComputePrice()
{
	if (kind == 1 || kind == 2 || kind == 3)
	{
		if (size == 1)
		{
			price = 10;
		}
		else if (size == 2)
		{
			price = 14;
		}
		else if (size == 3)
		{
			price = 17;
		}
		else
		{
			price = 0;
			topp = 0;
		}
		sum = price + topp * 2;
	}
	else
		sum = 0;

	return sum;
}

void IceCreamSundae::Receipt()
{
	if (kind == 1)
		cout << "���ݸ� ���̽�ũ�� ����" << "  10" << "      " << 1 << "      " << 10 << endl;

	else if (kind == 2)
		cout << "�ٴҶ� ���̽�ũ�� ����" << "  10" << "      " << 1 << "      " << 10 << endl;

	else if (kind == 3)
		cout << "���� ���̽�ũ�� ����  " << "  10" << "      " << 1 << "      " << 10 << endl;

	if (size == 1)
		cout << "�� ������ (��)" << "            0" << "      " << 1 << "      " << 0 << endl;
		
	else if (size == 2)
		cout << "�� ������ (��)" << "            4" << "      " << 1 << "      " << 4 << endl;

	else if (size == 3)
		cout << "�� ������ (��)" << "            7" << "      " << 1 << "      " << 7 << endl;

	if (topp != 0)
		cout << "�� ����                 " << "  2" << "       " << topp << "     " << 2 * topp << endl;
}

