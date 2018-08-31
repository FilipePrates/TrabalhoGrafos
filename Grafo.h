#include <iostream>
#include <string>
#include <stack>
#include <queue>



class Grafo{
public:
  Grafo();
  ~Grafo();
  BFS();
  DFS();
  vector<int> grau();
protected:
  int m_numArestas;
  int m_numVertices;
  string m_savePath = "path do output" // editar
}
