a = input().split()
a.pop(0)
b = input().split()
b.pop(0)
c = input().split()
c.pop(0)

ranges = []

def add_range(s, e):
    global ranges
    append = True
    for i in ranges:
        if 
        
    if append:
        ranges.append((s, e))
        ranges = sorted(ranges, key=lambda x: x[0])    

for i in range(len(a) // 2):
    s = a[2 * i].split(':')
    e = a[2 * i + 1].split(':')
    s = int(s[0]) * 3600 + int(s[1]) * 60 + int(s[2])
    e = int(e[0]) * 3600 + int(e[1]) * 60 + int(e[2])
    add_range(s, e)

for i in range(len(b) // 2):
    s = b[2 * i].split(':')
    e = b[2 * i + 1].split(':')
    s = int(s[0]) * 3600 + int(s[1]) * 60 + int(s[2])
    e = int(e[0]) * 3600 + int(e[1]) * 60 + int(e[2])
    add_range(s, e)
        
for i in range(len(c) // 2):
    s = c[2 * i].split(':')
    e = c[2 * i + 1].split(':')
    s = int(s[0]) * 3600 + int(s[1]) * 60 + int(s[2])
    e = int(e[0]) * 3600 + int(e[1]) * 60 + int(e[2])
    add_range(s, e)

print(ranges)


