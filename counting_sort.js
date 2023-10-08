/**
 *     Counting Sort Algorithm
 *
 * Counting sort is a sorting algorithm that sorts the elements of an array by counting
 * the number of occurrences of each unique element in the array.
 * The count is stored in an auxiliary array and the sorting is done
 * by mapping the count as an index of the auxiliary array.
 *
 * Explanation taken from: https://programiz.com/dsa/counting-sort
 *
 * @param {Array} list List of integers eg. [3, -12, 7, 2, -9, 1, 0, 14, 9]
 */

function countingSort(list) {
  const min = Math.min(...list);
  const max = Math.max(...list);

  let count = [];
  let a = min;
  let b = 0;

  for (a; a <= max; a++) {
    count[a] = 0;
  }

  for (a = 0; a < list.length; a++) {
    count[list[a]] += 1;
  }

  for (a = min; a <= max; a++) {
    while (count[a]-- > 0) {
      list[b++] = a;
    }
  }
  return list;
}

/**
 * Additional function to create sample array to use counting sort on
 *
 * @param {Integer} min Minimum Value
 * @param {Integer} max Maximum Value
 * @param {Integer} length Length of desired array
 * @return {Array}  List of random integers between min and max
 */
function generateRandomListOfIntegers(min, max, length) {
  return Array.from({ length }, () => {
    return Math.floor(Math.random() * (max - min + 1)) + min;
  });
}

let list = generateRandomListOfIntegers(-50, 50, 20);

console.log("Random list:");
console.log(list);

console.log("Sorted list:");
console.log(countingSort(list));
