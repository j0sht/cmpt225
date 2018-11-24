def binarySum(A, B):
    C = [0] * (len(A)+1)
    i = len(A)-1
    carry = 0
    while (i >= 0):
        s = A[i] + B[i] + carry
        if (s == 3):
            carry = 1
            C[i+1] = 1
        elif (s == 2):
            carry = 1
            C[i+1] = 0
        elif (s == 1):
            carry = 0
            C[i+1] = 1
        else:
            carry = 0
            C[i+1] = 0
        i -= 1
    C[i+1] = carry
    return C

def altBinarySum(A, B):
    C = [0] * (len(A)+1)
    i = len(A)-1
    carry = 0
    while (i >= 0):
        s = A[i] + B[i] + carry
        C[i+1] = (s % 2)
        carry = (s // 2)
        i -= 1
    C[0] = carry
    return C
