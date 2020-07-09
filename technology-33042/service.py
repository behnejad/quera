from material import TrafficUsageDao


class TrafficUsageService:
    def __init__(self, traffic_usage_dao: TrafficUsageDao):
        self.traffic_usage_dao = traffic_usage_dao
        self.l = self.traffic_usage_dao.load_all()

    def social_media_lovers(self, year: int, month: int):
        res = []
        active = {}
        s = "%02d/%02d/" % (year, month)
        for x in self.l:
            if x.date.startswith(s):
                value = 0 if x.internal else x.usage
                if x.user in active:
                    active[x.user] += value
                else:
                    active[x.user] = value
        if len(active) == 0:
            return res
        usage = []
        for i in active:
            usage.append(active[i])
        if len(usage) < 10:
            return res
        usage = sorted(usage)
        size = len(usage)
        index = (9 * (size - 1)) // 10
        for i in active:
            usage_use = active[i]
            for j in range(index + 1, size):
                if (usage_use == usage[j]):
                    res.append(i)
        return res

    def download_lovers(self, year: int, month: int):
        res = []
        night = {}
        day = {}
        s = "%02d/%02d/" % (year, month)
        for x in self.l:
            if x.date.startswith(s):
                user = x.user
                if user not in res:
                    res.append(user)
                    night[user] = 0
                    day[user] = 0
                if x.nightly:
                    night[user] += x.usage
                else:
                    day[user] += x.usage
        return filter(lambda x: night[x] > day[x], res)
