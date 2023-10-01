function selectionSort(array) {
    for (let i = 0; i < array.length; i++) {
      let minIndex = i;
  
      for (let j = i + 1; j < array.length; j++) {
        if (array[j] < array[minIndex]) {
          minIndex = j;
        }
      }
  
      [array[i], array[minIndex]] = [array[minIndex], array[i]];
    }
  
    return array;
  }