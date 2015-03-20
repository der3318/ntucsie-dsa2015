#include <iostream>
#include <string>
#include "biginteger_for_euclid.h"
#define MAX 300
#define BASE 10

BigInteger::BigInteger()
{
	data = new int[MAX];
	for(int i = 0 ; i < MAX ; i++)	data[i] = 0;
}

BigInteger::BigInteger(const int& input)
{
	data = new int[MAX];
	int tmp = input;
	for(int i = 0 ; i < MAX ; i++)
	{
		data[i] = tmp % BASE;
		tmp /= BASE;
	}
}

BigInteger::BigInteger(const std::string& input)
{
	data = new int[MAX];
	int count = 0;
	for(int i = 0 ; i < MAX ; i++)	data[i] = 0;
	for(int i = input.length() - 1 ; i >= 0 ; i--)	data[count++] = input[i] - '0';
}

BigInteger::BigInteger(const BigInteger& input)
{
	data = new int[MAX];
	for(int i = 0 ; i < MAX ; i++)	data[i] = input.data[i];
}

BigInteger::~BigInteger()
{
	delete []data;
}

bool BigInteger::operator<(const BigInteger& o) const
{
	for(int i = MAX - 1 ; i >= 0 ; i--)
	{
		if(o.data[i] - data[i] > 0)	return true;
		else if(data[i] - o.data[i] > 0)	return false;
	}
	return false;
}

BigInteger BigInteger::operator%(const BigInteger& o) const
{
	BigInteger output((*this));
	int shift = 0, output_digit = 0 , o_digit = 0;
	for(output_digit = MAX  - 1; output_digit >= 0 ; output_digit--)	if(output.data[output_digit] != 0)	break;
	for(o_digit = MAX - 1 ; o_digit >= 0 ; o_digit--)	if(o.data[o_digit] != 0)	break;
	shift = output_digit - o_digit;
	while(shift >= 0)
	{
		BigInteger o_shift;
		for(int i = shift ; i < MAX ; i++)	o_shift.data[i] = o.data[i - shift];
		while(!(output < o_shift))	
		{
			int tmp = 0;
			for(int i = shift ; i <= output_digit ; i++)
			{
				output.data[i] = output.data[i] - o_shift.data[i] - tmp;
				tmp = (output.data[i] < 0) ? 1 : 0;
				if(output.data[i] < 0)	output.data[i] += BASE;
			}
		}
		shift--;
	}
	return output;
}

BigInteger& BigInteger::operator=(const BigInteger& o)
{
	for(int i = 0 ; i < MAX ; i++)	data[i] = o.data[i];
	return *this;
}

bool BigInteger::iszero()
{
	for(int i = 0 ; i < MAX ; i++)	if(data[i] != 0)	return false;
	return true;		
}

std::ostream& operator<<(std::ostream& s, const BigInteger& o)
{
	int start = 0;
	for(start = MAX - 1 ; start >= 0 ; start--)	if(o.data[start] != 0)	break;
	s << o.data[start];
	for(int i = start - 1 ; i >= 0 ; i--)	s << o.data[i];
	return s;	
}
