while True:
    i = input().replace(" ", "")
    if i == "0000000000000000":
        break

    j = 1
    res = 0
    for k in i:
        t = ord(k) - ord('0')
        if j == 1:
            t *= 2
            if t > 9:
                t -= 9
            j = 0
        else:
            j = 1
        res += t
    if res % 10 == 0:
        print("Yes")
    else:
        print("No")
