N = int(input())
L = map(int, input().split())
l = list(L)
v = int(input())
c = 0

for i in range(N) :
    if v == l[i] : 
        c += 1
        
print(c)