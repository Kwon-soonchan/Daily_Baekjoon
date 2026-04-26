C = int(input())
score = 0
ave = 0
high_student = 0
high_ave_list = []

for i in range(C) : 
	N = list(map(int, input().split()))
	for j in range(N[0]) : 
		score += N[j+1]
		ave = score/N[0]

	for k in range(N[0]) : 
			if (N[k+1] > ave) : 
				high_student += 1

	high_ave_list.append(high_student / N[0] * 100)
	score = 0
	ave = 0
	high_student = 0
	
for l in range(C) : 
	print("%0.3f%%" % high_ave_list[l])
