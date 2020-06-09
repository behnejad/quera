n = input()
s = input()

ew, em = 0.0, 0.0
w, m = (2 ** 1000) * 1.0, (2 ** 1000) * 1.0

ew += w / 2
em += m / 2

w /= 2
m /= 2

for c in s:
    if c == 'W':
        w += (2 ** 1000)
    else:
        m += (2 ** 1000)
        
    ew += w / 2
    em += m / 2
    w /= 2
    m /= 2

if ew == em:
    print("=")
elif ew > em:
    print("W")
else:
    print("S")
