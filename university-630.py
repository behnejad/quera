import functools

##in_str = input().split()[:-1]
in_str = "alireza Mohammad Arash anahita sarah Milad john Alireza Maryam".split()
clone = [x for x in in_str]
def m_sort(a, b):
    global clone
    if a[0].lower() > b[0].lower():
        return 1
    if a[0].lower() == b[0].lower():
        if a[0].islower() and b[0].isupper():
            return 1

    return 0

for i in range(len(in_str)):
    for j in range(0, len(in_str) - i - 1):
        k = m_sort(in_str[j], in_str[j + 1])
        if k == 1:
            in_str[j], in_str[j + 1] = in_str[j + 1], in_str[j]
        elif k == -1:
            in_str[j + 1], in_str[j] = in_str[j], in_str[j + 1]

print(in_str)
