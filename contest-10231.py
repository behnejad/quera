a = [input() for i in range(5)]
count = []
for i in range(len(a)):
    if "HAFEZ" in a[i] or "MOLANA" in a[i]:
        count.append(i + 1)
if len(count) > 0:
    print(" ".join(str(x) for x in count))
else:
    print("NOT FOUND!")
