class Node:
    def __init__(self,init_data):
        self.data = init_data
        self.next = None

class LL:
    def __init__(self):
        self.head = None
        self.count = 0

    def addNode(self,node):
        if self.head == None:
            self.head = node
        else:
            current = self.head
            while current.next != None:
                current = current.next
            current.next = node
        self.count += 1
        print node.data,"has been appended to the list"
        return

    def length(self):
        return self.count

    def printll(self):
        if self.count == 0:
            print "No node in link list to print"
        current = self.head
        while current != None:
            print current.data, 
            current = current.next

    def dellast(self):
        current = self.head
        if current == None:
            print "link list is already empty"
            return
        elif current.next == None:
            self.head = None
            print "link list is now empty"
        else:
            while current.next.next != None:
                current = current.next
            current.next = None
            print "Last node deleted"
        self.count -= 1
        return

    def delbeg (self):
        current = self.head
        if current == None:
            print "link list is already empty"
            return
        elif current.next == None:
            self.head = None
            print "link list is now empty"
        else:
            self.head = current.next
            print "First node deleted"
        self.count -= 1

    def addtopos(self,node,pos):
        if self.count+1 < pos:
            print "You dumbass,pos =",pos,"can't be greater than length+1 which is",self.count+1
        elif pos == 1:
            '''current = self.head
            self.head = node
            node.next = current
            print node.data,"has been prepended"'''
            self.addNode(node)
            return
        else:
            prev = None
            current = self.head 
            mypos = 1
            while current != None and mypos != pos:
                mypos += 1
                prev = current
                current = current.next
                #if curnext != None:
            #print prev.data, mypos == pos       
            prev.next = node
            node.next = current
            print "node",node.data,"has been inserted at position",pos
        self.count += 1

a = Node(5)
print a.data

linklist = LL()
linklist.addNode(a)
linklist.addNode(Node(6))
linklist.addNode(Node(2))
print "number of nodes",str(linklist.length())
linklist.printll()
linklist.dellast()
print "number of nodes",str(linklist.length())
linklist.printll()
linklist.delbeg()
print "number of nodes",str(linklist.length())
linklist.printll()
linklist.delbeg()
print "number of nodes",str(linklist.length())
linklist.printll()
linklist.dellast()
print "number of nodes",str(linklist.length())
linklist.printll()
linklist.addtopos(Node(88),1)
linklist.addtopos(Node(82),2)
linklist.addtopos(Node(8),2)
linklist.addtopos(Node(38),1)
linklist.addtopos(Node(98),6)
linklist.printll()
