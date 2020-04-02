n = int(input())
array = [int(x) for x in input().split()]
div = [1]
for i in range(2, n):
    if n % i == 0:
        div.append(i)

found = False
for d in div:
    error = False
    sum1 = sum(array[0 : d])

    for k in range(1, (n // d)):
        sum2 = sum(array[k * d : (k + 1) * d])

        if sum2 != sum1:
            error = True
            break

    if error is False:
        found = True
        print(n // d)
        break

if found is False:
    print(1)
    
