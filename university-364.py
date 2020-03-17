t = int(input())
lengths = [int(input()) for i in range(t)]


for i in range(t):
    tree = []
    for j in range(lengths[i]):
        s = [int(k) for k in input().split(' ')]
        tree.append(s)
    tree.reverse()
   
    for j in range(1,len(tree)):
        for k in range(len(tree[j])):
            tree[j][k] += max(tree[j-1][k], tree[j-1][k+1])

    print(tree[-1][0])
