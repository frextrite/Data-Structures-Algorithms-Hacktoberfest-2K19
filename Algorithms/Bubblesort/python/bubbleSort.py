#Bubble sort for an that is given.

def bubbleSort(A): 
    n = len(A) 
  
    for i in range(n): 
        for j in range(0, n-i-1): 
            if A[j] > A[j+1] : 
                A[i], A[j+1] = A[j+1], A[j] 
  
A = [9, 7, 1, 5, 12, 99, 21, 22, 101] 
  
bubbleSort(A) 
  
print ("Sorted array: ") 
for i in range(len(A)): 
    print ("%d" %A[i]),  
