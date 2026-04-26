A, B, C = map(int, input().split())
count = 0

if (B < C) : 
	count = A/(C-B) + 1
	print(int(count))

else : 
	print(-1)

