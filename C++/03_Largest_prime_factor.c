#include <stdio.h>

unsigned long largest_prime_factor(unsigned long n)
{
	for(unsigned long i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return largest_prime_factor(n / i);
		}
	}
	return n;
}

void main(int argc, char *argv[])
{
	unsigned long num = 600851475143;
	printf("%lu\n", largest_prime_factor(num));

}