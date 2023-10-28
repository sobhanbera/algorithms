// This function implements the Quick Sort algorithm to sort an array.
function quickSort(arr) {
  // Base case
  if (arr.length <= 1) {
    return arr;
  }

  // Choose a pivot element(First, Middle, Last). In this code, it's the middle element.
  const pivotIndex = Math.floor(arr.length / 2);
  const pivot = arr[pivotIndex];
  const left = [];
  const right = [];

  // Iterate through the array and partition elements into 'left' and 'right'.
  for (let i = 0; i < arr.length; i++) {
    if (i === pivotIndex) continue; // Skip the pivot element.
    if (arr[i] < pivot) {
      left.push(arr[i]); // Elements less than pivot go to 'left'.
    } else {
      right.push(arr[i]); // Elements greater than pivot go to 'right'.
    }
  }

  // Recursively sort 'left' and 'right', and concatenate them with the pivot in between.
  return [...quickSort(left), pivot, ...quickSort(right)];
}

function main() {
  const arr = [8, 20, -10, 4, -6, 16, 5];
  const sortedArray = quickSort(arr);
  console.log("Sorted Array:", sortedArray);
}

main();

// Quick Sort has an average-case time complexity of O(n log n) and a worst-case time complexity of O(n^2). The space complexity is O(n) in the worst case and O(log n) on average due to the call stack and the space required for creating subarrays.

// First Element or Last Element: Choosing the first element or last element as the pivot is another straightforward option. It's a bit faster to implement as you don't need to calculate the middle index, but it can be less effective on already sorted or reverse-sorted arrays. In the worst case, when the array is sorted or nearly sorted, selecting the first element as the pivot can lead to a skewed partition and result in the worst-case time complexity of O(n^2).
