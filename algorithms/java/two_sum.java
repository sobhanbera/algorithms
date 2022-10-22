import java.util.*;

class two_sum {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] arr = new int[5];

        for (int i = 0; i < n; ++i) {
            arr[i] = scan.nextInt();
            System.out.println(arr[i]);
        }

        int target = scan.nextInt();
        // int ts[] = twoSum(arr, target);

        System.out.println("Two Sum: " + Arrays.toString(twoSum(arr, target)));
    }

    public static int[] twoSum(int[] num, int target) {
        for (int i = 0; i < num.length - 1; i++)
            for (int j = i + 1; j < num.length; j++)
                if (num[i] + num[j] == target)
                    return new int[] {
                        i,
                        j
                    };
        return new int[] {};
    }
}