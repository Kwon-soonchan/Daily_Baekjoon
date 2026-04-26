N = int(input())
a = 1
d = 6
count = 1

if N == 1:
    print(1)
	
else:
    while True:
        a = a + d
        count += 1
        if N <= a:
            print(count)
            break
        d += 6