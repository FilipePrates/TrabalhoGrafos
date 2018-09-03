#include <iostream>
#include <fstream>
#include "Matriz.h"
#include "Lista.h"
#include <vector>
#include <stdlib.h>



using namespace std;

int main(){

<<<<<<< HEAD
  Lista lista = Lista("as_graph.txt");
  lista.DFS(1);
  //lista.Grau();
  //lista.vizinhos(2);
  //vector<int> x = lista.BFS(3);

  // for(int i = 0;i < 100;i++){
  //   cout << x[i] << endl;
  // }
=======
  Lista lista = Lista("new 2.txt");
  //lista.vizinhos(2);
  lista.BFS(1);
  lista.Grau();
  //vector<int> x = lista.BFS(1);

  //for(int i = 0;i < 100;i++){
  //  cout << x[i] << endl;
  //}
>>>>>>> 67277b30a0ff5351efe276c145349f9f1fb2c05f
  //Matriz matriz = Matriz("as_graph.txt");
  //matriz.Grau("as_graph.txt");
  system("pause");
  return 0;
}
