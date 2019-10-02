def sortFun(arr):
    n=len(arr)
    for i in range(1,n):
        for j in range(n - i):
            if arr[j] > arr[j + 1]:
                arr[j] = arr[j] + arr[j + 1]
                arr[j + 1] = arr[j] - arr[j + 1]
                arr[j] = arr[j] - arr[j + 1]

print('Enter space-seperated intgers:',end=' ')
arr = list(map(int,input().split()))
print('Array read:',end=' ')
print(arr)
sortFun(arr)
print('After sort array:',end=' ')
print(arr)