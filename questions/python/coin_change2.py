# Coin Change 2 Leetcode (518)
# You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

def change(amount, coins):
    
    t = [[0]*(amount+1) for _ in range(len(coins)+1)]
    
    # j indicates amount and i indicates len of coins array in consideration
    # if j i.e. amount is 0, number of combinations is 1
    
    for i in range(len(t)):
        
        t[i][0] = 1
        
    for i in range(1,len(t)):
        
        for j in range(1,len(t[0])):
            
            if coins[i-1] <= j:
            
                t[i][j] = t[i][j-coins[i-1]] + t[i-1][j]
            else:
                
                t[i][j] = t[i-1][j]
                    
    return t[len(coins)][amount]

amount = 5
coins = [1, 2, 5]
print(change(amount,coins))