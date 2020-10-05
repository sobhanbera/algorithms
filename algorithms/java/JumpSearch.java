public class JumpSearch {

    public static int search(int[] numbers, int find) {
        int n = numbers.length;
        int m = (int) Math.sqrt(n);

        int low;
        int high;

        for (int i = 0; i < n; i += m) {
            low = i;
            if ((low + m) < n)
                high = low + m;
            else
                high = numbers[n - 1];

            if (find >= low && find <= high) {
                for (int j = low; j <= high; j++) {
                    if (find == numbers[j]) {
                        return j;
                    }
                }
            }
        }

        return -1;
    }
}