class ExceptionProxy(Exception):
    def __init__(self, msg, function):
        self.msg = msg
        self.function = function

def transform_exceptions(func_ls):
    l = []
    for i in func_ls:
        try:
            i()
            l.append(ExceptionProxy("ok!", i))
        except Exception as e:
            l.append(ExceptionProxy(str(e), i))

    return l

def f():
    1/0

def g():
    pass

tr_ls = transform_exceptions([f, g])

for tr in tr_ls:
    print("msg: " + tr.msg + "\nfunction name: " + tr.function.__name__)
