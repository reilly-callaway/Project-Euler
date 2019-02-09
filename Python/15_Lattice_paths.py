# Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

# How many such routes are there through a 20×20 grid?

import math

GRID_SIZE = 20

# Idea to use a series of twenty nested loops, turns out it took too long, who knew.
# def lattice_paths(depth=0, start=0, count=0):
# 	if depth < GRID_SIZE:
# 		for i in range(start, GRID_SIZE+1):
# 			count += lattice_paths(depth+1, i)
# 	else:
# 		count += 1
# 	return count

# Clean combinatorics solution
lattice_paths = lambda n: math.factorial(2*n)//(math.factorial(n)**2)

print(lattice_paths(GRID_SIZE))

# Also here's the one liner:
# print(math.factorial(40)//(math.factorial(20)**2))