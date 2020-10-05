## How to contribute an implementation (code)?

*   Have a look at open issues. They contain the list of algorithms/DS we plan to be implemented. Pick an unassigned issue.
*   You can also create a new issue for an algorithm that is not in the list.
*   Make sure you are assigned for the issue.
*   Code the algorithm/DS following the style guide defined below.
*   Send a PR. 
*   Be sure to not include any compiled binaries in the patch.
*   While sending a PR make sure you follow one issue per PR rule.

<a name="sa"></a>

## Suggesting an algorithm / DataStructure / Question:

*   First make sure you are not suggesting a duplicate.
*   If not, proceed and create the issue. Make sure that you specify only one language in an issue. Create multiple 
issues for different languages.
*   Please include at least one external link for the algorithm/DS in the issue's body for each issue. The link 
should explain the algorithm/problem/DS in detail.  
*   Title of issue should be of the following format -
    ```
        Algorithm/DS Name [Language]
    ```

## Code Style Guide

*   Code submitted should be modular. 
*   Don't use global variables.
*   Use separate folders for each concept. Folder name should be in full lowercase. If the algorithm/DS name has 
multiple words, separate them by underscores. (eg `longest_common_subsequence`)
*   Filename should be derived from the folder name. (eg `longest_common_subsequence` becomes 
`longestCommonSubsequence.c` or `LongestCommonSubsequence.java`)
*   Name of master function of the code should be kept same as filename to the best extent possible.
*   Prefer classes instead of multiple helper functions (where applicable).
*   Currently, we are accepting contributions in C, C++, C#, Java, Python, Go and JavaScript, Typescript but other languages 
may be considered after a discussion.
*   Define `tester` code only in `main` routine.
*   Use meaningful variable, method and function names and comments.
*   No profanity.
*   Use external libraries only when no other solution is possible/plausible.
*   We have defined [skeleton codes](#samples) for some popular languages below. Please follow them whenever possible.


## Improving an implementation

*   If you feel you can improve upon an implementation, feel free to open an issue discussing the improvements.


## Samples

**C**

```c
bool binarysearch(int *ar, int x) {
    /*
        Your implementation here...
    */
}

int main() {
	int ar_size = 4;
	int a[4] = {2, 3, 4, 9, 15, 23, 52};
	if(binarysearch(a, 15)) {
      cout << "present in array\n";
  }else {
      cout << "not present in array\n";
  }
	return 0;
}
```

**Java**

```java
public class BinarySearch {    
    public static void main(String[] args) {
        int[] arr = new int[] {2, 3, 0, 4};
        if(binarySearch(arr, 15)) {
            System.out.println("present in array");
        }else {
            System.out.println("not present in array");
        }
    }

    static boolean binarySearch(int[] a, int x) {
        /*
            Your implementation here...
        */
    }
}
```

**Python**

```python
def mergesort(arr):
    #
    # Your implementation here...
    #

def main():
    arr = [2, 3, 0, 4]
    sorted_arr = mergesort(arr)
    print(sorted_arr)
    
if __name__ == '__main__':
    main()
```


**JavaScript**

```JavaScript
function mergeSort (arr) {
	/*
	Your implementation here
	*/
}

function main () {
	let input = [2, 3, 0, 4];
	mergeSort(input);
	for (let x in input) {
		console.log(input[x] + ' ');
	}
}

main();
```

**C#**

```csharp
using System;

public class MergeSort {  
    public static void MergeSort(int[] a) {
        /*
            Your implementation here...
        */
    }
    
    public static void Main() {
        int[] arr = new int[] {2, 3, 0, 4};
        MergeSort(arr);
        foreach(int element in arr) {
            Console.Write(element + " ");
        }
        Console.WriteLine("");
    }
}
```

**Golang**

```go
package main

import "fmt"

// QuickSort sorts an array using QuickSort algorithm
func QuickSort(array []int) []int {
    // Your implementation here
    return array
}

// Main method where code starts executing
func main() {
    array := []int{2, 3, 0, 4}
    sortedArray := QuickSort(array)
    fmt.Println(sortedArray)
}
```
