n = int(input())
works = dict()
for i in range(n):
    row = input().split()
    for j in range(n):
        p = int(row[j])
        if p not in works:
            works[p] = [(i, j)]
        else:
            works[p].append((i, j))

list_works = []
for key, value in works.items():
    list_works.append([key, value])

list_works = sorted(list_works, key=lambda x: x[0])
able = set()
work = set()
order = []
for i in list_works:
    for j in i[1]:
        if j[0] not in able and j[1] not in work:
            able.add(j[0])
            work.add(j[1])
            order.append(j)

order = sorted(order, key=lambda x: x[0])
for i in order:
    print(i[1])
