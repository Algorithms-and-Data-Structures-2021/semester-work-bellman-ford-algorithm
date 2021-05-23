
#include <vector>
#include <iostream>
#include "Bellman-Ford-algorithm.hpp"

// файл с определениями

namespace itis {

  Graph* createGraph(int V, int E, std::vector<Edge> edges){
    auto* graph = new Graph;
    graph->V_ = V;
    graph->E_ = E;
    graph->edges_ = edges;

    return graph;
  }

  void BellmanFord(Graph* graph, int src){
    int V = graph->V_;
    int E = graph->E_;
    std::vector<int> dist(static_cast<unsigned long>(V));

    //Заполнение расстояний до вершин бесконечностью
    for(int i = 0; i < V; i++){
      dist[i] = INT_MAX;
    }
    dist[src] = 0; //расстояние до начальной вершины нулево//

    //Стадия фаз. Релаксация ребер.
    for(int i = 0; i<V-1; i++){
      for(int j = 0; j<E; j++){
        int srcV = graph->edges_.at(j).scr_;
        int destV = graph->edges_.at(j).dest_;
        int edgeWeight = graph->edges_.at(j).weight_;

        if(dist[static_cast<unsigned long>(srcV)] != INT_MAX &&
            dist[static_cast<unsigned long>(destV)] > dist[static_cast<unsigned long>(srcV)] + edgeWeight){
          dist[static_cast<unsigned long>(destV)] = dist[static_cast<unsigned long>(srcV)] + edgeWeight;
        }
      }
    }

    //Проверка на наличие отрицательных циклов. Выполнить (V_-1)+1 шаг, если произойдет релаксация, то есть отрицательный цикл.
    for(int i = 0; i<E; i++){
      int srcV = graph->edges_.at(i).scr_;
      int destV = graph->edges_.at(i).dest_;
      int edgeWeight = graph->edges_.at(i).weight_;

      if(dist[static_cast<unsigned long>(srcV)] != INT_MAX &&
         dist[static_cast<unsigned long>(destV)] > dist[static_cast<unsigned long>(srcV)] + edgeWeight){
        std::cout << "There is a negative cycle in this graph. Bad. Very bad..." << std::endl;
        return;
      }


    }
  }
  Edge::Edge(int scr, int dest, int weight) : scr_(scr), dest_(dest), weight_(weight){}

}  // namespace itis