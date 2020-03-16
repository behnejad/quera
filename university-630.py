import functools

in_str = input().split()
in_str.pop()

def m_sort(a, b):
    global in_str
    
    if a[0] < b[0]:
        return 1
    if a[0] == b[0]:
        if len(a) < len(b):
            return 1
        if len(a) >= 2:
            if in_str.index(a) < in_str.index(b):
                return 1
            else:
                return -1
    return 0

        
sorted(in_str, key = functools.cmp_to_key(m_sort))
print(in_str)
