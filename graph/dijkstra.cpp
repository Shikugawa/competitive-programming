#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD 1000000009
#define INF 1000000

using namespace std;

using ll = long long int;

class Node
{
public:
  Node(size_t _id) : id(_id)
  {}

  void SetCost(double&& _cost)
  {
    cost = std::move(_cost);
  }

  void SetCost(double _cost)
  {
    cost = _cost;
  }

  double GetCost() { return cost; }

private:
  size_t id;
  double cost;
};

class UndirectedGraph
{
public:
  using Vertex = unsigned int;
  using Edge = std::pair<Vertex, double>;

  UndirectedGraph(size_t _max_graph_size) : max_graph_size(_max_graph_size)
  {
    graph.resize(max_graph_size);
    nodes.resize(max_graph_size * (max_graph_size - 1));
  }

  ~UndirectedGraph()
  {
    for_each(nodes.begin(), nodes.end(), [](auto p){ delete p; });
  }

  void AddNode()
  {
    auto node = new Node(node_id);
    graph[node_id] = {};
    nodes[node_id] = node;
    ++node_id;
  }

  void AddEdge(Vertex from, Vertex to, double value)
  {
    AddArc(from, to, value);
    AddArc(to, from, value);
  }

  size_t GetGraphSize() const { return max_graph_size; }

  Node GetNode(size_t i) { return *nodes[i]; }

  vector<Edge> GetEdges(size_t i) const {
    return graph[i]; 
  }

  void SetCost(size_t node_id, double cost)
  {
    nodes[node_id]->SetCost(cost);
  }

private:
  void AddArc(Vertex from, Vertex to, double value)
  {
    graph[from].emplace_back(make_pair(to, value));
  }

  vector<vector<Edge>> graph;
  vector<Node*> nodes;
  size_t node_id;
  size_t max_graph_size;
};

template <typename CharT, typename Traits>
basic_ostream<CharT, Traits>& operator<<(basic_ostream<CharT, Traits>& os, const UndirectedGraph& sg)
{
  for(size_t i = 0; i < sg.GetGraphSize(); ++i)
  {
    os << i << " -> {";
    for(const auto& p: sg.GetEdges(i))
    {
      os << "{" << p.first << ", " << p.second << "},";
    }
    os << "}" << endl;
  }
  return os;
}

vector<size_t> dijkstra(UndirectedGraph& ug, size_t goal_node_id)
{
  bool flag = false;
  ug.SetCost(0, 0.0);
  for (size_t i = 1; i < ug.GetGraphSize(); ++i)
  {
    ug.SetCost(i, INF);
  }
  vector<size_t> list;
  vector<int> check(ug.GetGraphSize(), 0);
  check[0] = 1;
  list.emplace_back(0);
  size_t pointer = 0;
  while (!flag)
  {
    auto current_node_cost = ug.GetNode(pointer).GetCost();
    auto edges = ug.GetEdges(pointer);
    size_t min_node_id;
    double min_node_cost = INF;
    for (const auto edge : edges)
    {
      auto [adjacent_node_id, edge_weight] = edge;
      auto node = ug.GetNode(adjacent_node_id);
      auto new_node_cost = min(node.GetCost(), edge_weight + current_node_cost);
      ug.SetCost(adjacent_node_id, new_node_cost);
      if (new_node_cost < min_node_cost && check[adjacent_node_id] != 1) {
        min_node_id = adjacent_node_id;
        min_node_cost = new_node_cost;
      }
    }
    if (min_node_id == goal_node_id) flag = true;
    list.emplace_back(min_node_id);
    check[min_node_id] = 1;
    pointer = min_node_id;
  }
  return list;
}

int main()
{
  UndirectedGraph ud(6);
  for(size_t i = 0; i < 6; ++i)
  {
    ud.AddNode();
  }
  ud.AddEdge(0, 1, 2);
  ud.AddEdge(0, 2, 10);
  ud.AddEdge(1, 3, 7);
  ud.AddEdge(1, 2, 2);
  ud.AddEdge(2, 3, 4);
  ud.AddEdge(1, 4, 8);
  ud.AddEdge(2, 4, 5);
  ud.AddEdge(3, 5, 3);
  ud.AddEdge(4, 5, 1);
  auto result = dijkstra(ud, 5);
  for (size_t i = 0; i < result.size(); ++i) {
    cout << result[i] << endl;
  }
}