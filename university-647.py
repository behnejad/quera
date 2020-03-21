import math

n = int(input())
m = int(input())

res = 0

for i in range(-10, m + 1):
    for j in range(1, n + 1):
        res += ((i + j) ** 3) / (j ** 2)

print(int(res))
