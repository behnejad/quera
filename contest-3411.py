import math
x = int(input())
print(str(math.factorial(x)).rstrip('0')[-1])

##last = 1
##for i in range(1, x + 1):
##    last *= i
##    while last % 10 == 0:
##        last //= 10
##    if last > 99:
##        last = last % 100
##    if int(str(math.factorial(i)).rstrip('0')[-1]) != last % 10:
##        print(i, str(math.factorial(i)).rstrip('0')[-2:], last)
