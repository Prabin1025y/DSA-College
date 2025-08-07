class Node:
    def __init__(self, coeff, exp):
        self.coeff = coeff
        self.exp = exp
        self.next = None

class SLL:
    def __init__(self):
        self.first: Node = None
        self.last: Node = None

    def display(self):
        if self.first is None:
            print("Empty List.")
        else:
            temp = self.first
            data = ""
            while temp is not None:
                data += f"| {temp.coeff} | {temp.exp} | --> "
                temp = temp.next    
            data += "None"
            print(data)
    
    def insert_at_end(self, coeff, exp):
        NewNode = Node(coeff, exp)

        if self.first is None:
            self.first = NewNode
            self.last = NewNode
        else:
            self.last.next = NewNode
            self.last = NewNode
    
    def add(self, expression2: 'SLL'):
        term1 = self.first
        term2 = expression2.first
        result = SLL()
        while term1 is not None and term2 is not None:
            if term1.exp == term2.exp:
                result.insert_at_end(term1.coeff + term2.coeff, term1.exp)
                term1 = term1.next
                term2 = term2.next
            elif term1.exp > term2.exp:
                result.insert_at_end(term1.coeff, term1.exp)
                term1 = term1.next
            else:
                result.insert_at_end(term2.coeff, term2.exp)
                term2 = term2.next
    
        return result
            

polynomial1 = input("Enter 1st polynomial in form (ax2 + bx + c) in descending sorted exponent manner: ")
polynomial2 = input("Enter 2nd polynomial in form (ax2 + bx + c) in descending sorted exponent manner: ")

polynomial1 = polynomial1.replace("-","+-")
polynomial2 = polynomial2.replace("-","+-")

terms = polynomial1.split("+")
terms = [term.strip() for term in terms]
terms = [term.replace(" ", "") for term in terms]

expression1 = SLL()
expression2 = SLL()

for term in terms:
    coeff_exp = term.split("x")
    expression1.insert_at_end(int(coeff_exp[0]), int(coeff_exp[1]) if len(coeff_exp) == 2 else 0)

terms = polynomial2.split("+")
terms = [term.strip() for term in terms]
terms = [term.replace(" ", "") for term in terms]

for term in terms:
    coeff_exp = term.split("x")
    expression2.insert_at_end(int(coeff_exp[0]), int(coeff_exp[1]) if len(coeff_exp) == 2 else 0)

result = expression1.add(expression2)
expression1.display()
expression2.display()
result.display()



