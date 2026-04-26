T = int(input())
list=[]

for i in range(T) : 
  list.append(input())

for j in list :
  print(j[0] + j[-1])