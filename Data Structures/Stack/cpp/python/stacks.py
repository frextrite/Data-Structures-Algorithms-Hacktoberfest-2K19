#stacks
class stack:
    s=[]
    def push(self):
        a=input('enter no.')
        stack.s.append(a)
    def disp(self):
        if z.s==[]:
            print 'underflow situation'
        else:
            for x in range (len(z.s)-1,-1,-1):
                print z.s[x]
    def pop(self):
        if z.s==[]:
            print 'underflow situation'
        else:
            print 'deleted no.', z.s.pop()
z=stack()
ch='y'
while ch=='y':
    opt=input('enter 1 to push, enter 2 to pop, enter 3 to display')
    if opt==1:
        z.push()
    elif opt==2:
        z.pop()
    elif opt==3:
        z.disp()
    ch=raw_input('press y to continue')