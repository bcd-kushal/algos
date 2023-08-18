# Write a function that returns true if exactly one word in the array differs
# in length from the rest. Return false in all other cases.

def oddOne(words,index,lengths):
    if index==len(words):return True
    if len(words[index])!=lengths[0]:lengths[1]=len(words[index])
    if len(words[index]) not in lengths:return False
    return oddOne(words, index+1, lengths)

print(oddOne(["words","four","fexxing"], 0, lengths=[4,4]))
