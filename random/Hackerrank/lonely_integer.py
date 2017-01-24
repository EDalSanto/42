def lonely_integer(a):
	result = 0
	for num in a:
		result ^= num
	return result

n = int(raw_input().strip())
a = [int(a_temp) for a_temp in raw_input().strip().split(' ')]
print(lonely_integer(a))
