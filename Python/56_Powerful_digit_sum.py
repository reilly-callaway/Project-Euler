# Powerful digit sum
# Problem 56 
# A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

# Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?


def sum_digits(n):
   r = 0
   while n:
       r, n = r + n % 10, n // 10
   return r

max_sum = 0

for i in range(70, 100):
	for j in range(70, 100):
		sum = sum_digits(i**j)
		if(sum > max_sum):
			max_sum = sum

print(max_sum)