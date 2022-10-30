const binary_search = (arr, target) => {
  let start = 0;
  let end = arr.length - 1;
  let mid = Math.floor((start + end) / 2);
  while (arr[mid] !== target && start <= end) {
    if (target < arr[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
    mid = Math.floor((start + end) / 2);
  }
  return arr[mid] === target ? mid : -1;
};

const arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(binary_search(arr, 2)); // 1
