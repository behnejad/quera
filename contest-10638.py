import math
x1, y1, x2, y2 = [int(x) for x in input().split()]
n = int(input())
if x1 < 0:
    if x2 < 0:
        x1 = -x1
        x2 = -x2
    else:
        if abs(x1) < x2:
            x1 = 0
        else:
            x2 = 0
else:
    if x2 < 0:
        if abs(x2) < x1:
            x2 = 0
        else:
            x1 = 0

dx = abs(x1 - x2)
dy = abs(y1 - y2)
res = n * math.pi * dy * (max(x1, x2) ** 2 - min(x1, x2) ** 2)
res /= 360
print("%.10f" % res)
