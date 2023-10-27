import java.util.Scanner;

public class LinearSearch {

    public static int linearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Example Usage
        int[] exampleArray = {10, 5, 7, 2, 8, 4};
        int targetElement = 7;

        int result = linearSearch(exampleArray, targetElement);

        if (result != -1) {
            System.out.println("Element " + targetElement + " found at index " + result);
        } else {
            System.out.println("Element " + targetElement + " not found");
        }

        // Additional Test Cases
        int[] testArray1 = {1, 2, 3, 4, 5};
        int target1 = 3;
        int result1 = linearSearch(testArray1, target1);
        System.out.println("Test Case 1: Element " + target1 + " found at index " + result1);

        int[] testArray2 = {11, 22, 33, 44, 55};
        int target2 = 66;
        int result2 = linearSearch(testArray2, target2);
        System.out.println("Test Case 2: Element " + target2 + " not found");

        // Custom Input
        System.out.print("Enter the length of the array: ");
        int length = scanner.nextInt();
        int[] customArray = new int[length];

        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < length; i++) {
            customArray[i] = scanner.nextInt();
        }

        System.out.print("Enter the element to search for: ");
        int targetElementCustom = scanner.nextInt();

        int resultCustom = linearSearch(customArray, targetElementCustom);

        if (resultCustom != -1) {
            System.out.println("Element " + targetElementCustom + " found at index " + resultCustom);
        } else {
            System.out.println("Element " + targetElementCustom + " not found");
        }
    }
}

/*
Example Usage:
Element 7 found at index 2
Test Case 1: Element 3 found at index 2
Test Case 2: Element 66 not found

CUSTOM EXAMPLE: 

Enter the length of the array: 5
Enter the elements of the array:
1 3 5 7 9
Enter the element to search for: 5
Element 5 found at index 2


 */






