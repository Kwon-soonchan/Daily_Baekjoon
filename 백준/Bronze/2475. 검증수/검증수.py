A = list(map(int, input().split()))
B = 0


for i in A :
  B += i**2

print(B%10)