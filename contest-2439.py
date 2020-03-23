i = input().split()
day = int(i[0])
d = i[1]

res = 1
while day > 1:
    res *= day
    day -= 1

res = str(res)
print(res.count(d))
