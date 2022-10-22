def binarySearch (array, left, right, search): 
  
    if right >= left: 
  
        mid = lelf + (right - left) // 2
  
        if array[mid] == search: 
            return mid 
   
        elif array[mid] > search: 
            return binarySearch(array, lelf, mid-1, search) 
  
        else: 
            return binarySearch(array, mid + 1, right, search) 
  
    else: 
        return -1
  
array = [ 10, 40, 3, 2, 4, 50] 
search = 40
  
result = binarySearch(array, 0, len(arr)-1, search) 
  
if result != -1: 
    print ("Element is present at index % d" % result) 
else: 
    print ("Element is not present in array") 
