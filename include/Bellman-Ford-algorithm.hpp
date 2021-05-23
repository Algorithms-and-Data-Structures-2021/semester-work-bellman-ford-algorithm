#pragma once

#include <vector>

namespace itis {

  struct Edge {
    Edge(int scr, int dest, int weight);
    int scr_;
    int dest_;
    int weight_;
  };

  struct Graph {
    int V_;
    int E_;

    std::vector<Edge> edges_;
  };

  Graph* createGraph(int V, int E, std::vector<Edge> edges);

  void BellmanFord(Graph* graph, int src);
}