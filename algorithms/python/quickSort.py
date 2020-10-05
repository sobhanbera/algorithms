def quickSort(arr, low, high):
    if low < high:
        loc = partition(arr, low, high)
        quickSort(arr, low, loc-1)
        quickSort(arr, loc + 1, high)

def partition(arr, low, high):
    pivot = arr[high]
    i = (low - 1)
    for j in range(low, high):
        if arr[j] < pivot:
            [arr[i], arr[j]] = [arr[j], arr[i]]
    [arr[i+1], arr[high]] = [arr[high], arr[i+1]]
    return i + 1
array = [15,46,35,47,77,69,82,55,46,40,53,61,31,12,52,74,53,15,34,7,69,8,82]
n = len(array)
for j in range(n):
    print(array[j])
print("")
quickSort(array, 0, n-1)
print(array)
