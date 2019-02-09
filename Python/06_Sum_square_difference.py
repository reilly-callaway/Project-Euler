sum_square_diff = lambda r: abs(sum([x**2 for x in r])-sum(r)**2)
print(sum_square_diff(range(0, 101)))