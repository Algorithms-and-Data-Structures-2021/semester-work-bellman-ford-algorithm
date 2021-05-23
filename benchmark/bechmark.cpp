#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <chrono>
#include <vector>

#include "Bellman-Ford-algorithm.hpp"

using namespace std;
using namespace itis;

static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main() {

  const auto path = string(kDatasetPath);
  const auto output_path = string(kProjectPath) + "/benchmark/result.csv";

  auto output_file1 = ofstream(output_path);
  output_file1.close();

  vector<string> folders = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10"};
  vector<string> files = {"100","250", "500","750", "1000","2500", "5000", "7500", "10000","25000","50000","75000","100000"};
  vector<Edge> edges;
  vector<int> vertexes;
  int V, E;
  for (const string& file : files) {
    for (string folder : folders) {
      for (int i = 1; i < 11; i++) {
        auto input_file = ifstream(path + "/" + folder + "/" + file + ".csv");
        auto time_diff_heap_sort = chrono::nanoseconds::zero();
        cout << (path + "/" + folder + "/" + file) << endl;

        if (input_file) {
          input_file >> V;
          input_file >> E;
          int mass[3];
          for (int i = 0; i < E; i++) {
            for (int i = 0; i < 3; ++i) {
              input_file >> mass[i];
            }
            edges.push_back(*new Edge(mass[0], mass[1], mass[2]));
          }
          Graph *graph = createGraph(V,E,edges);

          const auto time_point_before_heap_sort = chrono::high_resolution_clock::now();
          BellmanFord(graph, 1);
          const auto time_point_after_heap_sort = chrono::high_resolution_clock::now();
          time_diff_heap_sort += time_point_after_heap_sort - time_point_before_heap_sort;
          edges.clear();
          delete graph;
        }
        input_file.close();

        const auto time_elapsed_ns_heap_sort = chrono::duration_cast<chrono::nanoseconds>(time_diff_heap_sort).count();
        cout << time_elapsed_ns_heap_sort << endl;

        auto output_file = fstream(output_path, ios::app);
        output_file << time_elapsed_ns_heap_sort << endl;
        output_file.close();
      }
    }
  }
  return 0;
}