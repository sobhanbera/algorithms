def quickSort(arr):

    # Base case
    if len(arr) < 2:
        return arr
    
    curr = 0  # Position of the partitioning element

    for i in range(1, len(arr)):  # Partitioning loop
         if arr[i] <= arr[0]:
              curr += 1
              temp = arr[i]
              arr[i] = arr[curr]
              arr[curr] = temp

    temp = arr[0]
    arr[0] = arr[curr] 
    arr[curr] = temp  # Brings pivot to it's appropriate position
    
    left = quickSort(arr[0:curr]) 
    right = quickSort(arr[curr+1:len(arr)])

    arr = left + [arr[curr]] + right  # Merging everything together
    
    return arr

def main():
    arr = [4, 2, 7, 3, 1, 6]
    arr = quickSort([4, 2, 7, 3, 1, 6])
    print("Sorted array -->",arr)

if __name__ == '__main__':
    main()