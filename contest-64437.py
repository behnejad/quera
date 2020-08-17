import math

def justify(words, w):
    if len(words) == 1:
        return words[0] + " " * (w - len(words[0]))
    else:
        space = w - len("".join(words))
        m = len(words)
        base_space = math.floor(space / (m - 1))
        x = [base_space for _ in range(m - 1)]
        ws = space - sum(x)

        if len(x) == 1:
            x[0] += ws
        elif ws != 0:
            for i in range(math.floor(ws / 2)):
                x[i] += 1
            for i in range(math.ceil(ws / 2)):
                x[-(i + 1)] += 1
        
        s = ""
        for i in range(m - 1):
            s += words[i]
            s += ' ' * x[i]
        s += words[-1]
        return s

t = int(input())
for _ in range(t):
    r = input().split()
    n = int(r[0])
    w = int(r[1])
    q = input().split()
    cap = True

    for i in range(len(q)):
        if cap:
            q[i] = q[i].capitalize()
            cap = False
        else:
            q[i] = q[i].lower()

        if q[i][-1] in ".?!":
            cap = True

    lines = [[]]
    for i in q:
        min_size = len(" ".join(lines[-1]))
        if min_size == 0 or ((len(i) + min_size + 1) <= w):
            lines[-1].append(i)
        else:
            lines.append([i])
    
    for line in lines:
        print("|%s|" % justify(line, w))
    
    
