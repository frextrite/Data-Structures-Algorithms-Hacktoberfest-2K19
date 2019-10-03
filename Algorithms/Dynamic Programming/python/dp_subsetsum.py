#!/usr/bin/env python3

def subsum(array, goal: int) -> bool:
    # True as empty list has sum = 0
    if goal == 0:
        return True
    n = len(array)
    # Columns = 1 + goal
    # Rows = 1 + n
    dp = [[False for i in range (1 + goal)] for j in range(1 + n)]
    # dp[i][j] => True if there is a subset of array[0:j] with sum = i
    for i in range(1 + n):
        # base case: goal = 0 => True
        dp[i][0] = True
        # 1 <= j <= goal
        for j in range(1, 1 + goal):
            if j < array[i - 1]:
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - array[i - 1]]
    return dp[n][goal]

array = [1,2,3,4]
print(array)
goal = int(input('n: '))
print(subsum(array, goal))
