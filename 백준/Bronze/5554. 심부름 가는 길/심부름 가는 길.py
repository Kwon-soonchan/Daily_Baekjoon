import math

time_list = []
sum = 0
for i in range(4) : 
	time_list.append(int(input()))
	sum += time_list[i]

print(math.floor(sum/60))
print(sum%60)