#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>

#include "header.h"
using namespace std;

void IceCreamSundae::OutputDescription()
{
	
	cout << "아이스크림 선디의 종류\n";
	cout << "1. 초콜릿 아이스크림 선디 \n";
	cout << "2. 바닐라 아이스크림 선디 \n";
	cout << "3. 딸기 아이스크림 선디 \n";
	cout << "아이스크림 선디의 종류(초콜릿, 바닐라, 딸기)를 선택하시오 : ";
	cin >> kind;
	cout << "\n";

	if (kind != 1 && kind != 2 && kind != 3)
	{
		cout << "아이스크림 선디의 종류를 다시 선택해 주세요. \n" << endl;
		OutputDescription();
	}

	else
	{
		cout << "아이스크림 선디의 크기(1. 소($10),   2. 중($14),   3. 대($17))를 선택하시오 : ";
		cin >> size;

		while (size != 1 && size != 2 && size != 3)
		{
			cout << "아이스크림 선디의 크기를 다시 선택해주세요. \n";
			cout << "아이스크림 선디의 크기(1. 소($10),   2. 중($14),   3. 대($17))를 선택하시오 : ";
			cin >> size;
			cout << "\n";
		}

		if (size == 1 || size == 2 || size == 3)
		{
			cout << "토핑의 개수(토핑당 $2)를 선택하시오 : ";
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
		cout << "초콜릿 아이스크림 선디" << "  10" << "      " << 1 << "      " << 10 << endl;

	else if (kind == 2)
		cout << "바닐라 아이스크림 선디" << "  10" << "      " << 1 << "      " << 10 << endl;

	else if (kind == 3)
		cout << "딸기 아이스크림 선디  " << "  10" << "      " << 1 << "      " << 10 << endl;

	if (size == 1)
		cout << "└ 사이즈 (소)" << "            0" << "      " << 1 << "      " << 0 << endl;
		
	else if (size == 2)
		cout << "└ 사이즈 (중)" << "            4" << "      " << 1 << "      " << 4 << endl;

	else if (size == 3)
		cout << "└ 사이즈 (대)" << "            7" << "      " << 1 << "      " << 7 << endl;

	if (topp != 0)
		cout << "└ 토핑                 " << "  2" << "       " << topp << "     " << 2 * topp << endl;
}

