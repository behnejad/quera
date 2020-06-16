i = input().split('*')
n = int(i[0])
m = int(i[1])
ma = [input().split() for i in range(n)]
i, j, e = 0, 0, 0

while True:
    try:
        c = input().lower()
        do = False
        if c == "finish":
            print("Energy %d!" % e)
            break;
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
            if ma[i][j].lower() == 'c':
                print("Frog hunted by crocodile :-/! Energy %d!" % e)
                break
            elif ma[i][j][0].lower() == 'e':
                d = int(ma[i][j][2:-1])
                if d % 5 == 0:
                    e += d
                    if e <= 0:
                        print("Frog died! Energy %d!" % e)
                        break
                    else:
                        print("Energy %d!" % e)
            elif ma[i][j][0].lower() == 'j':
                org = ma[i][j]
                di, dj = ma[i][j][2:-1].split(',')
                di = int(di)
                dj = int(dj)
                if di < 0 or di >= n:
                    print("Impossible place!")
                elif dj < 0 or dj >= m:
                    print("Impossible place!")
                else:
                    print("Jump to (%d,%d)" % (di, dj))
                    i = di
                    j = dj
                    
    except:
        break

