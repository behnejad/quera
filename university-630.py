from functools import cmp_to_key

words = input().split()[:-1]
##words = "alireza Mohammad Arash anahita sarah Milad john Alireza Maryam".split()

def compare(a, b):
    global words
    aa = a[0].lower()
    bb = b[0].lower()
    if bb > aa:
        return -1
    elif bb < aa:
        return +1
    else:
        if a[0] < b[0]:
            return -1
        elif a[0] > b[0]:
            return +1
        else:
            aa = a[1].lower()
            bb = b[1].lower()
            if bb > aa:
                return -1
            elif bb < aa:
                return +1
            elif len(a) < len(b):
                return +1
            else:
                return words.index(a) < words.index(b)


words = sorted(words, key=cmp_to_key(compare))
print(" ".join(words))
