n = int(input())
for _ in range(n):
    i = int(input())
    find = False
    k = 0
    try:
        k = i - (9 * len(str(i)))
    except:
        k = 1
    
    for j in range(k, i):
        if j + sum((int(x) for x in str(j))) == i:
            print("Yes")
            find = True
            break
    if not find:
        print("No")
            
