#include <stdio.h>
#include <string.h>

const int TARGET = 999;

int sum_multiple(int multiple)
{
	int sum = 0;
	for(int i = 0; i <= TARGET; i+=multiple)
	{
		sum += i;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int total = sum_multiple(3) + sum_multiple(5) - sum_multiple(15);
	printf("Total sum of multiples of 3 or 5 below 1000 is: %d\n", total);
}

// 233168
