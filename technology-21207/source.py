import os

recover = []


class FileManager():
    def create_dir(self, name, address):
        if not os.path.isdir(address + "/" + name):
            os.mkdir(address + "/" + name)

    def create_file(self, name, address):
        if not os.path.isfile(address + "/" + name):
            with open(address + "/" + name, "w") as f:
                f.close()

    def delete(self, name, address):
        if os.path.isfile(address + "/" + name):
            a = open(address + "/" + name, "r+b")
            b = a.read()
            a.close()
            recover.append([name, address + "/" + name, b])
            os.remove(address + "/" + name)

    def find(self, name, address):
        res = []
        for r, d, f in os.walk(address):
            for fi in f:
                if fi == name:
                    res.append((r + "/" + fi).replace("\\", "/"))
        return res
    
    def restore(self, name):
        if len(recover) == 0:
            return
        for i in range(len(recover) - 1, -1, -1):
            if recover[i][0] == name:
                if not os.path.isfile(recover[i][1]):
                    with open(recover[i][1], "w+b") as f:
                        if len(recover[i][2]) > 0:
                            f.write(recover[i][2])
                        f.close()
                    recover.pop(i)
                    return

fm = FileManager()
fm.create_dir('test', '.')
fm.create_dir('test1', 'test')
fm.create_dir('test2', 'test/test1/')

fm.create_file('test.txt', 'test')
fm.create_file('test.txt', 'test/test1')
fm.create_file('test.txt', 'test/test1/test2')

fm.restore('sss.txt')

