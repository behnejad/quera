templates = {}
for _ in range(int(input())):
    a = input().split()
    templates[a[0]] = a[1]

for _ in range(int(input())):
    command = input().split()
    if command[0] not in templates:
        print("[Error] url not found")
    else:
        if len(command) == 1:
            if "/<" in templates[command[0]]:
                print("[Error] missing parameter(s)")
            else:
                print(templates[command[0]])
        else:
            params = command[1:]
            command = command[0]
            if len(params) < templates[command].count("/<"):
                print("[Error] missing parameter(s)")
            else:
                res = templates[command]
                for param in params:
                    param = param.split('=')
                    res = res.replace("<%s>" % param[0], "".join(param[1:]))
                if "/<" in res:
                    print("[Error] missing parameter(s)")
                else:
                    print(res)


