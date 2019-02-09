num = 1

NUM_DIGITS = 10**10

for i in range(0, 7830457):
	if num > NUM_DIGITS:
		num = int(str(num)[-10:])
	num *= 2

num = 28433*num + 1

print(str(num)[-10:])