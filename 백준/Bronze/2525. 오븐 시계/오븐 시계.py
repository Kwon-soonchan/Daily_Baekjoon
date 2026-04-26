H, M = map(int, input().split())
T = int(input())

if (M+T) < 60 : 
    print(H, M+T)
    
elif (M+T) >= 60 : 
    if (H+((M+T)//60)) < 24 : 
        print(H+((M+T)//60), (M+T)%60)
    elif (H+((M+T)//60)) >= 24 : 
        print((H+((M+T)//60)-24), (M+T)%60)