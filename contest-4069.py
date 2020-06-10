n = input()
s = input()

ew, em = 0, 0
w, m = (2 ** 100005), (2 ** 100005)

ew += w // 2
em += m // 2

w //= 2
m //= 2

for c in s:
    if c == 'W':
        w += (2 ** 100005)
    else:
        m += (2 ** 100005)
    
    ew += w // 2
    em += m // 2
    w //= 2
    m //= 2

if ew == em:
    print("=")
elif ew > em:
    print("W")
else:
    print("S")
