def isSafe(x, y, maze, sol):
	if(x>=0 and x<len(maze) and y>=0 and y<len(maze) and maze[x][y] == 1 and sol[x][y] == 0):
		return True
	return False


def ratInMaze(maze):
	sol = [[0 for i in range(len(maze))] for i in range(len(maze))]

	xMoves = [1, 0, -1, 0]
	yMoves = [0, 1, 0, -1]
	sol[0][0] = 1
	allPaths(maze, 0, 0, sol, xMoves, yMoves)


def allPaths(maze, x, y, sol, xMoves, yMoves):
	if(x == len(maze)-1 and y == len(maze)-1):
		for i in sol:
			for j in i:
				print(j, end=" ")
			print()
		print()
		sol[x][y] = 0
		return

	for i in range(len(xMoves)):
		next_x = x + xMoves[i]
		next_y = y + yMoves[i] 
		if(isSafe(next_x,next_y, maze, sol)== True):
			sol[next_x][next_y] = 1
			allPaths(maze, next_x, next_y, sol, xMoves, yMoves)
	sol[x][y] = 0
	return 


maze = [[1,0,1],
		[1,1,1],
		[1,1,1]]

ratInMaze(maze)