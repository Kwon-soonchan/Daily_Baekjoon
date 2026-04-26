S = input()
List = []
result = ""

for i in range(26) : 
	List.append(S.find(chr(i+97)))

for j in range(26) : 
	result += str(List[j]) + " "

print(result)