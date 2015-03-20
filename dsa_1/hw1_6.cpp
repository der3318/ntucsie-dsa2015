#include <iostream>
#include <algorithm>
#define TIMES 0
#define GCD 1

int Times_ReverseSearch(int a, int b)
{
	int times = 0;
	for(int i  = std::min(a, b) ; i > 0 ; i--)
	{
		times++;
		if((a % i + b % i) == 0)	return times;
	}
}

int Times_Filter(int a, int b)
{
	int times = 0;
	for(int i = 2 ; i <= std::min(a, b) ; i++)
	{
		times++;
		if((a % i + b % i) == 0)	return	times +	Times_Filter(a / i, b / i);
	}
	return times;
}

int Times_FilterFaster(int a, int b, int s)
{
	int times = 0;
	for(int i = s ; i <= std::min(a, b) ; i++)
	{
		times++;
		if((a % i + b % i) == 0)	return times + Times_FilterFaster(a / i, b / i, i);
	}
	return times;
}

int Times_Binary(int a, int b)
{
	int times = 0, n = std::min(a, b), m = std::max(a, b);
	while(m * n != 0)
	{
		times++;
		if(n % 2 == 0)	n /= 2;
		if(m % 2 == 0)	m /= 2;
		if(n > m)	std::swap(n, m);
		m -= n;
	}
	return times;
}

int TimesAndGcd_Euclid(int a, int b, int flag)
{
	int output[2] = {0, 0}, n = std::min(a, b), m = std::max(a, b);
	while(m % n != 0)
	{
		output[TIMES]++;
		int tmp = n;
		n = m % n;
		m = tmp;
	}
	output[GCD] = n;
	if(flag == GCD)	return output[GCD];
	else	return output[TIMES];
}

int main(void)
{
	int a = 0, b = 0;
	std::cin >> a;
	while(a != 0)	
	{
		std::cin >> b;
		std::cout << "Case (" << a << ", " << b << "): GCD-By-Reverse-Search = " << TimesAndGcd_Euclid(a, b, GCD) 
			<< ", taking " << Times_ReverseSearch(a, b) << " iterations\n";
		std::cout << "Case (" << a << ", " << b << "): GCD-By-Filter = " << TimesAndGcd_Euclid(a, b, GCD)
			<< ", taking " << Times_Filter(a, b) << " iterations\n";
		std::cout << "Case (" << a << ", " << b << "): GCD-By-Filter-Faster = " << TimesAndGcd_Euclid(a, b, GCD) 
			<< ", taking " << Times_FilterFaster(a, b, 2) << " iterations\n";
		std::cout << "Case (" << a << ", " << b << "): GCD-By-Binary = " << TimesAndGcd_Euclid(a, b, GCD) 
			<< ", taking " << Times_Binary(a, b) << " iterations\n";
		std::cout << "Case (" << a << ", " << b << "): GCD-By-Euclid = " << TimesAndGcd_Euclid(a, b, GCD) 
			<< ", taking " << TimesAndGcd_Euclid(a, b, TIMES) << " iterations\n";
		std::cin >> a;
	}
	return 0;
}
