import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * PROBLEM STATEMENT :
 * 
 * You are given coins of different denominations and a total amount of money amount.
 * Write a function to compute the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return -1.
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * EXAMPLES :
 * 
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 */

public class CoinChange {
        public static void main(String[] args) throws IOException {
                BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

                System.out.println("\nEnter the coin denominations separated with spaces:");
                int[] coins = Arrays.stream(reader.readLine().trim().split("\\s+")).mapToInt(Integer::parseInt).toArray();

                System.out.println("\nEnter the amount:");
                int amount = Integer.parseInt(reader.readLine().trim());

                reader.close();

                System.out.println("\nMinimum " + coinChange(coins, amount) + " coins are required to make the amount.");
        }

        public static int coinChange(int[] coins, int amount) {
                int[] combinations = new int[amount + 1];

                combinations[0] = 0;

                for (int amt = 1; amt <= amount; ++amt) {
                        int minCoins = Integer.MAX_VALUE;
                        combinations[amt] = -1;
                        for (int c : coins)
                                if (c <= amt && combinations[amt - c] != -1) {
                                        minCoins = Math.min(minCoins, 1 + combinations[amt - c]);
                                        combinations[amt] = minCoins;
                                }
                }

                return combinations[amount];
        }
}
