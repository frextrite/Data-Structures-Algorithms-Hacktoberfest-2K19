/* Дан неориентированный граф. Требуется найти все мосты в нём.

Входные данные

Первая строка входного файла содержит два натуральных числа n и m — количества вершин
 и рёбер графа соответственно (1 ≤ n ≤ 20 000, 1 ≤ m ≤ 200 000).

Следующие m строк содержат описание рёбер по одному на строке.
 Ребро номер i описывается двумя натуральными числами b_i, e_i — номерами концов ребра
 (1 ≤ b_i, e_i ≤ n).

Выходные данные

Первая строка выходного файла должна содержать одно натуральное число b — количество мостов
 в заданном графе. На следующей строке выведите b целых чисел — номера рёбер,
 которые являются мостами, в возрастающем порядке. Рёбра нумеруются с единицы в том порядке,
 в котором они заданы во входном файле.
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>

class Graph {
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

  virtual bool IsMultiEdge(const Vertex &start, const Vertex &finish) const = 0;

  virtual size_t GetEdgeId(const Vertex &start, const Vertex &finish) const = 0;

  virtual void AddEdge(const Vertex &start, const Vertex &finish, size_t id) = 0;

  virtual std::vector<Vertex> GetAllNeighbors(const Vertex &vertex) const = 0;

 protected:
  std::map<std::pair<Vertex, Vertex>, size_t> edges_;
  std::map<std::pair<Vertex, Vertex>, bool> is_multi_edge_;
  size_t vertex_count_;
  size_t edge_count_;
  bool is_directed_;
};

class GraphAdjList : public Graph {
 private:
  std::vector<std::vector<Vertex>> adj_list_;

 public:
  explicit GraphAdjList(size_t vertex_count, bool is_directed)
      : Graph(vertex_count, is_directed),
        adj_list_(vertex_count + 1) {}

  void AddEdge(const Vertex &start, const Vertex &finish, size_t id) override {
    edges_[std::minmax(start, finish)] = id;
    is_multi_edge_[std::minmax(start, finish)] = false;
    adj_list_[start].push_back(finish);
    if (!is_directed_) {
      adj_list_[finish].push_back(start);
    }
    ++edge_count_;
  }

  void AddMultiEdge(const Vertex &start, const Vertex &finish) {
    is_multi_edge_[std::minmax(start, finish)] = true;
  }

  size_t GetEdgeId(const Vertex &start, const Vertex &finish) const override {
    if (edges_.find(std::minmax(start, finish)) != edges_.end()) {
      return edges_.at(std::minmax(start, finish));
    }
    return 0;
  }

  bool IsMultiEdge(const Vertex &start, const Vertex &finish) const override {
    return is_multi_edge_.at(std::minmax(start, finish));
  }

  std::vector<Vertex> GetAllNeighbors(const Vertex &vertex) const override {
    return adj_list_[vertex];
  }
};

namespace GraphProcessing {

  struct BridgeStatus {
    std::vector<bool> visited;
    std::vector<size_t> time_in;
    std::vector<size_t> time_up;
    size_t time;
    std::set<size_t> id_bridges;

    explicit BridgeStatus(size_t vertex_count) :
        visited(vertex_count + 1, false),
        time_in(vertex_count + 1, 0),
        time_up(vertex_count + 1, 0),
        time(0) {}
  };

  void DFS(const Graph &graph, const Graph::Vertex &vertex,
           BridgeStatus &status, size_t parent = -1) {
    status.time_in[vertex] = status.time_up[vertex] = ++status.time;
    status.visited[vertex] = true;
    for (Graph::Vertex u : graph.GetAllNeighbors(vertex)) {
      if (u == parent) {
        continue;
      }
      if (status.visited[u]) {
        status.time_up[vertex] = std::min(status.time_up[vertex], status.time_in[u]);
      } else {
        DFS(graph, u, status, vertex);
        status.time_up[vertex] = std::min(status.time_up[vertex], status.time_up[u]);
        if (status.time_up[u] > status.time_in[vertex]) {
          if (!graph.IsMultiEdge(vertex, u)) {
            status.id_bridges.insert(graph.GetEdgeId(vertex, u));
          }
        }
      }
    }
  }

  std::set<size_t> GetBridges(const Graph &graph) {
    const size_t vertex_count = graph.GetVertexCount();
    BridgeStatus status = BridgeStatus(vertex_count);
    for (Graph::Vertex vertex = 1; vertex < vertex_count + 1; ++vertex) {
      if (!status.visited[vertex]) {
        DFS(graph, vertex, status);
      }
    }
    return status.id_bridges;
  }
}

int main() {
  size_t n, m;

  std::cin >> n >> m;
  GraphAdjList graph_adj_list = GraphAdjList(n, false);

  for (int i = 1; i < m + 1; ++i) {
    Graph::Vertex start, finish;
    std::cin >> start >> finish;
    if (graph_adj_list.GetEdgeId(start, finish) != 0) {
      graph_adj_list.AddMultiEdge(start, finish);
    } else {
      graph_adj_list.AddEdge(start, finish, i);
    }
  }

  auto bridges = GraphProcessing::GetBridges(graph_adj_list);
  std::cout << bridges.size() << std::endl;
  for (auto id_bridge : bridges) {
    std::cout << id_bridge << ' ';
  }

  return 0;
}