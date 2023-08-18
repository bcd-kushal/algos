import sys
def output(a,b,c):
    print("{},{},{}".format(a,b,c))
def passValue(a):
    for i in range(2,a,b):
        giveValue(i,b)
def giveValue(a,b):
    
def sq(num):
    return int(num**2)
def valid(num):
    if(num<12):
        sys.exit("Too low input...")
def tripleSets(a,b,c):
    if sq(a)+sq(b)==sq(c-a-b):
        output(a,b,c-a-b)
num=int(input("Enter number: "))
valid(num)
