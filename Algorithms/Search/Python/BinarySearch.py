def binarysearch(list, left, right, target):
    
    while left <= right:
        middle = (left + (right-1))//2

        # Start finding x at the center of the list
        if list[middle] == x:
            return middle
        
        # if it's not on the center, then check if x is larger than the center
        elif list[middle] < x :
            #if it's greater then the left partition is ignored
            left = middle + 1

        # Or if it's smaller, the right partition is ignored
        else:
            right = middle - 1
    
    # return -1 if the element did not exists
    return -1

list = [1,2,5,10,15,30,60,120]
x = 30
result = binarysearch(list, 0, len(list)-1, x)
if result == -1 :
    print('{} Not Found in The List'.format(x))
else:
    print('{} Found at index {}'.format(x, result))