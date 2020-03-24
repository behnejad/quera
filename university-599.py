import math
vx, vy, y0, h = map(float, input().split())
b24ac = (vy ** 2) - (4 * -5 * (y0 - h))
if b24ac < 0:
    print("impossible")
elif b24ac == 0:
    t = vy / 10
    t *= vx
    if t >= 0:
        print(("%.2f" % t))
    else:
        print("impossible")
else:
    t = (vy - math.sqrt(b24ac)) / 10
    t *= vx
    if t >= 0:
        print(("%.2f" % t))
        t = (vy + math.sqrt(b24ac)) / 10
        t *= vx
        if t >= 0:
            print(("%.2f" % t))
    else:
        t = (vy + math.sqrt(b24ac)) / 10
        t *= vx
        if t >= 0:
            print(("%.2f" % t))
        else:
            print("impossible")
