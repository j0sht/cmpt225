def swap(A,i,j):
    tmp = A[i]
    A[i] = A[j]
    A[j] = tmp

def selectionSort(A):
    for i in range(0, len(A)-1):
        minVal = A[i]
        minIndex = i
        for j in range(i+1, len(A)):
            if (A[j] < minVal):
                minVal = A[j]
                minIndex = j
        swap(A,i,minIndex)

