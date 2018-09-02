#include <iostream>
#include "Matriz.h"
#include "Lista.h"



using namespace std;

int main(){

  Lista lista = Lista("as_graph.txt");
  lista.Grau();
  lista.BFS(1);
  //Matriz matriz = Matriz("as_graph.txt");
  //matriz.Grau("as_graph.txt");

  return 0;
}
