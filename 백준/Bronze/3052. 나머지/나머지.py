Per = []
 
for i in range(10) : 
  Per.append(int(input()) % 42)
    
s1 = set(Per)
length = len(s1)
      
print(length)