#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(NULL));
	int i = 0;
	for(i = 0 ; i < 253 ; i++)	printf("%d", rand()%10);
	printf("\n");
	for(i = 0 ; i < 253 ; i++)	printf("%d", rand()%10);
	return 0;
}

