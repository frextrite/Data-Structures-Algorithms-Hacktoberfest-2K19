#The Head of Linked List
class LinkedList(object):
    def __init__(self, head=None):
        self.head = head
      
 # Insertion
def insert(self, data):
    new_node = Node(data)
    new_node.set_next(self.head)
    self.head = new_node

# Size
def size(self):
    current = self.head
    count = 0
    while current:
        count += 1
        current = current.get_next()
    return count

# Searching in a Linked List
def search(self, data):
    current = self.head
    found = False
    while current and found is False:
        if current.get_data() == data:
            found = True
        else:
            current = current.get_next()
    if current is None:
        raise ValueError("Data not in list")
    return current

# Deletion in a Linked List
def delete(self, data):
    current = self.head
    previous = None
    found = False
    while current and found is False:
        if current.get_data() == data:
            found = True
        else:
            previous = current
            current = current.get_next()
    if current is None:
        raise ValueError("Data not in list")
    if previous is None:
        self.head = current.get_next()
    else:
        previous.set_next(current.get_next())
