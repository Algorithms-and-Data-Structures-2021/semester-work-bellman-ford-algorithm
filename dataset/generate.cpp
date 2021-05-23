#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <random>
#include <chrono>

using namespace std;

int main() {

  /* Пояснение для следующей строчки: если у вас нет папок, то необходимо создать перед запуском
  Далее вставляем в строчку путь к файлу, например C:\Users\user\CLionProjects\semester-work-bellman-ford-algorithm\dataset\data\01\ .csv файл
  Номер файла необходимо указать самому, например 100.csv  */
  auto output_stream = ofstream("",ios::ios_base::trunc);
  const auto seed = chrono::system_clock::now().time_since_epoch().count();
  auto engine = mt19937(seed);
  auto weight = uniform_int_distribution(-100, 100);
  int E = 100;  // это количество ребер, тут тоже нужно изменять самому, т.е если файл 100.csv то E = 100;
  float con = 0.4;
  float noc = 0.6;
  int V = (E * con);
  auto vertex = uniform_int_distribution(0, V - 1);
  int quantityOfE = E;
  int nocQuantityOfE = (noc * quantityOfE);
  if (output_stream) {
    output_stream << V << " ";
    output_stream << quantityOfE;
    output_stream << endl;
    for (int i = 0; i < V;i++) {
      output_stream << i << " " << (i + 1) << " " << weight(engine)<< endl;
    }

    for (int counter = 0; counter < nocQuantityOfE;counter++) {
      output_stream << vertex(engine) << " " << vertex(engine) << " " << weight(engine) << endl;
    }
  }

  return 0;
}