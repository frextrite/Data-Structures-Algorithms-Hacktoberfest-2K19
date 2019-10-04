/*BFS and DFS algorithms written for Javascript (ES6)*/

class Vertex {
	constructor(value) {
		this.value = value;
		this.connections = new Set();
	}

	addConnection(vertexToConnect) {
		if (!this.connections.has(vertexToConnect)) {
			this.connections.add(vertexToConnect);
		} else {
			console.log("Connection already exists.");
		}
	}
}

class Graph {
	constructor() {
		this.vertices = {};
	}

	addVertex(valueToAdd) {
		if (!this.vertices[valueToAdd]) {
			this.vertices[valueToAdd] = new Vertex(valueToAdd);
		} else {
			console.log("Vertex is already in graph.");
		}
	}

	connectVertices(value1,value2) {
		if (!(this.vertices[value1] && this.vertices[value2])) {
			console.log("Both vertices must be in graph.");
		} else {
			this.vertices[value1].addConnection(this.vertices[value2]);
			this.vertices[value2].addConnection(this.vertices[value1]);
		}
	}

}

/* Breadth First Search (BFS) graph search function.
Time complexity O(Vertices+Connections). Space complexity O(Vertices).*/

const bfs = (start, target, graph) => {
	if (!(graph.vertices[start])){
		console.log("Starting vertex must be in given Graph.");
		return null;
	}

	let queue = [[start,[start]]];
	let visited = new Set([start]);

	while (queue.length > 0) {
		let current = queue.shift();
		let currentVal = current[0];
		let currentPath = current[1];

		visited.add(graph.vertices[currentVal]);

		for (const vertex of graph.vertices[currentVal].connections) {
			if (!visited.has(vertex)) {

				let path = currentPath.slice()
				path.push(vertex.value);

				if (vertex.value === target) {
					return path;
				} else {
					queue.push([vertex.value,path]);
				}
			}

		}

	}
	return null;
}

const dfs = (start, target, graph) => {
	if (!(graph.vertices[start])){
		console.log("Starting vertex must be in given Graph.");
		return null;
	}

	let stack = [[start,[start]]];
	let visited = new Set([start]);

	while (stack.length > 0) {
		let current = stack.pop();
		let currentVal = current[0];
		let currentPath = current[1];

		visited.add(graph.vertices[currentVal]);

		for (const vertex of graph.vertices[currentVal].connections) {
			if (!visited.has(vertex)) {

				let path = currentPath.slice()
				path.push(vertex.value);

				if (vertex.value === target) {
					return path;
				} else {
					stack.push([vertex.value,path]);
				}
			}

		}

	}
	return null;
}


function testBfsDfs() {

	let graph = new Graph();
	graph.addVertex(1);
	graph.addVertex(2);
	graph.addVertex(3);
	graph.addVertex(4);
	graph.addVertex(5);
	graph.connectVertices(1,2);
	graph.connectVertices(1,3);
	graph.connectVertices(2,4);
	graph.connectVertices(3,5);
	console.log(dfs(1,5,graph));
	console.log(bfs(1,5,graph));
	console.log(dfs(1,4,graph));
	console.log(bfs(1,4,graph));

}

testBfsDfs();