public class LinearSearch {

    public static void main(String[] args) {
        int[] numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int find = 9;

        int position = search(numbers, find);
        System.out.println("Position: " + position);
    }

    private static int search(int[] numbers, int find) {
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] == find) {
                return i;
            }
        }
        return -1;
    }
}