import string

def get_ascii_count(i):
    a = 0
    for w in i:
        if w in string.ascii_letters:
            a += 1

    return a

def replace_not_ascii(i):
    a = ""
    for w in i:
        if w in string.ascii_letters:
            a += w

    return a

def words_check(i):
    dic = {}
    lis = i.split()
    lis2 = []
    for w in lis:
        if get_ascii_count(w) > len(w) // 2:
            lis2.append(replace_not_ascii(w).title())

    for w in lis2:
        if w not in dic:
            dic[w] = 1
        else:
            dic[w] += 1

    return dic
