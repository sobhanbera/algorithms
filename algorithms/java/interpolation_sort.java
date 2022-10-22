public class InterpolationSearch {

    public static int search(int[] numbers, int find) {
        int low = 0;
        int high = numbers.length - 1;

        while (low <= high && find >= numbers[low] && find <= numbers[high]) {
            float result = low + (((float) (find - numbers[low]) / (float) (numbers[high] - numbers[low])) * (float) (high - low));
            int position = (int) result;

            if (find == numbers[position])
                return position;
            else if (find < numbers[position])
                high = position - 1;
            else
                low = position + 1;
        }

        return -1;
    }
}