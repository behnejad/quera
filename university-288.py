i = input().split('*')
n = int(i[0])
m = int(i[1])
ma = [input().split() for i in range(n)]
i, j, e = 0, 0, 0

def do_map():
    global ma, i, j, e
    if ma[i][j].lower() == 'c':
        print("Frog hunted by crocodile :-/! Energy %d!" % e)
        exit(0)
    elif ma[i][j][0].lower() == 'e':
        d = int(ma[i][j][2:-1])
        e += d
        if e <= 0:
            print("Frog died! Energy %d!" % e)
            exit(0)
        else:
            print("Energy %d!" % e)
    elif ma[i][j][0].lower() == 'j':
        di, dj = ma[i][j][2:-1].split(',')
        di = int(di)
        dj = int(dj)
        if di < 0 or di >= n or dj < 0 or dj >= m:
            print("Impossible place!")
        else:
            print("Jump to (%d,%d)" % (di, dj))
            i = di
            j = dj
            do_map()

while True:
    try:
        c = input().lower()
        do = False
        if c == "finish":
            print("Energy %d!" % e)
            break
        elif c == "right":
            if j == m - 1:
                print("Impossible place!")
            else:
                j += 1
                do = True
        elif c == "left":
            if j == 0:
                print("Impossible place!")
            else:
                j -= 1
                do = True
        elif c == "up":
            if i == 0:
                print("Impossible place!")
            else:
                i -= 1
                do = True
        elif c == "down":
            if i == n - 1:
                print("Impossible place!")
            else:
                i += 1
                do = True
        elif c == "location":
            print("Location (%d,%d)" % (i, j))
        
        if do:
            do_map()
                    
    except:
        break

