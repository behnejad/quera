n = int(input())
l = [int(x) for x in input().split()]
if len(l) == 1:
    print(int(l[0] % (1e9 + 7)))
elif len(l) == 2:
    print(int((l[1] - l[0]) % (1e9 + 7)))
else:
    m = [1]
    for i in range(1, n):
        m.append(m[-1] * (n - i) // i)
        m[-1] = m[-1] % (1e9 + 7)

    l = l[::-1]
    for i in range(len(l)):
        l[i] *= m[i] * (1 if i % 2 == 0 else -1)

    print(int(sum(l) % (1e9 + 7)))
