def quick_sort(a):  #a is a list of numbers
    if(len(a)<=1):
        return(a)
    mid=a[len(a)//2]
    left=[x for x in a if x<mid ]
    middle=[x for x in a if x==mid]
    right=[x for x in a if x>mid]
    return(quick_sort(left)+middle+quick_sort(right))


if(__name__=='__main__'):
    arr=[]
    n=input('Enter the number of elements')
    print("Enter the elements")
    for i in range(int(n)):
        arr.append(int(input()))
    print("Before sorting")
    print(arr)
    arr=quick_sort(arr)
    print("After sorting")
    print(arr)
