#This is an unweighted graph. To add weights, one would have to changed Vertex.edges to a dictionary, where the keys are the vertices and the values
#are the edge weights.

class Vertex:
	def __init__(self, value):
		self.value = value
		self.edges = set()

	def addEdge(self, vertexToAdd):
		self.edges.add(vertexToAdd)

	def getEdges(self):
		return [self.edges.value for edge in self.edges]

	def getValue(self):
		return self.value

class Graph:
	def __init__(self):
		self.vertices = {}

	def addVertex(self, vertexToAdd):
		if vertexToAdd in self.vertices:
			raise ValueError("Vertex is already in the graph.")

		self.vertices[vertexToAdd] = Vertex(vertexToAdd)

	def connectVertices(self, vertexA, vertexB):
		if (vertexA not in self.vertices) or (vertexB not in self.vertices):
			raise ValueError("Both vertices given must be in the graph.")

		self.vertices[vertexA].addEdge(self.vertices[vertexB])
		self.vertices[vertexB].addEdge(self.vertices[vertexA])

	def getVertices(self):
		return self.vertices.keys()


#Breadth first search for Graph
def bfs(startValue, targetValue, graphToSearch):
	if (startValue not in graphToSearch.vertices):
		raise ValueError("The starting vertex is not in specified graph.")
	
	queue = [[startValue, [startValue]]]
	visited = set([startValue])

	while (len(queue) > 0):
		currentValue,currentPath = queue.pop(0)
		currentVertex = graphToSearch.vertices[currentValue]

		for vertex in currentVertex.edges:
			if vertex.value not in visited:
				path = currentPath + [vertex.value]
				if vertex.value == targetValue:
					return path
				else:
					queue.append([vertex.value, path])
					visited.add(vertex.value)

	return None

#Depth first search for Graph
def dfs(startValue, targetValue, graphToSearch):
	if (startValue not in graphToSearch.vertices):
		raise ValueError("The starting vertex is not in specified graph.")
	
	stack = [[startValue, [startValue]]]
	visited = set([startValue])

	while (len(stack) > 0):
		currentValue,currentPath = stack.pop()
		currentVertex = graphToSearch.vertices[currentValue]

		for vertex in currentVertex.edges:
			if vertex.value not in visited:
				path = currentPath + [vertex.value]
				if vertex.value == targetValue:
					return path
				else:
					stack.append([vertex.value, path])
					visited.add(vertex.value)

	return None

#Testing both search functions
def test_bfs_dfs():
	graph = Graph()
	for i in range(1,6):
		graph.addVertex(i)
	graph.connectVertices(1,2)
	graph.connectVertices(1,3)
	graph.connectVertices(2,4)
	graph.connectVertices(3,5)

	test_case1 = bfs(1,5,graph)
	test_case2 = dfs(1,5,graph)
	test_case3 = bfs(1,6,graph)
	test_case4 = dfs(1,6,graph)
	if test_case1 != [1,3,5]:
		return False
	if test_case2 != [1,3,5]:
		return False
	if test_case3:
		return False
	if test_case4:
		return False
	return True

print(test_bfs_dfs())










