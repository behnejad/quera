import copy

n = int(input())
last_server = []
server = []
local = []
original = []

for i in range(n):
    command = input()
    if "git add " in command:
        local.append(command.replace("git add ", ""))
    elif "git clear" == command:
        local.clear()
    elif "git del" == command:
        if len(local):
            local.pop
    elif "git commit & push" == command:
        original = copy.deepcopy(local)
        last_server = copy.deepcopy(server)
        server = copy.deepcopy(local)
    elif "git checkout" == command:
        local = copy.deepcopy(last_server)
        original = copy.deepcopy(last_server)
    elif "git pull" == command:
        print(len(original))
        if len(original):
            for i in original:
                print(i)
