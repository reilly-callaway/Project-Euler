THOUSAND_FACTORS = (1,2,4,5,8,10,20,25,40,50,100,125,200,250,500)
a = lambda m, n: m**2 - n**2
b = lambda m, n: 2*m*n
c = lambda m, n: m**2 + n**2

for m in range(1, 5):
	for n in range(1, m):
		for const in THOUSAND_FACTORS:
			if const*(a(m, n) + b(m, n) + c(m, n)) == 1000:
				print(const**3*a(m, n)*b(m, n)*c(m, n))