import re

reg = re.compile(r"^[\w_\-][\w_\-\.]*@[\w_\-][\w_\-\.]*\.[\w\-_]+$")

l = [input().lower() for i in range(int(input()))]

a = set()

for i in l:
    if ".." not in i and ".@" not in i:
        if reg.match(i) is not None:
            i = i.split("@")
            i[0] = i[0].replace(".", "")
            if len(i[0]) >= 6 and len(i[0]) <= 30 and len(i[1]) >= 3 and len(i[1]) <= 30:
                a.add(i[0] + "@" + i[1])

print(len(a))
