level = list(map(int, input().split()))
level.sort()
Mm = []
Mm.append(level[0] + level[3])
Mm.append(level[1] + level[2])
print(max(Mm) - min(Mm))