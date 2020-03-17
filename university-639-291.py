n = int(input())

l = [input() for i in range(n)]

first = l[0];
min_len = 51
min_str = 0

for i in l:
    if len(i) < min_len:
        min_len = len(i)
        min_str = i

l.remove(min_str)

res = [min_str[i: j] for i in range(len(min_str)) 
          for j in range(i + 1, len(min_str) + 1)]

max_len = 0
max_str = 0

for sub in res:
    exist = True
    for row in l:
        if sub not in row and sub[::-1] not in row:
            exist = False
            break

    if exist:
        if len(sub) > max_len:
            max_len = len(sub)
            max_str = sub

if max_len > 0:
    if max_str in first:
        print(max_str)
    elif max_str[::-1] in first:
        print(max_str[::-1])

    
