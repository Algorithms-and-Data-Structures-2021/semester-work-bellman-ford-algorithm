#pragma once

#include <vector>

namespace itis {

  struct Edge {
    int src;
    int dest;
    int weight;
  };

  struct Graph {
    int V;
    int E;

    std::vector<Edge>* edge;
  };

  Graph* createGraph(int V, int E);

  void BellmanFord(Graph* graph, int src);
}