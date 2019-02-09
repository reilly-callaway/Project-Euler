# Digit factorials
# Problem 34 
# 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

# Find the sum of all numbers which are equal to the sum of the factorial of their digits.

# Note: as 1! = 1 and 2! = 2 are not sums they are not included.
factorials = {0:1, 1:1, 2:2, 3:6, 4:24, 5:120, 6:720, 7:5040, 8:40320, 9:362880}

def fact(x):
	return factorials[int(x)]

total = 0

# All "curious numbers" lie below 100,000
for num in range(10, 100000):
	if sum(map(fact, str(num))) == num:
		total += num
print(total)
