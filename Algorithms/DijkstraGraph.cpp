#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <cmath>
#define INF 1000000

using namespace std;

class Graph {
private:
	int V; // número de vértices
	list<pair<int, int> > * adj;

public:
	Graph(int V){
		this->V = V; // atribui o número de vertices
		adj = new list<pair<int, int> >[V];
	}

	// adiciona uma aresta ao grafo de v1 a  v2
	void addEdges(int v1, int v2, int custo){
		adj[v1].push_back(make_pair(v2, custo));
	}

	// algoritmo de Dijkstra
	int dijkstra(int orig, int dest){
		int dist[V];
		int visitados[V];

		// fila de prioridades de pair (distancia, vertice)
		priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

		for(int i = 0; i < V; i++){
			dist[i] = INF;
			visitados[i] = false;
		}

		dist[orig] = 0;
		pq.push(make_pair(dist[orig], orig));

		while(!pq.empty()) {
			pair<int, int> p = pq.top(); 
			int u = p.second; 
			pq.pop(); 

			// verifica se o vertice não foi expandido
			if(visitados[u] == false){
				visitados[u] = true;
				list<pair<int, int> >::iterator it;

				// percorre os vertices "v" adjacentes de "u"
				for(it = adj[u].begin(); it != adj[u].end(); it++){
					int v = it->first;
					int custo_aresta = it->second;

					if(dist[v] > (dist[u] + custo_aresta)) {
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		return dist[dest];
	}
};

int main(){
    string inputs;
    int a, b, n, e;
    getline(cin, inputs);
    istringstream input(inputs);
    //n numero de vertices 
    input >> n; 
    //e numero de arestas
    input >> e;
    // vertice origem
    input >> a;
    // vertice destino
    input >> b;

    Graph graph(n);
    int x, y, w;
    for(int i=0; i<e; i++){
        //lendo dois vertices e o peso relacionado a esta aresta
        getline(cin, inputs);
        istringstream input(inputs);
        input >> x >> y >> w;
        graph.addEdges(x, y, w);
        graph.addEdges(y, x, w);
    }
    double dB;
    dB = graph.dijkstra(a, b);
    cout << "\nSSSP: " << dB << endl;
}
