users=dict()
idsList=[]
data=[]
output=[]
findCount=0
userNotFoundRes="No user found"
userFound = 0
limit=0

def find_user(count,searchKey):
    for key in sorted(users):
        if str(key).startswith(searchKey):
           global limit
           limit=limit+1
           if limit<=10:
            output.append(str(count)+" "+users.get(key))
           global userFound
           userFound=1



def add_user(arr):
 for i in range(0,len(arr)):
     if len(arr[i].split(" ")) == 5:
            id=arr[i].split(" ")[4]
            idsList.append(id)
            users[id]=arr[i].split(" ")[1]+" "+arr[i].split(" ")[2]+" "+arr[i].split(" ")[3]+" "+arr[i].split(" ")[4]
            output.append("User "+id+" added successfully")
     if len(arr[i].split(" ")) == 2:
            key=arr[i].split(" ")[1]
            global findCount
            findCount =findCount+1
            find_user(findCount,key)
            global limit
            limit=0
            global userFound
            if userFound!=1:
                output.append(str(findCount)+" "+userNotFoundRes)
     userFound=0



try:
    while True:
     data.append(input())
except EOFError as error:
    add_user(data)
    idsList.sort()
    for i in range(len(output)):
        print(output[i])
