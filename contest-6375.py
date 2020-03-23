i = input().split()
a = int(i[0])
b = int(i[1])
c = int(i[2])

mean = (a + b + c) / 3
if a == b and b == c:
    print(0)
elif a == mean or b == mean or c == mean:
    print(1)
else:
    print(2)
