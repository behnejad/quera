n = int(input())
a = list(map(int, input().split()))

b = a[:]
##c = a[:]

i = 0
while i < n - 1:
    if i % 2 == 0:
        if b[i] >= b[i + 1]:
##            del c[i + 1]
            del b[i]
            n -= 1
        else:
            i += 1
            
    else:
        if b[i] <= b[i + 1]:
            del b[i]
##            del c[i + 1]
            n -= 1
        else:
            i += 1
##print(max(len(b),len(c)))
print(len(b))
