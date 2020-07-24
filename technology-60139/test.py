from pyranj import PyRanj as pyranj

@pyranj
def f1():
    raise Exception('x1')

f1()

pyrannnnnnnj = pyranj()()(prefix='Hey')()

@pyrannnnnnnj(prefix='You')
def f2():
    raise Exception('x2')

f2()

with pyranj(prefix='Yes')()()()()():
    raise Exception('x3')


class A(pyranj):
    def run(self, num):
        raise Exception('x' * num)

A().run(5)


class B(pyranj()()(prefix='Hey there is an error')):
    def run(self):
        raise Exception('run ...')

B().run()
