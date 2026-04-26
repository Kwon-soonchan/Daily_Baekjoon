N = int(input())
Price = []

for i in range(N) : 
	Price.append(float(input()))
	
for j in range(N) : 
	print("$%.2f" % (Price[j] * 8/10))