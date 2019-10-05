class node:
    def __init__(self,val):
        self.val = val
        self.next=None

class circular:
    def __init__(self):
        self.head=None

    def insert(self,val):
        temp=node(val)
        temp.next=temp
        if self.head:
            temp.next=self.head.next
            self.head.next=temp
        else:
            self.head=temp

    def remove(self,val):
        temp=self.head
        if temp:
            if temp.val==val:
                if temp.next!=temp:
                    temp.val=temp.next.val
                    temp.next=temp.next.next
                else:
                    self.head=None
            else:
                temp=temp.next
                while temp!=self.head:
                    if temp.val==val:
                        if temp.next==self.head:
                            temp.val=temp.next.val
                            temp.next=temp.next.next
                            self.head=temp
                        else:
                            temp.val=temp.next.val
                            temp.next=temp.next.next
                        break
                    temp=temp.next

    def printList(self):
        temp=self.head
        if temp:
            print(temp.val)
            temp=temp.next
            while(temp!=self.head):
                print(temp.val)
                temp=temp.next

l = circular()
for i in range(10):
    l.insert(i)
l.printList()

for i in range(5):
    l.remove(i)
l.printList()