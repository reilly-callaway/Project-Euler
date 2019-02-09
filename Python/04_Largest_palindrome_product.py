# A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

# Find the largest palindrome made from the product of two 3-digit numbers.

def is_palindrome(n):
	s = str(n)
	for i in range(0, len(s)//2):
		if (s[i] != s[-(i+1)]):
			return False
	return True

palindromes = []

# Loops used assume that the largest palindrome will begin be a 6-digit number beginning with 9. I.e. the solution must be greater or equal to 900009
for i in range(999, 949, -1):
	for j in range(999, 900009//i, -1):
		if (is_palindrome(i*j)):
			palindromes.append((i, j, i*j))
for tup in palindromes:
	print(tup[0], "*", tup[1], "=", tup[2])
