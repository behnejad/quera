import string
import hashlib
import binascii

class Site:
    def __init__(self, url_address):
        self.url = url_address
        self.register_users = []
        self.active_users = []
        pass

    def show_users(self):
        pass

    def register(self, user):
        for u in self.register_users:
            if user.username == u.username:
                raise Exception("user already registered")

        self.register_users.append(user)
        return "register successful"

    def login(self, **kwargs):
        if "password" in kwargs:
            if "username" in kwargs:
                if "email" in kwargs:
                    for u in self.register_users:
                        if u.username == kwargs['username'] and u.email == kwargs['email'] and u.password == u.hash_password(kwargs['password']):
                            self.active_users.append(u)
                            return "login successful"
                else:
                    for u in self.register_users:
                        if u.username == kwargs['username'] and u.password == u.hash_password(kwargs['password']):
                            self.active_users.append(u)
                            return "login successful"
            elif "email" in kwargs:
                for u in self.register_users:
                    if u.email == kwargs['email'] and u.password == u.hash_password(kwargs['password']):
                        self.active_users.append(u)
                        return "login successful"

        return "invalid login"

    def logout(self, user):
        for u in self.active_user:
            if u.username == user.username:
                self.active_user.remove(u)
                return "logout successful"

        return "user is not logged in"

    def __repr__(self):
        return "Site url:%s\nregister_users:%s\nactive_users:%s" % (self.url, self.register_users, self.active_users)

    def __str__(self):
        return self.url


class Account:
    def __init__(self, username, password, user_id, phone, email):
        self.username_validation(username)
        self.password_validation(password)
        self.id_validation(user_id)
        self.phone_validation(phone)
        self.email_validation(email)

    def set_new_password(self, password):
        if not self.password_validation(password):
            raise Exception("invalid password")

        self.password = self.hash_password(password)

    def username_validation(self, username):
        if username.count("_") != 1:
            raise Exception("invalid username")
        self.name, self.family = username.split("_")
        for i in self.name:
            if i not in string.ascii_letters:
                raise Exception("invalid username")
        for i in self.family:
            if i not in string.ascii_letters:
                raise Exception("invalid username")
        self.username = username
            
    def hash_password(self, pwd):
        m = hashlib.sha256()
        m.update(pwd.encode("utf-8"))
        return binascii.hexlify(m.digest()).decode('ascii')

    def password_validation(self, pwd):
        if len(pwd) < 8:
            raise Exception("invalid password")

        lower = False
        upper = False
        digit = False
        
        for w in pwd:
            if w in string.ascii_uppercase:
                upper = True
            elif w in string.ascii_lowercase:
                lower = True
            elif w in string.digits:
                digit = True
        if lower and upper and digit:
            self.password = self.hash_password(pwd)
        else:
            raise Exception("invalid password")

    def id_validation(self, ids):
        if len(ids) != 10:
            raise Exception("invalid code melli")

        s = 0
        for i in range(9):
            s += (10 - i) * (ord(ids[i]) - ord('0'))
        rem = s % 11
        if rem < 2:
            if (ord(ids[9]) - ord('0')) == rem:
                self.user_id = ids
            else:
                raise Exception("invalid code melli")
        else:
            if (ord(ids[9]) - ord('0')) == (11 - rem):
                self.user_id = ids
            else:
                raise Exception("invalid code melli")
        

    def phone_validation(self, phone):
        if len(phone) == 13:
            if not phone.startswith("+989"):
                raise Exception("invalid phone number")
            else:
                self.phone = phone.replace("+989", "09")
        elif len(phone) == 11:
            if not phone.startswith("09"):
                raise Exception("invalid phone number")
            else:
                self.phone = phone
        else:
            raise Exception("invalid phone number")

    def email_validation(self, email):
        first, second = email.split("@")
        for i in first:
            if i not in (".-_" + string.ascii_letters + string.digits):
                raise Exception("invalid email")

        i = second.rindex(".")
        sec = second[:i]
        dot = second[i+1:]
        for i in sec:
            if i not in (".-_" + string.ascii_letters + string.digits):
                raise Exception("invalid email")
        for i in dot:
            if i not in string.ascii_letters:
                raise Exception("invalid email")
        if len(dot) > 5 or len(dot) < 2:
            raise Exception("invalid email")

        self.email = email

    def __repr__(self):
        return self.username

    def __str__(self):
        return self.username

def show_welcome(func):
    def inner(username):
        s = username.replace("_", " ").title()
        if len(s) > 15:
            s = s[:15] + "..."
        return func(s)
        
    return inner

def verify_change_password(func):
    def inner(user, old_pass, new_pass):
        if user.password == user.hash_password(old_pass):
            user.set_new_password(new_pass)
            return func(user, old_pass, new_pass)
        
    return inner

@show_welcome
def welcome(user):
    return ("welcome to our site %s" % user)

@verify_change_password
def change_password(user, old_pass, new_pass):
    return ("your password is changed successfully.")

