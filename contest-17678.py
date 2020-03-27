n, d = [int(x) for x in input().split()]
last_day = 0
day_user = set()
all_users = set()
all_logs = []
logs = []

for i in range(n):
    i = input().split()
    day = int(i[2])
    name = i[-2]
    time = i[5]

    if last_day != day:
        logs.append([0, 0, 0])
        day_user = set()
        all_logs.append(set())
        last_day = day

    if name not in day_user:
        logs[-1][0] = logs[-1][0] + 1
        day_user.add(name)

    if name not in all_users:
        logs[-1][1] = logs[-1][1] + 1
        all_users.add(name)

    all_logs[-1].add(name)

last_log = set()
index = len(logs) - 1
for i in all_logs[::-1]:
    for j in i:
        if j not in last_log:
            last_log.add(j)
            logs[index][2] = logs[index][2] + 1
    index -= 1

for i in logs:
    print(" ".join((str(x) for x in i)))
