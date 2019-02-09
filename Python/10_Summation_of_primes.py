from math import sqrt

primes = [2, 3]

def is_prime(n):
	for prime_num in primes:
		if n % prime_num == 0:
			return False
		elif sqrt(n) < prime_num:
			return True


while primes[-1] < 2000000:
	next_prime = primes[-1] + 2
	while not is_prime(next_prime):
		next_prime += 2
	primes.append(next_prime)
primes.pop()
print(sum(primes))
