def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n-i-1):
            if(arr[j+1] < arr[j]):
                arr[j+1],arr[j] = arr[j], arr[j+1]
                swapped = True
        if swapped == False:
            break;

arr = [23, 112, 2, 124, 56, 90, 124, 78, 41, 98]
bubbleSort(arr)
print("Sorted array is: ")
for i in range(len(arr)):
    print("%d" %arr[i], end=" ")