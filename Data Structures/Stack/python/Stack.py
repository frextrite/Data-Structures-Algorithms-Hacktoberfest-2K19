
class Stack:
    size = 10000
    st = list()

    def __init__(self,size):
        if(size != 'n'):
            self.size = int(size)

    def push(self):
        if(len(self.st) >= self.size):
            print("Overflow")
        else:
            s = input("Enter the variable to the stack ")
            self.st.append(s)
            print("Sucessfully Pushed")
    
    def pop(self):
        if(len(self.st) == 0):
            print("empty stack")
            return "none"
        else:
            return self.st.pop()

    def printStack(self):
        print()
        if(len(self.st) == 0):
            print("empty stack")
        else:
            for i in range(len(self.st)):
                print(self.st[len(self.st)-1-i] ,end = "-"),
        
def main():
    cmd = 0
    size = input("Here is a stack please enter size of your stack if you want or else press n and enter ")
    while(cmd != 4):
        print("1.Push 2.Pop 3.Display Stack 4.Exit")
        cmd = int(input("Enter what you want "))
        l = Stack(size)
        if(cmd == 1):
            l.push()
        if(cmd == 2):
            print("The element poped is " + l.pop())

        if(cmd == 3):
            l.printStack()
        print()

main()
