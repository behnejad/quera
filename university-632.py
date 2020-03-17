jomle = input().lower()
kalame = input().lower()
j1 = []
j2 = ""
for i in jomle:
    if i in "_!. ,()+=*&^%$#@'\"":
        j1.append(j2)
        j2 = ""
    else:
        j2 += i

res = j1.count(kalame)
if res == 0:
    res = j1.count(kalame[::-1])
print(res)

    
