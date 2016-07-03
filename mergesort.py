def mergesort(A):
    if len(A)==1:
        return A
    if len(A) == 2:
        if A[0]>A[1]:
            A[0],A[1]=A[1],A[0]
        return A
    if len(A)>2:
        mid = len(A)/2
        first = A[:mid]
        last = A[mid:]
        first = mergesort(first)
        last = mergesort(last)
        return merge(first,last)
            

def merge(A,B):
    print "Given, A=",A,"B=",B
    posA = 0
    posB = 0
    temp = []
    while posA != len(A) and posB != len(B):
        if A[posA] < B[posB]:
            temp.append(A[posA])
            #print "temp added with",posA,"element of A i.e.",A[posA]
            posA += 1
            #print "posA=",posA
        elif A[posA] >= B[posB]:
            temp.append(B[posB])
            #print "temp added with",posB,"element of B i.e.",B[posB]
            posB += 1
            #print "posB=",posB
    if posA == len(A) and posB != len(B):
        temp = temp + B[posB:]
        #print "posA == len(A)-1 and posB != len(B)-1"
        #print "Inside 1st case: posA =",posA,"posB =",posB
    elif posB == len(B) and posA != len(A):
        temp = temp + A[posA:]
        #print "posB == len(B) and posA != len(A)"
        #print "Inside 2ns case: posA =",posA,"posB =",posB
    print "temp sorted array:",temp
    return temp

print mergesort ([1,3,7,25,28,29,2,9,11,15,23,27])
