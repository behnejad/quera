

def guess_generator_iterator(guess_generator, min_value, max_value, assumed_number):
    last = assumed_number
    gen = guess_generator(min_value, max_value)
    qm = 0
    res = []
    send = None

    start = False
    try:
        value = next(gen)
        start = True
    except:
        pass

    while start:
        if send == 'E':
            qm += 1
            res.append('!')
            if qm == 3:
                res.append('!!!')
                break

        elif send == 'G' and value >= last:
            qm += 1
            res.append('!')
            if qm == 3:
                res.append('!!!')
                break

        elif send == 'L' and value <= last:
            qm += 1
            res.append('!')
            if qm == 3:
                res.append('!!!')
                break

        elif value < min_value or value > max_value:
            qm += 1
            res.append('!')
            if qm == 3:
                res.append('!!!')
                break

        if value == assumed_number:
            send = 'E'
        elif value < assumed_number:
            send = 'L'
        else:
            send = 'G'

        last = value
        res.append(value)

        try:
            value = gen.send(send)
        except:
            break

    return res
