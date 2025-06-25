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

expression = SLL()
n = int(input("Enter the number of terms: "))
for i in range(n):
    user_input = input(f"Enter coefficient and exponent of {i+1}th term separated by space (a b): ")
    coeff = int(user_input.split(" ")[0])
    exp = int(user_input.split(" ")[1])
    expression.insert_at_end(coeff, exp)

x = int(input("Enter the value of x: "))

print(evaluate_polynomial(expression, x))



