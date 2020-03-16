a, x, n = input().split()

a = int(a)
x = int(x)
n = int(n)

res = 0;

def fuc(i):
    if i == 0:
        return 1;
    res = 1
    while i > 0:
        res *= i
        i -= 1
    return res

for i in range(n+1):
    res += (x ** i) * (a ** (n - i)) * (fuc(n) // (fuc(i) * fuc(n - i)))

print(int(res))
