def hanoi(n, source, aux, target):
    if n > 0:
        # move tower of size n - 1 to aux:
        hanoi(n - 1, source, target, aux)

        # move disk from source to target
        if source:
            target.append(source.pop())
            
        # move tower of size n-1 from aux to target
        hanoi(n - 1, aux, source, target)
        
source = [4,3,2,1]
target = []
aux = []
n_disks = len(source)

print("Tower of Hanoi")
print ("source: ", source)
print("aux: ", aux) 
print ("target: ", target)

hanoi(n_disks, source, aux, target)

print ("\nsource: ", source)
print("aux: ", aux) 
print ("target: ", target)