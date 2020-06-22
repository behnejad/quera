def fruits(fruit_list):
    res = {}
    for f in fruit_list:
        if f['shape'] == "sphere" and f['mass'] >= 300 and f['mass'] <= 600 and f['volume'] >= 100 and f['volume'] <= 500:
            if f['name'] in res:
               res[f['name']] += 1
            else:
                res[f['name']]= 1
    return res
