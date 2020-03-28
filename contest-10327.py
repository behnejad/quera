in_put = str(input(''))
in_put = in_put.split(' ')
n = int(in_put[0])
refrence = in_put[1]
s_refrence = set(refrence)

list = []

for i in range(0,n):
    s = str(input(''))
    list.insert(len(list),s)

counter = 0

for items in list:
    l_s = set(items)
    if counter == len(list)-1:
        if l_s == s_refrence:
            print('Yes',end='')
        else:
            print('No', end='')
    else:
        if l_s == s_refrence:
            print('Yes')
        else:
            print('No')
    counter = counter+1
