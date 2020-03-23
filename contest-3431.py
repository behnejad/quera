i = input().split()
n = int(i[0])
m = int(i[1])
row = [input() for x in range(n)]
item = input()
count = 0
for i in row:
    for j in range(m - len(item) + 1):
        if i[j:j+len(item)] == item:
            count += 1

if m >= len(item):    
    new_row = ["".join(row[y][x] for y in range(n)) for x in range(m)]
    for i in new_row:
        for j in range(m - len(item) + 1):
            if i[j:j+len(item)] == item:
                count += 1

print(count)
