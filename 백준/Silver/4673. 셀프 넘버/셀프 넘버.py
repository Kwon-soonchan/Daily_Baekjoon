A = set(range(1, 10001))
B = set()

for i in range(10000) : 
	for j in str(i) : 
		i += int(j)
	B.add(i)

self_num = sorted(A - B)
for k in self_num : 
	print(k)
		