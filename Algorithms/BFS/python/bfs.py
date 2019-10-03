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


def bfs(startValue, targetValue, graphToSearch):
	if (startValue not in graphToSearch.vertices):
		raise ValueError("The starting vertex is not in specified graph.")
	
	queue = [[startValue, [startValue]]]

	while (len(queue) > 0):
		currentValue,currentPath = queue.pop(0)
		currentVertex = graphToSearch.vertices[currentValue]

		for vertex in currentVertex.edges:
			if vertex.value == targetValue:
				return currentPath + [targetValue]
			else:
				queue.append([vertex.value, currentPath + [vertex.value]])


	return None








