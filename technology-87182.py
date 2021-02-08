import csv

correct_list = {}
game = {}

def ready_up():
    global game
    game = {}
    csvfile = open('esm_famil_data.csv', "rb")
    rows = csvfile.readlines()
    for i in range(len(rows)):
        rows[i] = rows[i].decode("utf-8").replace('\r', '').replace('\n', '').split(',')

    csvfile.close()
    for i in rows[0]:
        correct_list[i] = set()

    for i in range(1, len(rows)):
        for j in range(len(rows[0])):
            if len(rows[i][j]) > 0:
                correct_list[rows[0][j]].add(rows[i][j])


def add_participant(participant, answers):
    game[participant] = answers
    for i in game[participant]:
        if len(game[participant][i]) > 0:
            game[participant][i] = " ".join(game[participant][i].split())

def calculate_all():
    res = {}
    for i in game:
        res[i] = 0

    for col in correct_list:
        not_answer = False
        for player in game:
            if col not in game[player] or game[player][col] == '':
                not_answer = True
                break

        ans = {}
        for player in game:
            if col in game[player] and len(game[player][col]) > 0:
                c = game[player][col]
                if c in ans:
                    ans[c] += 1
                else:
                    ans[c] = 1

        for player in game:
            if game[player][col] in correct_list[col]:
                if ans[game[player][col]] == 1:
                    if not_answer:
                        res[player] += 15
                    else:
                        res[player] += 10
                else:
                    if not_answer:
                        res[player] += 10
                    else:
                        res[player] += 5

    return res
