#include <stdio.h>

int main(void)
{
	for(int i = 1 ; i < 256 ; i++)
		printf("%d", i % 10);
	printf(" ");
	for(int i = 249 ; i >= 1 ; i--)
		printf("%d", i % 10);
	return 0;
}
