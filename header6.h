#pragma once

class IceCreamSundae
{
public:

	void OutputDescription();

	int ComputePrice();

	void Receipt();

private:
	int kind;
	int size;
	int price;
	int topp;
	int sum;
};