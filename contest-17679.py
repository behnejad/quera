n, q = map(int, input().split())
array = [[] for x in range(n)]
for _ in range(q):
    i = input().split()
    for k in range(len(i)):
        i[k] = int(i[k])
    if i[0] == 1:
        for k in range(n):
            array[k].append(i[1])
    elif i[0] == 2:
        su = 0
        for j in range(i[2]):
            su += array[i[1] - 1].pop(0)

        print(su)
