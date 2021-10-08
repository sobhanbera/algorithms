import java.util.Scanner;
public class factorial {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int factorial = 1;
        System.out.println("enter the number you want factorial of");
        int n = sc.nextInt();

        for(int i = 1;i <= n; i++){
            factorial = i*factorial;
        }

        System.out.println(factorial);
    }
}
