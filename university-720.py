m = int(input())

id_col = {}
col_ids = {}
for i in range(1, 30001):
    id_col[i] = i
    col_ids[i] = [i]
    
for i in range(m):
    c = input().split()
    if c[0] == "Height":
        a = int(c[1])
        print(col_ids[id_col[a]].index(a) + 1)
    elif c[0] == "Merge":
        a = int(c[1])
        b = int(c[2])
        cola = id_col[a]
        colb = id_col[b]
        col_ids[colb].extend(col_ids[cola])
        for x in col_ids[cola]:
            id_col[x] = colb
