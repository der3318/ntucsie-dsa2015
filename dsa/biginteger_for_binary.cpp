#include <iostream>
#include <string>
#include "biginteger_for_binary.h"
#define MAX 100
#define BASE 1000

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
	int pow[3] = {1, 10, 100};
	int count = 0;
	for(int i = 0 ; i < MAX ; i++)	data[i] = 0;
	for(int i = input.length() - 1 ; i >= 0 ; i--)
	{
		data[count / 3] += ((input[i] - '0') * pow[count % 3]);
		count++;
	} 	
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

const BigInteger BigInteger::operator-(const BigInteger& o) const
{
	BigInteger output;
	int tmp = 0;
	for(int i = 0 ; i < MAX ; i++)
	{
		output.data[i] = data[i] - o.data[i] - tmp;
		tmp = (output.data[i] < 0) ? 1 : 0;
		if(output.data[i] < 0)	output.data[i] += BASE;
	}
	return output;
}

const BigInteger BigInteger::operator*(const BigInteger& o) const
{
	BigInteger output;
	for(int i = 0 ; i < MAX ; i++)
	{
		for(int j = 0 ; j <= i ; j++)	output.data[i] += data[j] * o.data[i - j];
		output.data[i + 1] += (output.data[i] / BASE);
		output.data[i] %= BASE;
	}
	return output;
}

BigInteger& BigInteger::operator*=(int o)
{
	//have problem
	int tmp = 0;
	for(int i = 0 ; i < MAX ; i++)
	{
		data[i] = data[i] * o + tmp;
		tmp = (data[i] / BASE);
		data[i] %= BASE;
	}
	return *this;
}

BigInteger& BigInteger::operator/=(int o)
{
	int tmp = 0;
	for(int i = MAX - 1 ; i >= 0 ; i--)
	{
		tmp *= BASE;
		tmp += data[i];
		data[i] = tmp / o;
		tmp -= (data[i] * o);
	}
	return *this;
}

BigInteger& BigInteger::operator=(const BigInteger& o)
{
	for(int i = 0 ; i < MAX ; i++)	data[i] = o.data[i];
	return *this;
}

bool BigInteger::iseven()
{
	return (data[0] % 2 == 0);
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
	for(int i = start - 1 ; i >= 0 ; i--)	s << o.data[i] / 100 << (o.data[i] % 100) / 10 << o.data[i] % 10;
	return s;	
}
