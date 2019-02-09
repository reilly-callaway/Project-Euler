# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

# What is the 10 001st prime number?

# This methods allows for much larger primes to be calculated, largest tested is one millionth prime, correctly found in 132.1s

from math import sqrt

N_PRIMES = 10001
primes = [2, 3]

def is_prime(n):
	for prime_num in primes:
		if n % prime_num == 0:
			return False
		elif sqrt(n) < prime_num:
			return True


while len(primes) < N_PRIMES:
	next_prime = primes[-1] + 2
	while not is_prime(next_prime):
		next_prime += 2
	primes.append(next_prime)
print(primes[-1])
