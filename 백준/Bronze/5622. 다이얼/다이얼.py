N = list(input())
time = 0

for i in N : 
	if (i == 'A' or i == 'B' or i == 'C') : 
		time += 2
	elif (i == 'D' or i == 'E' or i == 'F') : 
		time += 3
	elif (i == 'G' or i == 'H' or i == 'I') : 
		time += 4
	elif (i == 'J' or i == 'K' or i == 'L') : 
		time += 5
	elif (i == 'M' or i == 'N' or i == 'O') : 
		time += 6
	elif (i == 'P' or i == 'Q' or i == 'R' or i == 'S') : 
		time += 7
	elif (i == 'T' or i == 'U' or i == 'V') : 
		time += 8
	elif (i == 'W' or i == 'X' or i == 'Y' or i == 'Z') : 
		time += 9

	time += 1

print(time)