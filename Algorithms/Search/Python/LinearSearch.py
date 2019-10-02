def Search(list,target):
    for i in range(len(list)):
        if list[i] == x:
            return i
    
    return -1

list = [1,2,3,10,20,30]
x = 3
result = Search(list, x)
if result == -1 :
    print('{} Not Found in List'.format(x))
else:
    print('{} Found at index {}'.format(x,result))