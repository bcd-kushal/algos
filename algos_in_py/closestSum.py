from itertools import permutations as nPr

#---------get closest sum to target----------
def sum_match(list,closest,target):
    if abs(target-sum(list))<abs(target-closest):
        return list
    return [0]
#--------------------------------------------


#--------------list validity check------------
def validity(list):
    if len(list)<2:
        sys.exit("Invalid length---------------")
#---------------------------------------------


#---find all nPr of list-------------
def permutation(list,num):
    closest=sum(list)
    for x in range(2,len(list)):
        arr=nPr(list,x)
        for i in range(row_length(arr)):
            sum_match(list,closest,num)
#------------------------------------
n=int(input("Enter size of array: "))
S=[]
for i in range(n):
    S.append(int(input("Element #{}: ".format(i+1))))

print("List = {}".format(S))

target=int(input("Enter target sum: "))
