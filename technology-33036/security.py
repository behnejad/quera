class Security:
    def __init__(self):
        self.org_name = ""
        
    def secure(self, info):
        if info is None:
            return None
        if len(info) == 0:
            return ""
        a = info.split()
        res = ""
        for i in a:
            if self.is_social_account_info(i):
                res += i.replace(self.org_name, self.encrypt(self.org_name))
            else:
                res += i
            res += " "
        return res[:-1]

    def is_social_account_info(self, param):
        try:
            i = param.index(":")
        except:
            i = -1
        if i == -1 or i == 0:
            return False
        social = param[0 : i]
        if social[0].islower():
            return False
        try:
            j = param.index("/", i + 1)
        except:
            j = -1
        if j == -1:
            return False
        url = param[i + 1 : j]
        if len(url) <= 4 or not url.startswith("www."):
            return False
        for p in range(4, len(url)):
            if url[p].islower():
                continue
            elif url[p] == '.':
                continue
            elif url[p] >= '0' and url[p] <= '9':
                continue
            else:
                return False
        name = param[j + 1:]
        if len(name) == 0:
            return False
        for p in name:
            if p != '_' and not p.isalnum():
                return False
        self.org_name = name
        return True

    def encrypt(self, s):
        res = ""
        if len(s) == 0:
            return res
        base = s[0]
        count = 0
        for i in s:
            if i == base:
                count += 1
            else:
                c = ord(base) - 96
                for j in range(count):
                    res += "%d" % c
                    c += ord(base) - 96
                base = i
                count = 1
        c = ord(base) - 96
        for j in range(count):
            res += "%d" % c
            c += ord(base) - 96

        return res

a = Security()
print(a.secure("FirstName:Ali, LastName:Alavi, BirthDate:1990/02/02 Gender:male Instagram:www.instagram.com/aalavi Degree:Master Twitter:www.twiter.com/alaviii imdb:www.imdb.com/alavi"))
