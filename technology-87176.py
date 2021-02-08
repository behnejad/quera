def game(number):
    a = number // 10
    b = number % 10
    return (a - b) if a >= b else (b - a)