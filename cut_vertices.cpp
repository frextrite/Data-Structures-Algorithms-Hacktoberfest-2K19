#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

class Graph {
 protected:
  size_t vertex_count_;
  size_t edge_count_;
  bool is_directed_;

 public:
  typedef size_t Vertex;

  explicit Graph(size_t vertex_count, bool is_directed)
      : vertex_count_(vertex_count),
        is_directed_(is_directed),
        edge_count_(0) {}

  size_t GetVertexCount() const {
    return vertex_count_;
  }

  size_t GetEdgeCount() const {
    return edge_count_;
  }

  bool IsDirected() const {
    return is_directed_;
  }

  virtual void AddEdge(const Vertex &start, const Vertex &finish) = 0;

  virtual std::vector<Vertex> GetAllNeighbors(const Vertex &vertex) const = 0;

};

class GraphAdjList : public Graph {
 private:
  std::vector<std::vector<Vertex>> adj_list_;

 public:
  explicit GraphAdjList(size_t vertex_count, bool is_directed)
      : Graph(vertex_count, is_directed),
        adj_list_(vertex_count + 1) {}

  void AddEdge(const Vertex &start, const Vertex &finish) override {
    adj_list_[start].push_back(finish);
    if (!is_directed_) {
      adj_list_[finish].push_back(start);
    }
    ++edge_count_;
  }

  std::vector<Vertex> GetAllNeighbors(const Vertex &vertex) const override {
    return adj_list_[vertex];
  }
};

namespace GraphProcessing {

  struct CutVerticesStatus {
    std::vector<bool> visited;
    std::vector<size_t> time_in;
    std::vector<size_t> time_up;
    size_t time;
    std::set<Graph::Vertex> cut_vertices;

    explicit CutVerticesStatus(size_t vertex_count)
    :   visited(vertex_count + 1, false),
        time_in(vertex_count + 1, 0),
        time_up(vertex_count + 1, 0),
        time(0) {}
  };

  void DFS(const Graph &graph, const Graph::Vertex &vertex,
           CutVerticesStatus &status, size_t parent = -1) {
    const bool is_root = (parent == -1);
    status.time_in[vertex] = status.time_up[vertex] = ++status.time;
    status.visited[vertex] = true;
    size_t children = 0;
    for (Graph::Vertex u : graph.GetAllNeighbors(vertex)) {
      if (u == parent) {
        continue;
      }
      if (status.visited[u]) {
        status.time_up[vertex] = std::min(status.time_up[vertex], status.time_in[u]);
      } else {
        DFS(graph, u, status, vertex);
        ++children;
        status.time_up[vertex] = std::min(status.time_up[vertex], status.time_up[u]);
        if (!is_root && status.time_up[u] >= status.time_in[vertex]) {
          status.cut_vertices.insert(vertex);
        }
      }
    }
    if (is_root && children >= 2) {
      status.cut_vertices.insert(vertex);
    }
  }

  std::set<Graph::Vertex> GetCutVertices(const Graph &graph) {
    const size_t vertex_count = graph.GetVertexCount();
    CutVerticesStatus status = CutVerticesStatus(vertex_count);
    for (Graph::Vertex vertex = 1; vertex < vertex_count + 1; ++vertex) {
      if (!status.visited[vertex]) {
        DFS(graph, vertex, status);
      }
    }
    return status.cut_vertices;
  }
}

int main() {
  size_t n, m;

  std::cin >> n >> m;
  GraphAdjList graph_adj_list = GraphAdjList(n, false);

  for (int i = 0; i < m; ++i) {
    Graph::Vertex start, finish;
    std::cin >> start >> finish;
    graph_adj_list.AddEdge(start, finish);
  }

  auto cut_vertices = GraphProcessing::GetCutVertices(graph_adj_list);
  std::cout << cut_vertices.size() << std::endl;
  for (auto cut_vertex : cut_vertices) {
    std::cout << cut_vertex << std::endl;
  }

  return 0;
}
