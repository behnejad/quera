jomle = input().lower()
kalame = input().lower()
j1 = []
ponc = "!@#$%^&*()-_=+,./;\\[]{}:\"|?><"
for i in ponc:
    jomle = jomle.replace(i, " ")

j1 = jomle.split()
res = j1.count(kalame) + j1.count(kalame[::-1])
print(res)

    
