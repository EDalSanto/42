def make_word_histogram(arr):
	new_dict = {};

	for word in arr:
		if (word in new_dict):
			new_dict[word] += 1
		else:
			new_dict[word] = 1
	return new_dict

def enough(d_mag, d_ransom):
	for word, freq in d_ransom.items():
		if word in d_mag.keys():
			if freq > d_mag[word]:
				return 0		
		else:
			return 0
	return 1

def ransom_note(magazine, ransom):
	d_mag = make_word_histogram(magazine)
	d_ransom = make_word_histogram(ransom)
	return enough(d_mag, d_ransom)

m, n = map(int, input().strip().split(' '))
magazine = input().strip().split(' ')
ransom = input().strip().split(' ')
answer = ransom_note(magazine, ransom)
if(answer):
	print("Yes")
else:
	print("No")
