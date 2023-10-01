def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left_side = arr[:mid]
    right_side = arr[mid:]

    left_side = merge_sort(left_side)
    right_side = merge_sort(right_side)

    return merge(left_side, right_side)

def merge(left, right):
    result = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])
    return result

array = [12, 11, 13, 5, 6, 7]
sorted_array = merge_sort(array)
print("Sorted array:", sorted_array)
