n = int(input())
p = []
album = []
while True:
    row = input()
    try:
        n = int(row)
        break
    except:
        pass

    if '- name:' in row:
        p.append({'name': row.split()[-1]})
    elif '  age:' in row:
        p[-1]['age'] = row.split()[-1]
    elif '  city:' in row:
        p[-1]['city'] = row.split()[-1]
    elif '  albums:' in row:
        p[-1]['albums'] = []
    elif '    - ' in row:
        p[-1]['albums'].append(row.split()[-1])

while True:
    row = input()
    try:
        n = int(row)
        break
    except:
        pass

    if '- name:' in row:
        album.append({'name': row.split()[-1]})
    elif '  singer:' in row:
        album[-1]['singer'] = row.split()[-1]
    elif '  genre:' in row:
        album[-1]['genre'] = row.split()[-1]
    elif '  tracks:' in row:
        album[-1]['tracks'] = int(row.split()[-1])

for i in range(n):
    q = input().split()
    if q[0] == '1':
        res = 0
        for i in p:
            if i['name'] == q[1]:
                for l in i['albums']:
                    for j in album:
                        if j['name'] == l and j['singer'] == q[2]:
                            res += j['tracks']
        print(res)
    elif q[0] == '2':
        res = 0
        for i in p:
            if i['name'] == q[1]:
                for l in i['albums']:
                    for j in album:
                        if j['name'] == l and j['genre'] == q[2]:
                            res += j['tracks']
        print(res)
    elif q[0] == '3':
        res = 0
        for i in p:
            if i['age'] == q[1]:
                for l in i['albums']:
                    for j in album:
                        if j['name'] == l and j['singer'] == q[2]:
                            res += j['tracks']
        print(res)
    elif q[0] == '4':
        res = 0
        for i in p:
            if i['age'] == q[1]:
                for l in i['albums']:
                    for j in album:
                        if j['name'] == l and j['genre'] == q[2]:
                            res += j['tracks']
        print(res)
    elif q[0] == '5':
        res = 0
        for i in p:
            if i['city'] == q[1]:
                for l in i['albums']:
                    for j in album:
                        if j['name'] == l and j['singer'] == q[2]:
                            res += j['tracks']
        print(res)
    elif q[0] == '6':
        res = 0
        for i in p:
            if i['city'] == q[1]:
                for l in i['albums']:
                    for j in album:
                        if j['name'] == l and j['genre'] == q[2]:
                            res += j['tracks']
        print(res)
