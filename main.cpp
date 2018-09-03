#include <iostream>
#include <fstream>
#include "Matriz.h"
#include "Lista.h"
#include <vector>
#include <stdlib.h>



using namespace std;

int main(){

  Lista lista = Lista("new 2.txt");
  //lista.vizinhos(2);
  lista.BFS(1);
  lista.Grau();
  //vector<int> x = lista.BFS(1);

  //for(int i = 0;i < 100;i++){
  //  cout << x[i] << endl;
  //}
  //Matriz matriz = Matriz("as_graph.txt");
  //matriz.Grau("as_graph.txt");
  system("pause");
  return 0;
}
