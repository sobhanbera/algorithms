const array = [100, 5, 60, 3, 1, 2, 7, 9, 10, 4, 6, 8, 11, 12, 13, 14, 15, 16, 17]

function insertionSort(array) {
    let i = 1
    
    while (i < array.length) {
        let j = i
        while (j > 0 && array[j - 1] > array[j]) {
            let temp = array[j]
            array[j] = array[j - 1]
            array[j - 1] = temp
            j--
        }
        i++
    }

    return array
}

const sortedArray = insertionSort(array)
console.log(sortedArray) // [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, ..., 100]