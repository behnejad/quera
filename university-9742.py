users = []
di = {}
find = 1
try:
    while True:
        line = input().split()
        if line[0] == "Add":
            di[line[4]] = line[1:-1]
            users.append(line[4])
            users = sorted(users)
            print("User", line[4], "added successfully")
        elif line[0] == "Find":
            index = -1
            for i in range(len(users)):
                if users[i].startswith(line[1]):
                    index = i
                    break
            if index == -1:
                print(find, "No user found")
            else:
                for i in range(10):
                    if users[index + i].startswith(line[1]):
                        l = di[users[index + i]]
                        print(find, l[0], l[1], l[2], users[index + i])
                    else:
                        break

            find += 1
except:
    pass
