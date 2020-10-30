# Coin Change Leetcode (322)
# You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

# You may assume that you have an infinite number of each kind of coin.

def coinChange(coins, amount: int):
    
    n = len(coins)
    
    t = [[0]*(amount+1) for _ in range(n+1)]
    
    for i in range(n+1):
        
        for j in range(amount+1):
            
            if j == 0:
                
                t[i][j] = 0

            # Initializing base conditions i.e. when amount is 0
                
            if i == 0:
                
                t[i][j] = float('inf') - 1

            # Initializing base conditions i.e. when length of coins array in consideration is 0
                
            if i == 1 and j != 0:
                
                if j % coins[0] == 0:
            
                    t[i][j] = j // coins[0]
            
                else:
            
                    t[i][j] = float('inf') - 1
                
            else:
                
                if coins[i-1] <= j:
            
                    t[i][j] = min(1+t[i][j-coins[i-1]],t[i-1][j])
                else:
                
                    t[i][j] = t[i-1][j]
                
    if t[n][amount] != float('inf'):
        return t[n][amount]
    
    return -1

coins = [1,2,5]
amount = 11
print(coinChange(coins,amount))
        