def calculator(n, m, li):
    new_list = [sum(li[x * m : m * (x + 1)]) for x in range(n // m)]
    if n % m != 0:
        new_list.append(sum(li[-(n % m):]))
    r = 0
    for i in range(len(new_list)):
        if i % 2 == 0:
            r += new_list[i]
        else:
            r -= new_list[i]
    return r
