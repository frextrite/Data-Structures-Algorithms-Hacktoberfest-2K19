#include "Graph.h"
#include <iostream>
using namespace std;

int main() {

	Graph *graph = new Graph();

	cout << "CREATED THE FOLLOWING GRAPH:" << endl;
	graph->add_vertex('A');
	graph->add_vertex('B');
	graph->add_vertex('C');
	graph->add_vertex('D');
	graph->add_edge('A', 'B', 8);
	graph->add_edge('A', 'C', 22);
	graph->add_edge('B', 'C', 7);
	graph->add_edge('B', 'D', 15);
	graph->add_edge('C', 'D', 18);
	graph->display();

	cout << "FINDING THE SHORTEST DISTANCE FROM 'A' TO EVERY OTHER NODE:" << endl;
	graph->traverse('A');

	return 0;

}