lee = []
mun = []

for i in range(4) : 
	lee.append(int(input()))

for j in range(2) : 
	mun.append(int(input()))

lee_m = min(lee)
mun_m = min(mun)
lee.remove(lee_m)
mun.remove(mun_m)

print(lee[0] + lee[1] + lee[2] + mun[0])