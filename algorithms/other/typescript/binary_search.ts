const binary_search = (arr: number[], key: number): number => {
  let low = 0;
  let high = arr.length - 1;
  while (low <= high) {
    let mid = Math.floor((low + high) / 2);
    if (arr[mid] === key) {
      return mid;
    }
    if (arr[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
};

const ar: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(binary_search(ar, 5));
