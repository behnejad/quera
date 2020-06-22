import functools

def cmp(a, b):
    if a[0] > b[0]:
        return 1
    elif a[0] < b[0]:
        return -1
    elif a[1] > b[1]:
        return 1
    elif a[1] < b[1]:
        return -1
    else:
        return 0

i = input().split()
n = int(i[0])
m = int(i[1])

l = [input().split() for x in range(n)]
for i in l:
    i[0] = int(i[0])
    i[1] = int(i[1])

l = sorted(l, key=functools.cmp_to_key(cmp))
s = l[0][0]
