##########################################################
#Heap Sort Algorithm in Python - Code by Trusha Talati
##########################################################

def heapify(arr, n, i):
    largest = i 
    left_child = 2*i + 1
    right_child = 2*i + 2

    if(left_child<n and arr[left_child] > arr[largest]):
        largest = left_child
    if(right_child<n and arr[right_child] > arr[largest]):
        largest = right_child

    if largest != i:
        arr[largest], arr[i] = arr[i] , arr[largest]
        heapify(arr,n,largest)

def heapsort(arr,n) :

    for i in range(n//2 - 1,-1,-1): #gives max heap
        heapify(arr,n,i)   

    for i in range(n-1,0,-1):
        arr[0] , arr[i] = arr[i] , arr[0]  # max element at last ith position
        heapify(arr,i,0) # heapify ith elements to have next max at 0th position.

def main():
    arr = [4, 10, 3, 5, 1]
    heapsort(arr,len(arr))
    print("Sorted array -->",arr)

if __name__ == '__main__':
    main()