# The prime factors of 13195 are 5, 7, 13 and 29.

# What is the largest prime factor of the number 600851475143 ?

from math import sqrt

def largest_prime_factor(n, divisor=2):
	while (divisor <= sqrt(n)):
		if (n % divisor == 0):
			return largest_prime_factor(n//divisor, divisor)
		else:
			divisor += 1
	return n


num = 600851475143
print(largest_prime_factor(num))