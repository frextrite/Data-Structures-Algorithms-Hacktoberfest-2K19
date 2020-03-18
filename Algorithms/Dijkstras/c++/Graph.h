#include "PQueue.h"
#include <iostream>
#include <string>;
using namespace std;

using namespace std; class Graph {

	class Edge;

	class Vertex {
	public:
		char label;
		Vertex *next;
		Edge *edgeList;
		int distance;
		Vertex(char c) {
			label = c;
		}
	};
	class Edge {
	public:
		Vertex *to;
		Edge *next;
		int weight;
		Edge(Vertex *v, int w) {
			to = v;
			weight = w;
			next = 0;
		}
	};

	Vertex *vertList;
	void destr_helper(Vertex *vert) {

		if (vert) {
			destr_helper(vert);
			delete vert;
		}

	}
	~Graph() {

		destr_helper(vertList);

	}
public:
	Graph() {
		vertList = 0;
	}
	void add_vertex(char c) {

		//create new vertex, push to front of graph's vertList
		//	for the project, we don't need to check whether it exists already
		Vertex *vert = new Vertex(c);
		vert->next = vertList;
		vertList = vert;

	}
	void add_edge(char f, char t, int weight) {

		Vertex *node_a = 0, *node_b = 0;

		//look for the two vertices we're going to connect
		//	again, we're going to presume that the vertices exist
		for (Vertex *temp = vertList; temp; temp = temp->next) {
			if (temp->label == f)
				node_a = temp;
			if (temp->label == t)
				node_b = temp;
		}

		//create the edge from node_a to node_b and push to the front of node_a's edgelist
		Edge *edge_a = new Edge(node_b, weight);
		edge_a->next = node_a->edgeList;
		node_a->edgeList = edge_a;

		//do the converse because the edges will be double-sided
		Edge *edge_b = new Edge(node_a, weight);
		edge_b->next = node_b->edgeList;
		node_b->edgeList = edge_b;
	}

	//displays every vertex on the graph
	void display() {

		for (Vertex *vert = vertList; vert; vert = vert->next) {
			cout << "\t" << vert->label << " -> ";
			if (vert->edgeList) {
				cout << vert->edgeList->to->label << " (" << vert->edgeList->weight;
				for (Edge *edge = vert->edgeList->next; edge; edge = edge->next) {

					cout << "), " << edge->to->label << " (" << edge->weight;

				}
			}

			cout << ")" << endl;

		}

	}

	//the actual Dijkstra's Algorithm
	void traverse(char start_c) {

		//create priority queue
		PQueue *pq = new PQueue();

		//iterate through vertices to add them to the queue
		for (Vertex *vert = vertList; vert; vert = vert->next)
			//if this vertex's label is the one we want, push it to the queue with priority 0 so it's at the front
			if (vert->label == start_c)
				pq->push(start_c, 0);
			//otherwise push it with some massive priority, like 1000, so it's at the very back of the list
			else
				pq->push(vert->label, 1000);

		//peek first
		while (pq->peek()) {

			//going to print the current state of the queue with each vertex's current shortest distance
			cout << "\tEnqueued: ";
			pq->display();

			//pop the next node and the vertex that it stands for
			Node *node = pq->pop();
			Vertex *current = search_vertex(node->label);
			int distance = node->priority;	//the total distance traveled to the node

			//print the shortest distance from start node to this node
			display_node(node, start_c);
			
			delete node;	//don't forget to delete; we have everything we need now (the vertex and total distance traveled)

			//for each neighbor of this vertex (iterating through its edgelist)
			for (Edge *e = current->edgeList; e; e = e->next) {

				Vertex *neighbor = e->to;

				//if this node is no longer in consideration (it has already been popped), continue
				if (!pq->search_node(neighbor->label))
					continue;
			
				//calculate distance from neighbor to starting point by adding distance between start->current and current->start
				int new_priority = distance + e->weight;
				int current_priority = pq->get_priority(neighbor->label);

				//if this distance is shorter than the current, then set shortest distance to new distance
				if (new_priority < current_priority) {
					cout << "\t\t Updated Vertex " << neighbor->label << "'s shortest distance from " << current_priority << " to " << new_priority << endl;
					pq->set_priority(neighbor->label, new_priority);	//set new distance from start to neighbor
					pq->set_previous(neighbor->label, current->label);	//set neighbor's previous to current vertex

				}
				//otherwise don't change its priority
				else
					cout << "\t\tKept " << neighbor->label << "'s shortest distance; " << new_priority << " is not farther than " << current_priority << endl;
			
			}

			//print new line for clarity
			cout << endl;

		}

	}

	//finds vertex in graph that has label 'c'
	Vertex *search_vertex(char c) {

		//iterate through graph's vertlist
		for (Vertex *temp = vertList; temp; temp = temp->next)
			if (temp->label == c)
				return temp;

		//return 0 if not found
		return 0;
	}


	//explains shortest distance from node labeled start_c to node n
	void display_node(Node *n, char start_c) {

		int distance = n->priority;
		char prev = n->prev_char;
		cout << "\tShortest distance from " << start_c << " to " << n->label << " is " << distance;
		if (prev)
			cout << " from previous vertex " << prev << endl;
		else
			cout << " with no previous vertex" << endl;
		cout << "\t\t Popped Vertex " << n->label << " from the queue" << endl;

	}
};