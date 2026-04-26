Min = list(map(int, input().split()))
Man = list(map(int, input().split()))
sum_Min = 0
sum_Man = 0

for i in range(len(Min)) : 
	sum_Min += Min[i]
	sum_Man += Man[i]

if (sum_Min > sum_Man) : 
	print(sum_Min)
elif (sum_Min == sum_Man) : 
	print(sum_Min)
else : 
	print(sum_Man)