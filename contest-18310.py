s = input()
p = input()

if s in p or p in s or s[::-1] in p or p[::-1] in s:
    print("Yes")
else:
    s1 = s + s
    if s1 in p or p in s1 or s1[::-1] in p or p[::-1] in s1:
        print("Yes")
    else:
        p1 = p + p
        if s in p1 or p1 in s or s[::-1] in p1 or p1[::-1] in s:
            print("Yes")
        else:
            print("No")
