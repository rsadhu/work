def contains_duplicate(arr) -> bool:
    hash =  {}
    for val in arr:
        if val in hash:
            return True

        hash[val] = True
    return False


def contains_duplicate_sorting(arr)->bool:
    arr.sort()
    i = 0
    j = 1
    while(j < len(arr)):
        if (arr[i] is arr[j]):
            return True
        i+=1
        j+=1

    return False

def test1():
    arr = [1,2,3,1]
    print(contains_duplicate(arr))

    arr = [1,2,3,4]
    print(contains_duplicate(arr))
    
def test2():
    arr = [1,2,3,1]
    print(contains_duplicate_sorting(arr))

    arr = [1,2,3,4]
    print(contains_duplicate_sorting(arr))





if __name__ == "__main__":
    test1()
    test2()