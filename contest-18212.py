c = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
i = input().split('e')
i[1] = int(i[1])
i[0] = i[0].split('.')
if len(i[0]) == 2:
    i[1] -= len(i[0][1])
    i[0][0] += i[0][1]

watt = 0
for j in i[0][0]:
    watt += c[ord(j) - ord('0')]

watt += i[1] * c[0]
print(watt)
    
