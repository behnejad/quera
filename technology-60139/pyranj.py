class PyRanj():
    def __init__(self, *f, prefix=None):
        if prefix:
            self.prefix = prefix
        else:
            self.prefix = "[EXCEPTION]"

        if f:
            self.func = f[0]
        else:
            self.func = None

    def __call__(self, f=None, prefix=None):
        if prefix:
            self.prefix = prefix
        if f:
            self.func = f

        if f is None and prefix is None and self.func is not None:
            try:
                self.func()
            except Exception as e:
                print(self.prefix + " :: " + str(e))
        return self

    def __enter__(self): 
        return self
      
    def __exit__(self, exc_type, exc_value, exc_traceback):
        if exc_type:
            print(self.prefix + " :: " + str(exc_value))
        return True

##    def __getattribute__(self, name):
##        attr = object.__getattribute__(self, name)
##        if hasattr(attr, '__call__') and str(name) == "run":
##            def new_run(*a, **k):
##                try:
##                   attr(*a, **k)
##                except Exception as e:
##                    print(self.prefix + " :: " + str(e))
##            return new_run
##        if not hasattr(attr, '__call__'):
##            pass
##        return attr
