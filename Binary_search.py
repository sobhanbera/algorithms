def binary_search(arr, x): 
    low = 0
    high = len(arr) - 1
    mid = 0
  
    while low <= high: 
  
        mid = (high + low) // 2
  
        # Check if x is present at mid 
        if arr[mid] < x: 
            low = mid + 1
  
        # If x is greater, ignore left half 
        elif arr[mid] > x: 
            high = mid - 1
  
        # If x is smaller, ignore right half 
        else: 
            return mid 
  
    # If we reach here, then the element was not present 
    return -1
  
## Input
elements = int(input("how many elements you want to enter in the array??"))
arr = []
for i in range(1,elements+1):
    a = int(input(f"Enter the Element No. {i} : "))
    arr.append(a)
 
x = int(input("Enter the element that you want to search"))
  
# Function call 
result = binary_search(arr, x) 
  
if result != -1: 
    print("Element is present at index", str(result)) 
else: 
    print("Element is not present in array") 
