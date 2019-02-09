# The Fibonacci sequence is defined by the recurrence relation:

# Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
# The 12th term, F12, is the first term to contain three digits.

# What is the index of the first term in the Fibonacci sequence to contain 1000 digits?


fib = [0, 1]

while(len(str(fib[-1])) < 1000):
	fib.append(fib[-2]+fib[-1])

print(len(fib)-1)