def merge_lists(left, right):
    i, j = 0, 0
    result = []

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
		
    result += left[i:]
    result += right[j:]

    return result


def merge_sort(list):
    if len(list) <= 1:
        return list
    else:
        midpoint = int(len(list) / 2)
        left = merge_sort(list[:midpoint])
        right = merge_sort(list[midpoint:])
        return merge_lists(left, right)

number_list = [5, 12, 31, 7, 234, 7, 1, 9, 3, 4, 634, 1, 0, 65, 234, 9]
print(merge_sort(number_list))