users_ip = {}
users_name = {}
users = {}
index = 0
for _ in range(int(input())):
    line = input().split()
    line[1] = line[1].split(':')
    if line[0] == '1':
        if '_' in line[1][1] or '*' in line[1][1] or '#' in line[1][1] or '$' in line[1][1]:
            print("invalid username")
        else:
            users_ip[line[1][0]] = index
            users_name[line[1][1]] = index
            users[index] = 0
            index += 1
    elif line[0] == '2':
        users[users_ip[line[1][0]]] -= int(line[1][2])
        users[users_name[line[1][1]]] += int(line[1][2])
    elif line[0] == '3':
        print(users[users_ip[line[1][0]]])
