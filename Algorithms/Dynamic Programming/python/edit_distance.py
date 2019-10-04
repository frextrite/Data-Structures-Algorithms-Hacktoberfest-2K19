#!/usr/bin/env python3

def edit_distance(s1: str, s2: str) -> int:
    n = len(s1)
    m = len(s2)
    edit = [[None for i in range(1 + m)] for j in range(1 + n)]
    for i in range(1 + m):
        edit[0][i] = i
    for i in range(1, 1 + n):
        edit[i][0] = i
        for j in range(1, 1 + m):
            replace = edit[i-1][j-1]
            insert = 1 + edit[i][j - 1]
            delete = 1 + edit[i - 1][j]
            if not (s1[i - 1] == s2[j - 1]):
                replace += 1
            edit[i][j] = min(insert, delete, replace)
    return edit[n][m]

if __name__ == '__main__':
    s1 = input('s1: ')
    s2 = input('s2: ')
    print(edit_distance(s1, s2))
