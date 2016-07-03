def partition(A):
    print "Given:",A
    pivot = A[0]
    i = j = 1
    while j < len(A):
        if A[j] < pivot:
            A[j],A[i]=A[i],A[j]
            print "swapped:",A[i],A[j]
            i += 1
        j += 1
    A[0],A[i-1]=A[i-1],A[0]
    print A,i-1


partition([4,8,3,6,1])


