# If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

# If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
words = {0:0, 1:len("one"), 2:len("two"), 3:len("three"), 4:len("four"), 5:len("five"), 6:len("six"), 7:len("seven"), 8:len("eight"), 9:len("nine"), 10:len("ten"), 11:len("eleven"), 12:len("twelve"), 13:len("thirteen"), 14:len("fourteen"), 15:len("fifteen"), 16:len("sixteen"), 17:len("seventeen"), 18:len("eighteen"), 19:len("nineteen"), 20:len("twenty"), 30:len("thirty"), 40:len("forty"), 50:len("fifty"), 60:len("sixty"), 70:len("seventy"), 80:len("eighty"), 90:len("ninety")}
LEN_HUNDRED = 7
LEN_AND = 3

def count_letters(num):
	num_letters = 0
	if num >= 100:
		num_letters += words[num//100] + LEN_HUNDRED
		if num%100 != 0:
			num_letters += LEN_AND
	if num%100 in words:
		num_letters += words[num%100]
	else:
		num_letters += words[num%10]
		num_letters += words[((num%100)//10)*10]
	return num_letters

total = 0
for numbers in range(1, 1000):
	total += count_letters(numbers)

total += len("onethousand")

print(total)