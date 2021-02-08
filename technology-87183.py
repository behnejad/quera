import os


def combet(salib, sajjad, path):
    dic = {}
    dic_name = {}
    for r, ds, fs in os.walk(path):
        for f in fs:
            if f not in dic:
                dic[f] = 1
            else:
                dic[f] += 1

            f = f[0:f.rindex('.')]
            if f not in dic_name:
                dic_name[f] = 1
            else:
                dic_name[f] += 1

    salib_files = 0
    sajjad_files = 0
    for i in dic:
        if i.split('.')[-1] == salib:
            salib_files += dic[i]
        elif i.split('.')[-1] == sajjad:
            sajjad_files += dic[i]

    if sajjad_files > salib_files:
        return "Win! Normally!"
    else:
        for j in dic_name:
            delta = salib_files - sajjad_files + 1;
            all_file_name_count = dic_name[j]
            i = j + "." + sajjad
            if i in dic:
                all_file_name_count -= dic[i]
            i = j + "." + salib
            if i in dic:
                delta -= dic[i]
            if all_file_name_count >= delta:
                return "Win! you can win if you cheat on '%s'!" % j

        return "Lose! you can't win this game!"
            
        
