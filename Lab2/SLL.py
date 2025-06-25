
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SLL:
    def __init__(self):
        self.first = None
        self.last = None

    def display(self):
        if self.first is None:
            print("Empty List.")
        else:
            temp = self.first
            data = []
            while temp is not None:
                data.append(temp.data)
                temp = temp.next    
            print(data)
    
    def insert_at_beginning(self, element):
        NewNode = Node(element)

        if self.first is None:
            self.first = NewNode
            self.last = NewNode
        else:
            NewNode.next = self.first
            self.first = NewNode
        
        print(f"{self.first.data} was inserted at beginning.")
    
    def insert_at_end(self, element):
        NewNode = Node(element)

        if self.first is None:
            self.first = NewNode
            self.last = NewNode
        else:
            self.last.next = NewNode
            self.last = NewNode
        
        print(f"{self.last.data} was inserted at end.")

    def insert_at_specific_position(self, element, pos):
        NewNode = Node(element)

        if pos <= 0:
            print("[Error]: Invalid Position")
        elif pos == 1:
            self.insert_at_beginning(element)
        else:
            temp = self.first

            for i in range(1, pos-1):
                if temp.next is None:
                    break
                temp = temp.next
            
            if temp == self.last:
                self.insert_at_end(element)
            else:
                NewNode.next = temp.next
                temp.next = NewNode
                print(f"{NewNode.data} was inserted at {pos}")
    
    def delete_from_beginning(self):
        if self.first is None:
            print("[Error]: List is empty.")
        elif self.first.next is None:
            self.first = self.last = None
        else:
            self.first = self.first.next
        
        print("Data was deleted from beginning.")
    
    def delete_from_end(self):
        if self.first is None:
            print("[Error] : List is empty.")
        elif self.first.next is None:
            self.first = self.last = None
        else:
            temp = self.first
            while temp.next != self.last:
                temp = temp.next
            
            self.last = temp
            self.last.next = None
        print("Data was deleted from end.")
    
    def delete_from_specifi_pos(self, pos):
        if pos <= 0:
            print("[Error]: Invalid Position")
        elif pos == 1:
            self.delete_from_beginning()
        else:
            temp = self.first
            for i in range(1, pos-1):
                if temp.next is None:
                    break
                temp = temp.next
            
            if temp.next == self.last:
                self.delete_from_end()
            tempp = temp.next
            temp.next = tempp.next
            
        print(f"Data was deleted from {pos}")


sll = SLL()
sll.insert_at_beginning(50)
sll.insert_at_beginning(33)
sll.insert_at_beginning(98)
sll.display()  
sll.insert_at_end(20)
sll.display()  
sll.insert_at_beginning(522)
sll.display()  
sll.insert_at_specific_position(10, 2) 
sll.display()  
sll.delete_from_beginning() 
sll.display()
sll.delete_from_end()        
sll.display()
sll.delete_from_specifi_pos(2)
sll.display()

    

