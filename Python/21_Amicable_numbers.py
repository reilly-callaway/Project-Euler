# Amicable numbers
# Problem 21 
# Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
# If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

# For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

# Evaluate the sum of all the amicable numbers under 10000.

import math

pairs = set()
divisor_sums = {}
divisors = set()

# Evaluate sum of proper divisors from 1 -> 10000
for num in range(1, 10000):
	divisors = {1}
	for i in range(2, round(math.sqrt(num))):
		 if (num % i == 0):
		 	# print(num, i, num/i)
		 	divisors.add(i)
		 	divisors.add(num/i)
	divisor_sums[num] = sum(divisors)

# Find amicable pairs and add to set of pairs
# Could be improved efficiency-wise
for num in range(1, 10000):
	if(divisor_sums[num] < 10000 and num == divisor_sums[divisor_sums[num]] and num != divisor_sums[num]):
		pairs.add(num)

print(sum(pairs))
