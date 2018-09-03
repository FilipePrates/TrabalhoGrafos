#include <iostream>
#include <fstream>
#include "Matriz.h"
#include "Lista.h"
#include <vector>
#include <stdlib.h>



using namespace std;

int main(){
  Matriz matriz = Matriz("as_graph.txt");
  matriz.Grau();
  //Lista lista = Lista("dblp.txt");
  //lista.DFS(1);
  //lista.Grau();
  //lista.vizinhos(2);
  //vector<int> x = lista.BFS(3);
  system("pause");
  return 0;
}
