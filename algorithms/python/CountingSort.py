# Counting sort is a non-comparison sorting algorithm that works well when the range of values in the input array is small.
# It works by counting the number of occurrences of each element in the input array and then using this information to construct
# the sorted output array.

# 💡 [ Time Complexity: O(n + k), where n is the number of elements in the input array and k is the range of input. ]

def counting_sort(arr):
    # Find the maximum and minimum values in the input array
    max_val = max(arr)
    min_val = min(arr)

    # Create a counting array to store the count of each distinct element
    count = [0] * (max_val - min_val + 1)

    # Count the occurrences of each element in the input array
    for num in arr:
        count[num - min_val] += 1

    # Reconstruct the sorted array from the counting array
    sorted_arr = []
    for i in range(len(count)):
        while count[i] > 0:
            sorted_arr.append(i + min_val)
            count[i] -= 1

    return sorted_arr


def main():
    input_arr = [4, 2, 2, 8, 3, 3, 1]  # example input array
    sorted_arr = counting_sort(input_arr)  # sort the input array
    print(sorted_arr)  # print the sorted array


if __name__ == '__main__':
    main()
