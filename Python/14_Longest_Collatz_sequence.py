# The following iterative sequence is defined for the set of positive integers:

# n → n/2 (n is even)
# n → 3n + 1 (n is odd)

# Using the rule above and starting with 13, we generate the following sequence:

# 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
# It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

# Which starting number, under one million, produces the longest chain?

# NOTE: Once the chain starts the terms are allowed to go above one million.

chain_lengths = {1:1}

def collatz_counter(num):
	if (not num in chain_lengths):
		if num % 2 == 0:
			chain_lengths[num] = collatz_counter(num//2)+1
		else:
			chain_lengths[num] = collatz_counter(3*num+1)+1
	return chain_lengths[num]

max_start = 1
for i in range(1, 1000000):
	length = collatz_counter(i)
	if length > chain_lengths[max_start]:
		max_start = i

print(max_start)