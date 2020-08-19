res = 0

n = int(input())

dic = {}
for i in input().split():
    i = int(i)
    if i not in dic:
        dic[i] = 1
    else:
        dic[i] += 1
l = []
for i in dic:
    l.append((i, dic[i]))

l = sorted(l, key=lambda x: x[0], reverse=True)

for i in range(len(l)):
    for j in range(i, len(l)):
        res += l[i][1] * l[j][1] * (l[i][0] // l[j][0])

print(res)
