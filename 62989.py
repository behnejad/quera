import sqlite3
db = sqlite3.connect(":memory:")
types = {"int": "INTEGER  NOT NULL default 0", "string": "TEXT NOT NULL default `null`"}
users = {}
tables = {}
insert_id = 0

while True:
    q = input().split()
    if q[0] == "done":
        break;

    elif q[0] == "create":
        if q[1] == "user":
            users[q[2]] = (q[3] == "editor")
        elif q[1] == "table":
            if users[q[-1]]:
                db.execute("create table `%s` (h_id integer)" % q[2])
                tables[q[2]] = ["h_id"]
            else:
                print("access denied")

    elif q[0] == "delete":
        if users[q[-1]]:
            db.execute("drop table `%s`" % q[2])
        else:
            print("access denied")

    elif q[0] == "add":
        if users[q[-1]] == False:
            print("access denied")
        else:
            if q[1] == "column":
                db.execute("alter table `%s` add `%s` %s" % (q[2], q[3], types[q[4]]))
                tables[q[2]].append(q[3])
            elif q[1] == "row":
                db.execute("insert into `%s`(h_id) values(%d)" % (q[2], insert_id))
                insert_id += 1

    elif q[0] == "remove":
        if users[q[-1]] == False:
            print("access denied")
        else:
            if q[1] == "column":
                c = db.execute("select * from sqlite_master where tbl_name = '%s'" % q[2])
                for i in c:
                    c = i[-1]
                    break
                c = c.replace("`%s`" % q[2], "`%s_old`" % q[2]).split(',')
                for i in range(len(c)):
                    if q[3] in c[i]:
                        c.pop(i)
                        break
                c = ",".join(c)
                if c[-1] != ')':
                    c += ')'

                db.execute(c)
                tables[q[2]].remove(q[3])
                cl = ", ".join(tables[q[2]])
                quer = "insert into `%s_old` (%s) select %s from `%s`" % (q[2], cl, cl, q[2])
                db.execute(quer)
                db.execute("drop table `%s`" % q[2])
                db.execute("alter table `%s_old` RENAME TO `%s`" % (q[2], q[2]))
            elif q[1] == "row":
                db.execute("delete from `%s` where h_id in (select h_id from `%s` limit 1 offset %d)" % (q[2], q[2], int(q[3]) - 1))
            
    elif q[0] == "change":
        if users[q[-1]] == False:
            print("access denied")
        else:
            db.execute("update `%s` set `%s` = '%s' where h_id in (select h_id from `%s` limit 1 offset %d)" % (q[1], q[3], q[4], q[1], int(q[2]) - 1))

    elif q[0] == "search":
        for i in db.execute("select * from `%s` where %s = '%s'" % (q[1], q[2], q[3])):
            for j in i[1:]:
                print(j, end=" ")
            print()

    elif q[0] == "print":
        if q[2] == "*":
            for i in db.execute("select * from `%s`" % (q[1])):
                for j in i[1:]:
                    print(j, end=" ")
                print()
        else:
            cl = q[2:-1]
            quer = "select h_id, %s from `%s` order by " % (",".join(cl), q[1])
            for c in cl:
                quer += "%s asc, " % c
            quer += "h_id asc"
            for i in db.execute(quer):
                for j in i[1:]:
                    print(j, end=" ")
                print()
            
