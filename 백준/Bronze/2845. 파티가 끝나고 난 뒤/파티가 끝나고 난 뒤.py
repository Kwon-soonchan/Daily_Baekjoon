L, P = map(int, input().split())
Count = list(map(int, input().split()))

for i in range(5) : 
	print(Count[i] - (L*P), end=" ")