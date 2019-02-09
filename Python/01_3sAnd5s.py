# If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
# The sum of these multiples is 23.
# Find the sum of all the multiples of 3 or 5 below 1000.

sum = 0
max = 1000
for threes in range(0, max, 3):
	sum += threes
for fives in range(0, max, 5):
	if fives%3 != 0:
		sum+=fives
print(sum)