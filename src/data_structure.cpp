#include "bits/stdc++.h" // INT_MAX
#include <vector>
#include "data_structure.hpp"

// файл с определениями

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

  Graph* createGraph(int V, int E){
    auto* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new std::vector<Edge>(static_cast<unsigned long>(E));
    return graph;
  }

  void BellmanFord(Graph* graph, int src){
    int V = graph->V;
    int E = graph->E;
    std::vector<int> dist(static_cast<unsigned long>(V));

    //Заполнение расстояний до вершин бесконечностью
    for(int i = 0; i < V; i++){
      dist[i] = INT_MAX;
    }
    dist[src] = 0; //расстояние до начальной вершины нулево//

    //Стадия фаз. Релаксация ребер.
    for(int i = 0; i<V-1; i++){
      for(int j = 0; j<E; j++){
        int srcV = graph->edge->at(j).src;
        int destV = graph->edge->at(j).dest;
        int edgeWeight = graph->edge->at(j).weight;

        if(dist[static_cast<unsigned long>(srcV)] != INT_MAX &&
            dist[static_cast<unsigned long>(destV)] > dist[static_cast<unsigned long>(srcV)] + edgeWeight){
          dist[static_cast<unsigned long>(destV)] = dist[static_cast<unsigned long>(srcV)] + edgeWeight;
        }
      }
    }

    //Проверка на наличие отрицательных циклов. Выполнить (V-1)+1 шаг, если произойдет релаксация, то есть отрицательный цикл.
    for(int i = 0; i<E; i++){
      int srcV = graph->edge->at(i).src;
      int destV = graph->edge->at(i).dest;
      int edgeWeight = graph->edge->at(i).weight;

      if(dist[static_cast<unsigned long>(srcV)] != INT_MAX &&
         dist[static_cast<unsigned long>(destV)] > dist[static_cast<unsigned long>(srcV)] + edgeWeight){
        std::cout << "There is a negative cycle in this graph. Bad. Very bad..." << std::endl;
        return;
      }


    }
  }
}  // namespace itis