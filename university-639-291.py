n = int(input())

l = [input() for i in range(n)]

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
    for row in l:
        if sub in row or sub[::-1] in row:
            if len(sub) > max_len:
                max_len = len(sub)
                max_str = sub
        else:
            break;

if max_len > 0:
    print(max_str)

    
