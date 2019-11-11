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

		cout << "주문하신 아이스크림 선디의 가격은 " << ice.ComputePrice() << "$ 입니다. \n" << endl;
		cout << "현재까지 주문하신 아이스크림 선디의 가격은 " << total << "$ 입니다. \n" << endl;
		q.push(ice);

		cout << "주문을 더 하시겠습니까? (1. Yes or 2. No) : ";
		cin >> choice;
		cout << "\n";

		while (choice != 1 && choice != 2)
		{
			cout << "주문을 더 하시겠습니까? (1. Yes or 2. No) : ";
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
	cout << "[영수증] \n" << endl;
	cout << "상품명                   " << "단가   " << "수량   " << "금액  " << endl;
	cout << "\n" << endl;

	while (!q.empty())
	{
		q.front();
		//ice.Receipt();
		q.front().Receipt();
		q.pop();
	}

	cout << "\n" << endl;
	cout << "합계 금액                              $" << total << " \n" << endl;

	return 0;
}
