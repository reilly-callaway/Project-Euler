from math import sqrt
triangle_num = lambda n: n*(n+1)//2
triangle_nums = [1]

def count_divisors(n):
	num_divisor_pairs = 0
	curr_div = 1
	while curr_div < sqrt(n):
		if n % curr_div == 0:
			num_divisor_pairs += 1
		curr_div += 1
	return num_divisor_pairs*2
i = 1
triangle = 1
while count_divisors(triangle) < 500:
	triangle = triangle_num(i)
	i += 1
	# triangle_nums.append(triangle_nums[-1]+len(triangle_nums)+1)
	# print(triangle_nums[-1])
print(triangle)