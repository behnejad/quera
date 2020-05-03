import math
input()
a = input()
x1 = 0
c1 = 0
x2 = 0
c2 = 0
index = 0
token1 = []
token2 = []
last = ""
while index < len(a):
    if a[index] == '=':
        if last != "":
            token1.append(last)
            last = ""
        break
    elif a[index] == '+':
        token1.append(last)
        last = ""
    elif a[index] == '-':
        if last != "":
            token1.append(last)
        last = "-"
    else:
        last += a[index]
    index += 1

index += 1
while index < len(a):
    if a[index] == '+':
        token2.append(last)
        last = ""
    elif a[index] == '-':
        if last != "":
            token2.append(last)
        last = "-"
    else:
        last += a[index]
    index += 1

if last != "":
    token2.append(last)

for item in token1:
    if item == 'x':
        x1 += 1
    elif item == '-x':
        x1 -= 1
    elif 'x' in item:
        x1 += int(item.replace('x', ''))
    else:
        c1 += int(item)

for item in token2:
    if item == 'x':
        x2 += 1
    elif item == '-x':
        x2 -= 1
    elif 'x' in item:
        x2 += int(item.replace('x', ''))
    else:
        c2 += int(item)

if x1 == x2:
    print("invalid")
else:
##    print (x1, c1, x2, c2)
    x1 -= x2
    c2 -= c1
    neg = ((x1 < 0) and (c2 > 0)) or ((x1 > 0) and (c2 < 0))
    x1 = abs(x1)
    c2 = abs(c2)
    gcd = math.gcd(x1, c2)
    x1 //= gcd
    c2 //= gcd
    if neg:
        print("-", end="")
    print(c2, x1)
        
    
