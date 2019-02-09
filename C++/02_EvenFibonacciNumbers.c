#include <stdio.h>

int fib(int n)
{
	if(n == 1){
		return 1;
	}
	else if (n == 2){
		return 2;
	}
	else
	{
		return fib(n-2) + fib(n-1);
	}
}

void main(int argc, char *argv[])
{
	unsigned long long sum = 0;
	unsigned long x;
	for(int i = 1; fib(i) < 4000000; i++)
	{
		x = fib(i);
		if(x % 2 == 0)
		{
			sum += x;
		}
	}
	printf("%llu\n", sum);
}