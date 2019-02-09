# What is the sum of the digits of the number 2^1000

def sum_digits(num):
	str_num = str(num)
	total = 0
	for digit in str_num:
		total += int(digit)
	return total

print(sum_digits(2**1000))