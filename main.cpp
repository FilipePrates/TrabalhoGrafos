#include <iostream>
#include <fstream>
#include "Matriz.h"
#include "Lista.h"
#include <vector>
#include <stdlib.h>



using namespace std;

int main(){

  Lista lista = Lista("as_graph.txt");
  lista.DFS(1);
  //lista.Grau();
  //lista.vizinhos(2);
  //vector<int> x = lista.BFS(3);

  return 0;
}
