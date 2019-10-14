
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<pair<int, int>>* getEdgeSet(unordered_map<int, vector<int>*> &graph, int &edgeCount) {

    // NUMBER OF VERTICES
    int V = graph.size();

    vector<pair<int, int>> *v = new vector<pair<int, int>>();
    
    for(int i=0; i<V; i++) {
        int n = graph[i] -> size();
        for(int j=0; j<n; j++) {
            int curr = graph[i]->at(j);
            if(curr >= i) {
                v->push_back(make_pair(i, curr));
            }
        }
    }

    edgeCount = v->size();
    return v;

}

int find(int *parent, int p) {
    int currParent = p;
    while(parent[currParent] != -1) {
        currParent = parent[currParent];
    }
    return currParent;
}

void unionn(int *parent, int p1, int p2) {
    parent[p2] = p1;
}

bool detectCycle(unordered_map<int, vector<int>*> &graph) {

    // NUMBER OF VERTICES
    int V = graph.size();

    // NUMBER OF EDGES
    int edgeCount = 0;

    // FUNCTION TO GET THE EDGE SET FROM AN ADJACENT LIST
    vector<pair<int, int>> *edges = getEdgeSet(graph, edgeCount);

    // UTILITY PARENT SET FOR CYCLE DETECTION, INITIALISED WITH -1
    int *parent = new int[V];
    for(int i=0; i<V; i++) {
        parent[i] = -1;
    }

    for(int i=0; i<edgeCount; i++) {

        // FIND THE PARENT OF BOTH VERTICES OF EDGE
        int p1 = find(parent, edges->at(i).first);
        int p2 = find(parent, edges->at(i).second);

        // IF P1 AND P2 ARE SAME THEN BOTH VERTICES LIE IN SAME SET
        // INCLUDING THIS EDGE RESULTS IN A CYCLE
        if(p1 == p2)
            return true;
        
        // ELSE IF P1 NOT EQUAL TO P2, THEN BOTH VERTICES ARE IN DIFFERENT SETS
        // INCLUDE BOTH IN SAME SET
        unionn(parent, p1, p2);
    }

    // NO CYCLE, RETURN FALSE
    return false;


}

int main() {

    /*

               0
             /  | \
            /   |   \
            1   2    3
            |   |     \
            4___5___6   7

    */
    // INITIAL INPUT FOR NUMBER OF VERTICES AND EDGES
    int V = 8, E = 8;

    // GRAPH AS ADJACENCY LIST
    unordered_map<int, vector<int> *> graph;
    for(int i=0; i<V; i++) {
        graph[i] = new vector<int>();
    }

    // INPUT FOR EDGES
    int **edges = new int*[E];
    for(int i=0; i<E; i++) {
        edges[i] = new int[2];
    }
    
    edges[0][0] = 0;edges[0][1] = 1;
    edges[1][0] = 0;edges[1][1] = 2;
    edges[2][0] = 0;edges[2][1] = 3;
    edges[3][0] = 1;edges[3][1] = 4;
    edges[4][0] = 4;edges[4][1] = 5;
    edges[5][0] = 2;edges[5][1] = 5;
    edges[6][0] = 5;edges[6][1] = 6;
    edges[7][0] = 7;edges[7][1] = 3;

    // INPUT FOR NO CYCLE IN GRAPH, MAKE E=7 ABOVE ON LINE 93
    // edges[0][0] = 0;edges[0][1] = 1;
    // edges[1][0] = 7;edges[1][1] = 3;
    // edges[2][0] = 0;edges[2][1] = 3;
    // edges[3][0] = 1;edges[3][1] = 4;
    // edges[4][0] = 4;edges[4][1] = 5;
    // edges[5][0] = 2;edges[5][1] = 5;
    // edges[6][0] = 5;edges[6][1] = 6;

    //FORMING THE ADJACENCY LIST
    for(int i=0; i<E; i++) {
        graph[edges[i][1]] -> push_back(edges[i][0]);
        graph[edges[i][0]] -> push_back(edges[i][1]);
    }

    // IF CYCLE EXISTS RETURNS TRUE
    bool isCycle = detectCycle(graph);
    
    if(isCycle) 
        cout << "There is a cycle in the graph\n";
    else
        cout << "No cycle in the graph\n";

}