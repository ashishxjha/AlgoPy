
def peakfind1d(A):
    for i in range(0,len(A)):
        if(i==0 or i==len(A)-1):
            if(A[0]>A[1]):
                print (A[0])
            if(A[len(A)-1]>A[len(A)-2]):
                print(A[len(A)-1])
        else:
            if(A[i]>A[i-1] and A[i]>A[i+1]):
                print(A[i])

import random as random
A=random.sample(range(1,20), 10)

peakfind1d(A)
