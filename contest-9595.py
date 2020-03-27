n = int(input())
count = 0
for i in range(n):
    a = input().replace(' ', '')
    b = input().replace(' ', '')
    if a != b:
        count += 1
print(count)
