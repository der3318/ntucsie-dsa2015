#include <iostream>
#include <algorithm>

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

int Times_Euclid(int a, int b)
{
	int times = 0, n = std::min(a, b), m = std::max(a, b);
	while(m % n != 0)
	{
		times++;
		int tmp = n;
		n = m % n;
		m = tmp;
	}
	return times;
}

int main(void)
{
	int a = 11260, b = 0, AverageTimes[5] = {0};
	for(b = 52000 ; b <= 54260 ; b++)
	{
		AverageTimes[0] += Times_ReverseSearch(a, b);
		AverageTimes[1] += Times_Filter(a, b);
		AverageTimes[2] += Times_FilterFaster(a, b, 2);
		AverageTimes[3] += Times_Binary(a, b);
		AverageTimes[4] += Times_Euclid(a, b);
	}
	std::cout << "Average Number of Iterations by GCD-By-Reverse-Search = " << ((double)(AverageTimes[0])) / (double)2261 << std::endl; 
	std::cout << "Average Number of Iterations by GCD-By-Filter = " << ((double)(AverageTimes[1])) / (double)2261 << std::endl;
	std::cout << "Average Number of Iterations by GCD-By-Filter-Faster = " << ((double)(AverageTimes[2])) / (double)2261 << std::endl;
	std::cout << "Average Number of Iterations by GCD-By-Binary = " << ((double)(AverageTimes[3])) / (double)2261 << std::endl;
	std::cout << "Average Number of Iterations by GCD-By-Euclid = " << ((double)(AverageTimes[4])) / (double)2261 << std::endl;
	return 0;
}
