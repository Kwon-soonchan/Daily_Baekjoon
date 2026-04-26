d = int(input())
car_number = list(map(int, input().split()))
count = 0

for i in range(5) : 
	if car_number[i] == d :
		count += 1

print(count)