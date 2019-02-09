# A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

# For example,

# 44 → 32 → 13 → 10 → 1 → 1
# 85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

# Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

# How many starting numbers below ten million will arrive at 89?



squares = {"0":0, "1":1, "2":4, "3":9, "4":16, "5":25, "6":36, "7":49, "8":64, "9":81}
ones = {13, 10, 1}
eighty_nines = {85, 89}

sum_digits_squared = lambda n: sum(squares[digit] for digit in str(n))

def digit_chain(n):
	if n in eighty_nines:
		return 89
	elif n in ones:
		return 1
	else:
		chain_end = digit_chain(sum_digits_squared(n))
		if chain_end == 1:
			ones.add(n)
			return 1
		elif chain_end == 89:
			eighty_nines.add(n)
			return 89


for num in range(1, 10000000):
	# print(num, digit_chain(num))
	digit_chain(num)
print(len(eighty_nines))

