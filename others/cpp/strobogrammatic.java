import java.util.Scanner;
class strobogrammatic {
    public static boolean isStrobogrammatic(char[] digits) {
        int left = 0;
        int right = digits.length - 1;

        while (left <= right) {
            char c1 = digits[left];
            char c2 = digits[right];
            if (c1 == '0' && c2 == '0' || c1 == '1' && c2 == '1' || c1 == '8' && c2 == '8' || c1 == '6' && c2 == '9' || c1 == '9' && c2 == '6') {
                left++;
                right--;
            } else {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        char[] digits = String.valueOf(num).toCharArray();

        if (isStrobogrammatic(digits)) {
            System.out.println("Strobogrammatic");
        } else {
            System.out.println("Not Strobogrammatic");
        }
    }
}
