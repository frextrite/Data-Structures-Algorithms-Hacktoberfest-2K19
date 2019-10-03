#include <iostream>
#include <vector>
#include <algorithm>

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

  virtual void Transpose() = 0;
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

  void Transpose() override {
    std::vector<std::vector<Vertex>> temp(vertex_count_ + 1);
    for (int i = 1; i < vertex_count_ + 1; ++i) {
      const size_t size = adj_list_[i].size();
      for (int j = 0; j < size; ++j) {
        temp[adj_list_[i][j]].push_back(i);
      }
    }
    adj_list_ = temp;
  }
};

namespace GraphProcessing {

  void DFS_SetOrder(const Graph &graph, const Graph::Vertex &vertex, std::vector<bool> &used,
                    std::vector<Graph::Vertex> &order) {
    used[vertex] = true;
    for (Graph::Vertex u : graph.GetAllNeighbors(vertex)) {
      if (!used[u]) {
        DFS_SetOrder(graph, u, used, order);
      }
    }
    order.push_back(vertex);
  }

  void DFS_GetSCC(const Graph &graph, const Graph::Vertex &vertex, std::vector<bool> &used,
                  std::vector<Graph::Vertex> &component) {
    used[vertex] = true;
    component.push_back(vertex);
    for (Graph::Vertex u : graph.GetAllNeighbors(vertex)) {
      if (!used[u]) {
        DFS_GetSCC(graph, u, used, component);
      }
    }
  }

  std::vector<Graph::Vertex> SetOrder(const Graph &graph) {
    const size_t size = graph.GetVertexCount() + 1;
    std::vector<bool> used(size, false);
    std::vector<Graph::Vertex> order;
    for (Graph::Vertex vertex = 1; vertex < size; ++vertex) {
      if (!used[vertex]) {
        DFS_SetOrder(graph, vertex, used, order);
      }
    }
    return {order.rbegin(), order.rend()};
  }

  std::vector<std::vector<Graph::Vertex>> GetStronglyConnectedComponents(Graph &graph) {
    const size_t size = graph.GetVertexCount() + 1;
    std::vector<bool> used(size, false);
    std::vector<Graph::Vertex> order = SetOrder(graph);
    graph.Transpose();
    std::vector<Graph::Vertex> component;
    std::vector<std::vector<Graph::Vertex>> strongly_connected_components;
    for (Graph::Vertex vertex : order) {
      if (!used[vertex]) {
        component.clear();
        DFS_GetSCC(graph, vertex, used, component);
        strongly_connected_components.emplace_back(component);
      }
    }
    return strongly_connected_components;
  }
}

int main() {
  size_t n, m;
  std::cin >> n >> m;

  GraphAdjList graph_adj_list = GraphAdjList(n, true);
  for (int i = 0; i < m; ++i) {
    size_t first, second;
    std::cin >> first >> second;
    graph_adj_list.AddEdge(first, second);
  }

  auto scc_vertices = GraphProcessing::GetStronglyConnectedComponents(graph_adj_list);

  return 0;
}
