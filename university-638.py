def nChoosek(n, k):
    if k * 2 > n:
        k = n - k

    if k == 0:
        return 1

    result = n
    for i in range(2, k + 1):
        result *= (n - i + 1)
        result /= i
    return result

n = int(input())
res = 0
for i in range(1, n + 1):
    t = 1
    for j in range(1, i + 1):
        t *= nChoosek(i, j)
    res += t

print(res)
