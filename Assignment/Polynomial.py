# import re
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

def evaluate_polynomial(exp:SLL, x):
    answer = 0
    temp = exp.first
    while temp is not None:
        answer += temp.coeff * pow(x, temp.exp)
        temp = temp.next

    return answer


polynomial = input("Enter polynomial in form (ax2 + bx + c): ")
n = int(input("Enter the value of x: "))

polynomial = polynomial.replace("-","+-")

terms = polynomial.split("+")
terms = [term.strip() for term in terms]
terms = [term.replace(" ", "") for term in terms]

expression = SLL()

for term in terms:
    coeff_exp = term.split("x")
    expression.insert_at_end(int(coeff_exp[0]), int(coeff_exp[1]) if len(coeff_exp) == 2 else 0)

print(evaluate_polynomial(expression, n))



