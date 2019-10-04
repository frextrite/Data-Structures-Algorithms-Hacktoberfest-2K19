def printBoard(board):
    num=len(board)
    for i in range(num):
        for j in range(num):
            print(board[i][j],end=' ')
        print()

def isValid(board,row,col):
    num=len(board)

    for i in range(col):
        if board[row][i]:
            return False
    i=row
    j=col
    while i>=0 and j>=0:
        if board[i][j]:
            return False
        i-=1
        j-=1

    i=row
    j=col
    while j>=0 and i< num:
        if board[i][j]:
            return False
        i+=1
        j-=1
    
    return True

def solveNQueen(board,col):
    num=len(board)

    if col>=num:
        return True

    for i in range(num):
        if isValid(board,i,col):
            board[i][col] = 1
            if solveNQueen(board,col+1):
                return True
            board[i][col]=0

    return False

def checkSolution(num):
    board=[]
    for i in range(num):
        temp=[]
        for j in range(num):
            temp.append(0)
        board.append(temp)
    if not(solveNQueen(board,0)):
        print("Solution does not exist")
        return False
    printBoard(board)
    return True

print("Enter board dimension (Row num): ",end=' ')
checkSolution(int(input()))