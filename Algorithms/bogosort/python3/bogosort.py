from random import shuffle
def isSorted(arr):
    for i in range(len(arr)-1):
        if arr[i] > arr[i+1]:
            return False
    return True

def bogo(arr):
    print(arr)
    count = 1
    while not isSorted(arr):
        shuffle(arr)
        print(str(count) + " - " + str(arr))
        count+=1

array = [8,6,7,5,3,0,9]
bogo(array)
