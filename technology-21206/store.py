from models import Product, User


class Store:
    def __init__(self):
        self.products = dict()
        self.users = list()

    def add_product(self, product, amount=1):
        self.products[product] = self.products.get(product, 0) + amount

    def remove_product(self, product, amount=1):
        if product in self.products:
            if self.products[product] < amount:
                raise Exception("Not Enough Products")
            elif self.products[product] == amount:
                del self.products[product]
            else:
                self.products[product] -= amount

    def add_user(self, username):
        for i in self.users:
            if i.username == username:
                return None
        self.users.append(User(username))
        return username

    def get_total_asset(self):
        res = 0
        for item, value in self.products.items():
            res += item.price * value
        return res

    def get_total_profit(self):
        res = 0
        for u in self.users:
            for item in u.bought_products:
                res += item.price

        return res

    def get_comments_by_user(self, user):
        res = []
        for p in self.products:
            for c in p.comments:
                if c.user == user:
                    res.append(c.text)
        return res

    def get_inflation_affected_product_names(self):
        res = []
        dic = {}
        for p in self.products:
            if p.name in dic:
                if dic[p.name] != p.price and p.name not in res:
                    res.append(p.name)
            else:
                dic[p.name] = p.price
        return res

    def clean_old_comments(self, date):
        for p in self.products:
            p.comments[:] = [c for c in p.comments if not c.date_added < date]                   

    def get_comments_by_bought_users(self, product):
        res = []
        for p in self.products:
            if p.id == product.id:
                for c in p.comments:
                    if p in c.user.bought_products:
                        res.append(c.text)
                break
        return res
