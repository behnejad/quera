def Input():
    number_of_words = int(input())
    words = [input() for _ in range(number_of_words)]
    local_key = [int(i) for i in input()]
    
    return words, local_key

def Output(words):
    for word in words:
        print(word)

def comp(a, b):
    a_moji = "moji" in a.lower()
    b_moji = "moji" in b.lower()
    
    if a_moji and not b_moji:
        return 1
    if b_moji and not a_moji:
        return 0
    return a < b

def mergeSort(array):    
    len_of_array = len(array)
    
    if len_of_array > 1:
        middle = len_of_array // 2
        left = array[:middle]
        right = array[middle:]
        
        mergeSort(left)
        mergeSort(right)
        
        index_array = 0
        index_left = 0
        index_right = 0
        
        len_left = len(left)
        len_right = len(right)
        
        while index_left < len_left and index_right < len_right:
            if comp(left[index_left], right[index_right]):
                array[index_array] = left[index_left]
                index_left += 1
                
            else:
                array[index_array] = right[index_right]
                index_right += 1
                
            index_array += 1
        
        while index_left < len_left:
            array[index_array] = left[index_left]
            index_left += 1
            index_array += 1
        
        while index_right < len_right:
            array[index_array] = right[index_right]
            index_right += 1
            index_array += 1

def decryption(array):
    global local_key
    
    len_array = len(array)
    if len_array == 1:
        return array
    
    key = local_key[(-1)*len_array:]
    parts = [[], []]
    
    for index in range(len_array):
        parts[key[index]].append(array[index])
    
    local_key = local_key[:(-1)*len_array]
    
    right = decryption(parts[1])
    left = decryption(parts[0])
    return left + right

words, local_key = Input()
mergeSort(words)
decrypted = decryption(words)
Output(decrypted)