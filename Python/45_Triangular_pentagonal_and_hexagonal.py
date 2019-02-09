# Triangular, pentagonal, and hexagonal
# Problem 45 
# Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:

# Triangle	 	Tn=n(n+1)/2	 	1, 3, 6, 10, 15, ...
# Pentagonal	 	Pn=n(3n−1)/2	 	1, 5, 12, 22, 35, ...
# Hexagonal	 	Hn=n(2n−1)	 	1, 6, 15, 28, 45, ...
# It can be verified that T285 = P165 = H143 = 40755.

# Find the next triangle number that is also pentagonal and hexagonal.

# triangle numbers can be ignored as hexagonal numbers are a subset of triangle numbers
# tri = {n*(n+1)/2 for n in range(285, 100000)}
pent = {n*(3*n-1)/2 for n in range(165, 40000)}
hexa = {n*(2*n-1) for n in range(143, 40000)}

print(pent.intersection(hexa))