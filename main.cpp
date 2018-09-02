#include <iostream>
#include "Matriz.h"
#include "Lista.h"



using namespace std;

int main(){

  Lista lista = Lista("new 2.txt");
  lista.Grau();
  //Matriz matriz = Matriz("as_graph.txt");
  //matriz.Grau("as_graph.txt");

  return 0;
}
