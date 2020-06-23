def coloring(cube):
    for i in range(len(cube)):
        for j in range(len(cube[i])):
            for k in range(len(cube[i][j])):
                cube[i][j][k] = 0

    for j in range(len(cube[0])):
        for k in range(len(cube[0][j])):
            cube[0][j][k] = 1
            cube[-1][j][k] = 1

    for j in range(len(cube)):
        for k in range(len(cube[j])):
            cube[j][k][0] = 1
            cube[j][k][-1] = 1

    for j in range(len(cube)):
        for k in range(len(cube[j][0])):
            cube[j][0][k] = 1
            cube[j][-1][k] = 1

##matrix = [
##            [
##                [5, 5, 5, 5],
##                [5, 5, 5, 5],
##                [5, 5, 5, 5],
##            ],
##            [
##                [5, 5, 5, 5],
##                [5, 5, 5, 5],
##                [5, 5, 5, 5],
##            ],
##            [
##                [5, 5, 5, 5],
##                [5, 5, 5, 5],
##                [5, 5, 5, 5],
##            ]
##        ]
##
##coloring(matrix)
##
##for i in range(len(matrix)):
##    print("{}th layer:".format(i+1))
##    for j in matrix[i]:
##        for k in j:
##            print(k, end=' ')
##        print()
