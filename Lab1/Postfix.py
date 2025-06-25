stack = []

def isIntOrFLoat(value):
    try:
        float(value)
        return True
    except:
        return False

def eval_postfix(expression):
    for e in expression:
        if isIntOrFLoat(e):
            stack.append(e)
        else:
            op1 = stack.pop()
            op2 = stack.pop()
            if e == "^" or e == "$":
                result = eval(f"{op2}**{op1}")
            else:
                result = eval(f"{op2}{e}{op1}")
            stack.append(result)
    
    print(f"result is {stack.pop()}")


expression = input("Enter the expression each term separated by space: ")
eval_postfix(expression.split(" "))
