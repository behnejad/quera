count_inputs = int(input())
for _____ in range(count_inputs):
    ____ = input().replace(" := ", " = ")
    if ____.startswith("print"):
        ____ = ____.replace("print", "print(") + ")"
    exec(____)
    
