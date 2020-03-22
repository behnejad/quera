jomle = input().lower()
kalame = input().lower()
j1 = []
j2 = ""

for i in jomle:
    if i in "_!. ,()+=*&^%$#@'\";/`~":
        j1.append(j2)
        j2 = ""
    else:
        j2 += i

j1.append(j2)
res = j1.count(kalame) + j1.count(kalame[::-1])
print(res)

    
