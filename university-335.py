import json

a = json.loads(input().replace("{", "[").replace("}", "]"))

def sum(i: list) -> int:
    if type(i) is int:
        print(i)
        return i
    
    res = 0;
    
    for item in i:
        if type(item) is list:
            res += sum(item)
        else:
            res += item
    print(res)
    return res

sum(a)
