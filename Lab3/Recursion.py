def tailFact(n, a):
    if n == 1:
        return a
    else:
        return tailFact(n-1, a*n)

table = {}

# print(5 in table)

def fiboM(n):
    if n==1 or n==2:
        return 1
    else:
        if n not in table:
            table[n] = fiboM(n-1) + fiboM(n-2)
            
        return table[n]

def sum_natural(n):
    if n == 1:
        return 1
    else:
        return n + sum_natural(n-1)

def GCD(a,b):
    if b==0:
        return a
    else:
        return GCD(b, a%b)

print(f"The factorial of 5 is {tailFact(5,1)}")
print(f"The 50th fibonacci term is {fiboM(50)}")
print(f"The sum of first 10 natural numbers is {sum_natural(20)}")
print(f"The GCD of 10 and 25 is {GCD(125,10)}")