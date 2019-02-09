#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define N_PRIMES 10001

unsigned long primes[N_PRIMES];

bool is_prime(unsigned long n, int max_index)
{
	for (int i = 0; i < max_index; i++)
	{
		if (n % primes[i] == 0)
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	unsigned long next_prime;
	// Set the first two primes to deal with edge cases of algorithm, such as giving the first prime, and only needing to add one to get the next prime (instead of adding two)
	primes[0] = 2;
	primes[1] = 3;
	for (int i = 2; i < N_PRIMES; i++)
	{
		next_prime = primes[i-1];
		while(!is_prime(next_prime, i))
		{
			next_prime += 2;
		}
		primes[i] = next_prime;
	}
	printf("\n%dth prime: %lu\n\n", N_PRIMES, primes[N_PRIMES-1]);
}