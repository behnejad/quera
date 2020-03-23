a = input()
b = input()
c = input()

res = ""
for i in range(0, len(a), 5):
    if a[i: i + 5] == "*****":
        res += "T"
    elif a[i: i + 5] == "oo*oo":
        res += "A"
    elif a[i: i + 5] == "**o**":
        res += "M"
    elif a[i: i + 5] == "*ooo*":
        if b[i: i + 5] == "oo*oo":
            res += "X"
        elif b[i: i + 5] == "*o*o*":
            res += "N"
print(res)
