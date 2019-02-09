# Permuted multiples
# Problem 52 
# It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

# Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

def sort_digits(n):
	digits = []
	while(n > 0):
		digits.append(n%10)
		n //= 10
	digits.sort()
	return digits

num = 100
sorted_num = sort_digits(num)
while not (sort_digits(2*num) == sorted_num and sort_digits(3*num) == sorted_num and sort_digits(4*num) == sorted_num and sort_digits(5*num) == sorted_num and sort_digits(6*num) == sorted_num):
	num += 1
	sorted_num = sort_digits(num)

print(num)
