#include <iostream>
#include "Matriz.h"
#include "Lista.h"



using namespace std;

int main(){
  delete[] m_Matriz;

  //Lista lista = Lista("as_graph.txt");
  Matriz matriz = Matriz("as_graph.txt");
  return 0;
  delete[] m_Matriz;
}
