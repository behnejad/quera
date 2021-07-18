def compare(string1, string2):
    while len(string1) and len(string2):
        if string1[0] < string2[0]:
            string1 = string1[1:]
        elif string1[0] > string2[0]:
            string2 = string2[1:]
        else:
            string1 = string1[1:]
            string2 = string2[1:]

        if len(string1):
            string2 = string2[::-1]
        if len(string2):
            string1 = string1[::-1]

    if len(string1) == 0 and len(string2) == 0:
        return "Both strings are empty!"
    elif len(string1):
        return string1
    else:
        return string2

        
