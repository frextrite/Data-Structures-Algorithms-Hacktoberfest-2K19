a=int(input("enter the elements in the dictionary"))  #inputing the elements

d={}

for i in range(a):    
   key =int(input('Enter key:'))  #key
   age =input('Enter age:') #value 
   d[key]=age #key-value pair

print(d)

key_list=[]
value_list=[]
for keys,values in d.items():
    key_list.append(keys)
    value_list.append(values)


print(key_list)
print(value_list)
    
    
