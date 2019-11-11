#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <queue>

#include "header.h"

using namespace std;

int main(void)
{
	IceCreamSundae ice ;
	queue<IceCreamSundae> q;

	int choice = 0, total = 0;
	int cnt = 0;

	q.empty();

	while (choice != 2)
	{
		ice.OutputDescription();
		total += ice.ComputePrice();

		cout << "�ֹ��Ͻ� ���̽�ũ�� ������ ������ " << ice.ComputePrice() << "$ �Դϴ�. \n" << endl;
		cout << "������� �ֹ��Ͻ� ���̽�ũ�� ������ ������ " << total << "$ �Դϴ�. \n" << endl;
		q.push(ice);

		cout << "�ֹ��� �� �Ͻðڽ��ϱ�? (1. Yes or 2. No) : ";
		cin >> choice;
		cout << "\n";

		while (choice != 1 && choice != 2)
		{
			cout << "�ֹ��� �� �Ͻðڽ��ϱ�? (1. Yes or 2. No) : ";
			cin >> choice;
			cout << "\n";
		}

		if (choice == 1)
		{
			cnt++;
			continue;
		}

		else if (choice == 2)
			break;
	}

	cout << "\n" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "\n" << endl;
	cout << "[������] \n" << endl;
	cout << "��ǰ��                   " << "�ܰ�   " << "����   " << "�ݾ�  " << endl;
	cout << "\n" << endl;

	while (!q.empty())
	{
		q.front();
		//ice.Receipt();
		q.front().Receipt();
		q.pop();
	}

	cout << "\n" << endl;
	cout << "�հ� �ݾ�                              $" << total << " \n" << endl;

	return 0;
}
