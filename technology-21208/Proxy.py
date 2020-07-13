class Proxy:
    def __init__(self, obj):
        self._obj = obj
        self.last_invoke = None
        self.method_call_count = {}

    def last_invoked_method(self):
        if self.last_invoke:
            return self.last_invoke
        else:
            raise Exception("No Method Is Invoked")

    def count_of_calls(self, method_name):
        return self.method_call_count.get(method_name, 0)

    def was_called(self, method_name):
        c = self.count_of_calls(method_name)
        return c > 0

    def inc_calls(self, name):
        if name in self.method_call_count:
            self.method_call_count[name] += 1
        else:
            self.method_call_count[name] = 1

    def __getattr__(self, n):
        try:
            attr = getattr(self._obj, n)
            if callable(attr):
                def wrapper(*a, **b):
                    self.last_invoke = n
                    self.inc_calls(n)
                    return attr(*a, **b)
                return wrapper
            return attr
        except:
            raise Exception("No Such Method")
            
    def __setattr__(self, n, v):
        super().__setattr__(n, v)

class Radio():
    def __init__(self):
        self._channel = None
        self.is_on = False
        self.volume = 0

    @property
    def channel(self):
        return self._channel

    @channel.setter
    def channel(self, value):
        self._channel = value

    def power(self):
        self.is_on = not self.is_on

radio = Radio()
radio_proxy = Proxy(radio)
radio_proxy.channel = 95
print(radio_proxy.power())
print(radio.channel)
