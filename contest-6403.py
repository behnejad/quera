n, k = map(int, input().split())
array = [int(x) for x in input().split()]
count = 0
if k == 1:
    print(0)
else:
    while len(array) != 1:
        index = 0
        mini = 9999999999999
        for i in range(len(array) - 1):
            if array[i] + array[i + 1] < mini:
                mini = array[i] + array[i + 1]
                index = i
        count += mini
        array[index] = mini
        array.pop(index + 1)
    print(count)
