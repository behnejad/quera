from bisect import bisect_left, bisect_right

class SortedList():
    def __init__(self, data=None):
        self.data = sorted(data) if data else []

    def add(self, value):
        index = bisect_right(self.data, value)
        self.data.insert(index, value)

    def pop(self):
        if len(self.data) % 2 == 0:
            index = len(self.data) // 2 - 1
        else:
            index = len(self.data) // 2
        return self.data.pop(index)

a = None
n = int(input())
for i in range(n):
    c = input()
    if c == "build()":
        a = SortedList()
    elif c[0] == 'b':
        l = [int(float(x)) if int(float(x)) == float(x) else float(x) for x in c.replace("build", "")[1:-1].split(',')]
        a = SortedList(l)
    elif c == "remove":
        print(a.pop())
    elif c[0] == 'i':
        l = c.replace("insert", "")[1:-1]
        l = int(float(l)) if int(float(l)) == float(l) else float(l)
        a.add(l)
