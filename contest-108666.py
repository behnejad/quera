import sqlite3
con = sqlite3.connect(':memory:')
cur = con.cursor()
cur.execute("create table student (i integer, name txt, id txt, year integer, field txt)")
cur.execute("create table teacher (name txt, id txt, field txt)")
cur.execute("create table class   (name txt, id txt, field txt, t_id txt)")
cur.execute("create table class_member (st_id txt, cl_id txt, grade integer)")

st_id = 1

while True:
    line = input()

    if line == "":
        continue
    else:
        line = line.split()

    if line[0] == "end":
        break
    
    elif line[0] == "register_student":
        if cur.execute(f"select count(1) from student where id = '{line[2]}'").fetchone()[0] != 0:
            print("this identical number previously registered")
        else:
            cur.execute(f"insert into student values ({st_id}, '{line[1]}', '{line[2]}', {line[3]}, '{line[4]}')")
            st_id += 1
            print("welcome to golestan")
            
    elif line[0] == "register_professor":
        if cur.execute(f"select count(1) from teacher where id = '{line[2]}'").fetchone()[0] != 0:
            print("this identical number previously registered")
        else:
            cur.execute(f"insert into teacher values ('{line[1]}', '{line[2]}', '{line[3]}')")
            print("welcome to golestan")
            
    elif line[0] == "make_class":
        if cur.execute(f"select count(1) from class where id = '{line[2]}'").fetchone()[0] != 0:
            print("this class id previously used")
        else:
            cur.execute(f"insert into class values ('{line[1]}', '{line[2]}', '{line[3]}', '')")
            print("class added successfully")
            
    elif line[0] == "add_student":
        if cur.execute(f"select count(1) from student where id = '{line[1]}'").fetchone()[0] == 0:
            print("invalid student")
        elif cur.execute(f"select count(1) from class where id = '{line[2]}'").fetchone()[0] == 0:
            print("invalid class")
        elif cur.execute(f"select count(1) from student where field = (select field from class where id = '{line[2]}') and id = '{line[1]}'").fetchone()[0] == 0:
            print("student field is not match")
        elif cur.execute(f"select count(1) from class_member where st_id = '{line[1]}' and cl_id = '{line[2]}'").fetchone()[0] != 0:
            print("student is already registered")
        else:
            cur.execute(f"insert into class_member values ('{line[1]}', '{line[2]}', -1)")
            print("student added successfully to the class")

    elif line[0] == "add_professor":
        if cur.execute(f"select count(1) from teacher where id = '{line[1]}'").fetchone()[0] == 0:
            print("invalid professor")
        elif cur.execute(f"select count(1) from class where id = '{line[2]}'").fetchone()[0] == 0:
            print("invalid class")
        elif cur.execute(f"select count(1) from teacher where field = (select field from class where id = '{line[2]}') and id = '{line[1]}'").fetchone()[0] == 0:
            print("professor field is not match")
        elif cur.execute(f"select t_id from class where id = '{line[2]}'").fetchone()[0] != "":
            print("this class has a professor")
        else:
            cur.execute(f"update class set t_id = '{line[1]}' where id = '{line[2]}'")
            print("professor added successfully to the class")

    elif line[0] == "student_status":
        if cur.execute(f"select count(1) from student where id = '{line[1]}'").fetchone()[0] == 0:
            print("invalid student")
        else:
            res = " ".join([str(x) for x in cur.execute(f"select name, year, field from student where id = '{line[1]}'").fetchone()]) + " "
            for n in cur.execute(f"select class.name from class left outer join class_member where class.id = class_member.cl_id and class_member.st_id = '{line[1]}'"):
                res += n[0] + " "
            print(res[:-1])

    elif line[0] == "professor_status":
        if cur.execute(f"select count(1) from teacher where id = '{line[1]}'").fetchone()[0] == 0:
            print("invalid professor")
        else:
            res = " ".join([str(x) for x in cur.execute(f"select name, field from teacher where id = '{line[1]}'").fetchone()]) + " "
            for n in cur.execute(f"select name from class where class.t_id = '{line[1]}' "):
                res += n[0] + " "
            print(res[:-1])

    elif line[0] == "class_status":
        if cur.execute(f"select count(1) from class where id = '{line[1]}'").fetchone()[0] == 0:
            print("invalid class")
        else:
            tid = cur.execute(f"select t_id from class where id = '{line[1]}'").fetchone()[0]
            if tid == "":
                res = "None "
            else:
                res = cur.execute(f"select name from teacher where id = '{tid}'").fetchone()[0] + " "

            for n in cur.execute(f"select student.name from student left outer join class_member where student.id = class_member.st_id and class_member.cl_id = '{line[1]}'"):
                res += n[0] + " "
            print(res[:-1])

    elif line[0] == "set_final_mark":
        if cur.execute(f"select count(1) from teacher where id = '{line[1]}'").fetchone()[0] == 0:
            print("invalid professor")
        elif cur.execute(f"select count(1) from student where id = '{line[2]}'").fetchone()[0] == 0:
            print("invalid student")
        elif cur.execute(f"select count(1) from class where id = '{line[3]}'").fetchone()[0] == 0:
            print("invalid class")
        elif cur.execute(f"select count(1) from class where id = '{line[3]}' and t_id = '{line[1]}'").fetchone()[0] == 0:
            print("professor class is not match")
        elif cur.execute(f"select count(1) from class_member where cl_id = '{line[3]}' and st_id = '{line[2]}'").fetchone()[0] == 0:
            print("student did not registered")
        else:
            cur.execute(f"update class_member set grade = {line[4]} where cl_id = '{line[3]}' and st_id = '{line[2]}'")
            print("student final mark added or changed")

    elif line[0] == "mark_student":
        if cur.execute(f"select count(1) from student where id = '{line[1]}'").fetchone()[0] == 0:
            print("invalid student")
        elif cur.execute(f"select count(1) from class where id = '{line[2]}'").fetchone()[0] == 0:
            print("invalid class")
        elif cur.execute(f"select count(1) from class_member where cl_id = '{line[2]}' and st_id = '{line[1]}'").fetchone()[0] == 0:
            print("student did not registered")
        else:
            m = cur.execute(f"select grade from class_member where cl_id = '{line[2]}' and st_id = '{line[1]}'").fetchone()[0]
            print("None" if m == -1 else m)

    elif line[0] == "mark_list":
        if cur.execute(f"select count(1) from class where id = '{line[1]}'").fetchone()[0] == 0:
            print("invalid class")
        elif cur.execute(f"select count(1) from class where id = '{line[1]}' and t_id = ''").fetchone()[0] != 0:
            print("no professor")
        elif cur.execute(f"select count(1) from class_member where cl_id = '{line[1]}'").fetchone()[0] == 0:
            print("no student")
        else:
            res = ""
            for n in cur.execute(f"select grade from class_member where cl_id = '{line[1]}'"):
                res += str(n[0]) + " "
            print(res[:-1])

    elif line[0] == "average_mark_professor":
        if cur.execute(f"select count(1) from teacher where id = '{line[1]}'").fetchone()[0] == 0:
            print("invalid professor")
        else:
            res = cur.execute(f"select avg(grade) from class_member where grade != -1 and cl_id in (select id from class where t_id  = '{line[1]}')").fetchone()[0]
            print("None" if res is None else f"{res:.2f}")

    elif line[0] == "average_mark_student":
        if cur.execute(f"select count(1) from student where id = '{line[1]}'").fetchone()[0] == 0:
            print("invalid student")
        else:
            res = cur.execute(f"select avg(grade) from class_member where grade != -1 and st_id = '{line[1]}'").fetchone()[0]
            print("None" if res is None else f"{res:.2f}")

    elif line[0] == "top_student":
        res = cur.execute(f"select name, avg(grade) as mark from class_member left outer join student where student.id = class_member.st_id and year = {line[2]} and field = '{line[1]}' group by st_id order by mark desc, student.i").fetchall()
        if len(res) == 0:
            print("None")
        else:
            print(res[0][0])

    elif line[0] == "top_mark":
        if cur.execute(f"select count(1) from class where id = '{line[1]}'").fetchone()[0] == 0:
            print("invalid class")
        else:
            res = cur.execute(f"select max(grade) from class_member where cl_id = '{line[1]}' and grade != -1").fetchone()
            if len(res) == 0:
                print("None")
            else:
                print(res[0])




