n = int(input())

if n <= 1:
    print("0")
else:
    if (n % 2) == 1:
        res = (n // 2) * ((n // 2) + 1)
        res /= (n + 1)
        print(("%.7f" % res)[:-1])
    else:
        res = (n // 2) * ((n // 2) - 1)
        res += (n // 2)
        res /= (n + 1)
        print(("%.7f" % res)[:-1])
