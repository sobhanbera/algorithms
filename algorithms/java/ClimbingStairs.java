class Solution {
    public int climbStairs(int n) {
        // Create an array to store the number of ways to climb each stair.
        int[] dp = new int[n + 1];

        // There is one way to climb 0 stairs (no steps).
        dp[0] = 1;

        // There is one way to climb 1 stair (take 1 step).
        dp[1] = 1;

        // Calculate the number of ways to climb each stair from 2 to n.
        for (int i = 2; i <= n; i++) {
            // The number of ways to reach the current stair is the sum of
            // the ways to reach the previous two stairs.
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // The final value in dp array (dp[n]) contains the answer.
        return dp[n];
    }
}
