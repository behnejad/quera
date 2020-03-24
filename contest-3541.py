n = int(input())
sit = set()
count = 0
for i in range(1, n // 2 + 1):
    ab = n - i
    for j in range(ab // 2, ab - i + 1):
        k = ab - j
##        print(i, ab,  j, k)
        if (i, j, k) in sit:
            continue
        
        if i + j > k and i + k > j and j + k > i:
            sit.add((i, j, k))
            sit.add((i, k, j))
            sit.add((j, i, k))
            sit.add((j, k, i))
            sit.add((k, i, j))
            sit.add((k, j, i))
            count += 1

print(count)
