def bubblesort(A):
    pos = 0
    while (pos != len(A)-1):
        insidePos = 0
        while (insidePos != len(A)-1):
            if A[insidePos]>A[insidePos+1]:
                A[insidePos],A[insidePos+1]=A[insidePos+1],A[insidePos]
                print "swapped",insidePos,insidePos+1,"i.e.",A[insidePos],A[insidePos+1]
            insidePos += 1
        print "End of iteration",pos+1,"A now...",A
        pos += 1
    return A
    
print bubblesort([5,7,3,9,4,2,6])
