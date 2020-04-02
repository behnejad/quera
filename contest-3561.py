n = int(input())
mat = [[' ' for x in range((n * 4 + 1) + i)] for i in range(5 + 4 * (n - 1))]

for i in range(n):
    for j in range((n * 4 + 1) - (5 + 4 * i), len(mat[4 * (i + 1)])):
        mat[4 * (i + 1)][j] = '*'

    for k in range(4 * (n - i) + 1):
        mat[4 * i + k][4 * (n - i) + k] = '*'

    for k in range(4 * (n - i) + 1):
        mat[4 * i + k][4 * (n + i) - k] = '*'
    
for i in mat:
    print("".join(i))
