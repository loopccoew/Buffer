import sys
import time
import copy
def main():
    condition=True

    A=[]
    while condition==True:
        menu()
        choice=input("Enter your choice")
        choice=int(choice)
        if choice==1:
            B=copy.deepcopy(A)

            ans=bubble(B)
            print("Execution time for Bubble Sort: ",ans)

        elif choice==2:
            B=copy.deepcopy(A)

            ans=selection(B)
            print("Execution time for Selection Sort: ",ans)

        elif choice==3:
            B=copy.deepcopy(A)

            ans=insertion(B)
            print("Execution time for Insertion Sort: ",ans)

        elif choice==4:
            B=copy.deepcopy(A)

            ans=merge(B)
            print("Execution time for Merge Sort: ",ans)

        elif choice==5:
            B=copy.deepcopy(A)

            ans=radix(B)
            print("Execution time for Radix Sort: ",ans)

        elif choice==6:
            print("Thankyou")
            condition=False
        elif choice<=0 and choice>=7:
            print("Invalid Choice, enter again")
            break;


def menu():
    print("Select Sorting method")
    print("1. Bubble Sort")
    print("2. Selection Sort")
    print("3. Insertion Sort")
    print("4. Merge Sort")
    print("5. Radix Sort")
    print("6. Exit\n")

def bubble(A):
    start=time.time()
    for i in range(len(A)):
        for j in range(0, len(A)-i-1):
            if A[j] > A[j+1] :
                A[j], A[j+1] = A[j+1], A[j]
    end=time.time()
    timex=(end-start)
    return timex

def selection(A):
    start=time.time()
    for i in range(len(A)):
        min_idx = i
        for j in range(i+1, len(A)):
            if A[min_idx] > A[j]:
                min_idx = j
        A[i], A[min_idx] = A[min_idx], A[i]
    end=time.time()
    timex=end-start
    return timex

def insertion(A):
    start=time.time()
    for i in range(1, len(A)):
        key = A[i]
        j = i-1
        while j >=0 and key < A[j] :
            A[j+1] = A[j]
            j -= 1
        A[j+1] = key
    end=time.time()
    timex=end-start
    return timex

def merge(arr):
    start=time.time()
    def mergeSort(arr):
        if len(arr) >1:
            mid = len(arr)//2
            L = arr[:mid]
            R = arr[mid:]
            mergeSort(L)
            mergeSort(R)
            i = j = k = 0
            while i < len(L) and j < len(R):
                if L[i] < R[j]:
                    arr[k] = L[i]
                    i+=1
                else:
                    arr[k] = R[j]
                    j+=1
                k+=1
            while i < len(L):
                arr[k] = L[i]
                i+=1
                k+=1
            while j < len(R):
                arr[k] = R[j]
                j+=1
                k+=1
    mergeSort(arr)
    end=time.time()
    timex=end-start
    return timex

def radix(arr):
    start=time.time()
    def countingSort(arr, exp1):
        n = len(arr)
        output = [0] * (n)
        count = [0] * (10)
        for i in range(0, n):
            index = int((arr[i]/exp1))
            count[ (index)%10 ] += 1
        for i in range(1,10):
            count[i] += count[i-1]
        i = n-1
        while i>=0:
            index = int((arr[i]/exp1))
            output[ count[ (index)%10 ] - 1] = arr[i]
            count[ (index)%10 ] -= 1
            i -= 1
        i = 0
        for i in range(0,len(arr)):
            arr[i] = output[i]
    def radixSort(arr):
        max1 = max(arr)
        exp = 1
        while max1/exp > 0:
            countingSort(arr,exp)
            exp *= 10

    radixSort(arr)
    end=time.time()
    timex=end-start
    return timex

main()
