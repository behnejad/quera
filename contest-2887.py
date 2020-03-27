n = int(input())
items = [int(i) for i in input().split()]
mi = min(items)
if mi == 1:
    print(int(sum(items)))
else:
    li = []
    for i in range(2, mi + 1):
        if mi % i == 0:
            li.append(i)
    for d in li:
        dividable = True
        for k in range(len(items)):
            if items[k] % d != 0:
                dividable = False
                break
        if dividable:
            for k in range(len(items)):
                items[k] //= d

    print(int(sum(items)))
        
