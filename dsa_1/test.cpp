#include <iostream>
#include "biginteger_for_binary.h"

BigInteger re(BigInteger n)
{
	if( (n - 1).iszero() )	return 1;
	return	n * re(n - 1);
}

int main()
{
	std::cout << re(50);
	return 0;
}
