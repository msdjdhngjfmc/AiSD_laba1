#pragma once

class Fraction
{

private:
	struct Node
	{
		int firstNumber;
	};
public:
	Fraction(int top, int bottom) {
		num = top;
		den = bottom;
	}

private:
	int num;
	int den;
};


