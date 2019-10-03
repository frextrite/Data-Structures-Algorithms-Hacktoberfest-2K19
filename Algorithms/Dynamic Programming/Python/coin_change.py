#!/usr/bin/env python3

def coinChange(coins, amount):
    if amount < 0:
        return -1
    dp = [(1 + amount) for i in range(1 + amount)]
    dp[0] = 0
    for i in range(1, 1 + amount):
        for coin in coins:
            if coin > i: break
            dp[i] = min(dp[i], 1 + dp[i - coin])
    if dp[amount] > amount:
        return -1
    return dp[amount]

if __name__ == '__main__':
    coins = input('Coins: ')
    coins = list(map(int, coins.split()))
    for i in range(3):
        amount = int(input('Amount: '))
        print(coinChange(coins, amount))
