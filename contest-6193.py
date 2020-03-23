s = input()
res = ""
for i in s:
    p = s.count(i.lower()) + s.count(i.upper())
    if i >= 'a' and i <= 'z':
        res += chr(ord('a') + ((1 + (ord(i) - ord('a')) * p) % 26))
    else:
        res += chr(ord('A') + ((1 + (ord(i) - ord('A')) * p) % 26))        
print(res)
