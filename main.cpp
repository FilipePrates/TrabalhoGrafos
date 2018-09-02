#include <iostream>
#include <fstream>
#include "Matriz.h"
#include "Lista.h"
#include <vector>



using namespace std;

int main(){

  Lista lista = Lista("as_graph.txt");
  lista.Grau();
  vector<int> x = lista.BFS(1);

  for(int i = 0;i < 100;i++){
    cout << x[i] << endl;
  }
  //Matriz matriz = Matriz("as_graph.txt");
  //matriz.Grau("as_graph.txt");

  return 0;
}
