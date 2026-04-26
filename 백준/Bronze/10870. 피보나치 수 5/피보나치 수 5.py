def fibonacci(n) : 
	a = 0
	b = 1
	c = 0
	
	if n==-1 : 
		return 0
	elif n==0 : 
		return 1

	for i in range(n) : 
		c = a+b
		a = b
		b = c
	return b

N = int(input())
print(fibonacci(N-1))
			