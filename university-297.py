x = int(input())
n = int(input())

fac = 1

if n == 0:
    print("1.000")
else:
    res = 1
    so = x
    for i in range(1, n):
        res += so / fac
        so *= x
        fac *= i + 1
    print(("%.4f" % res)[:-1])
