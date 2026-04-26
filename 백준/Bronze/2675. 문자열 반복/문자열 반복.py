T = int(input())
P = ""
Input = []
List = []

for i in range(T) : 
	S = list(map(str, input().split()))

	for j in S[1] : 
		Input.append(j)
		
	for k in range(len(S[1])) : 
		P += Input[k] * int(S[0])

	List.append(P)
	Input = []
	P = ""

for l in range(T) : 
	print(List[l])