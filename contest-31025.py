import math

a = input().split()
n = int(a[0])
k = int(a[1])

for i in range(k):
    n /= 2

print(math.floor(n))
    
    
