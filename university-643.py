a = input().split()
for i in range(len(a)):
    a[i] = int(a[i])
print(" ".join(str(x) for x in sorted(a)))
