from re import compile as c

a = c("<\s*a[^>]*>(.*?)<\s*/\s*a>")

def process(name):
    global a
    data = open(name).read()
    return len(a.findall(data))
