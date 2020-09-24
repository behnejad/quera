import math
n = int(input())

print(round(n ** 2 / 48)) if n % 2 == 0 else print(round((n + 3)** 2 / 48))
