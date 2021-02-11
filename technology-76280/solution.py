import json

def process(json_files_paths_list):
    rows = []
    for i in json_files_paths_list:
        f = open(i, "r")
        ff = f.read()
        f.close()
        ff = json.loads(ff)
        row = [0 for i in range(len(ff))]
        for i in ff:
            row[int(i) - 1] = int(ff[i])
        row = sorted(row)

        rows.append(row)

    for i in range(len(rows)):
        for j in range(i):
            rows[i].append(rows[i].pop(0))
            
    with open("ans.csv", "w") as out:
        for i in rows:
            out.write(",".join(map(str, i)))
            out.write("\n")

