vovles = "aeiouy"
ponc = "!@#$%^&*()-_=+,./;\\[]{}:\"|?><"
a = ""
while True:
    try:    
        a += input()
    except:
        break

for i in ponc:
    a = a.replace(i, " ")
lis = []
a = a.split()

for w in a:
    s = 0
    for ww in w.lower():
        if ww not in vovles:
            s += 1
            if s >= 5:
                break
        else:
            s = 0
    if s >= 5 and w.upper() != w:
        lis.append(w)

print(" ".join(lis))
