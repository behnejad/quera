import functions
from threading import Thread
def solve():

    t1 = Thread(name=1, target=functions.f[0])
    t2 = Thread(name=2, target=functions.f[1])
    t3 = Thread(name=3, target=functions.f[2])
    t4 = Thread(name=4, target=functions.f[3])

    t1.start()
    t2.start()
    t3.start()
    t4.start()

    t1.join()
    t2.join()
    t3.join()
    t4.join()


    g1 = Thread(name=1, target=functions.g[0])
    g2 = Thread(name=2, target=functions.g[1])

    g1.start()
    g2.start()

    g1.join()
    g2.join()

    h = Thread(name=1, target=functions.h[0])
    h.start()
    h.join()

    pass