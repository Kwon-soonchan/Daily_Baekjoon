N, X = map(int, input().split())
A = input().split()

for i in A : 
    if X > int(i) : 
        print(int(i),end=" ")