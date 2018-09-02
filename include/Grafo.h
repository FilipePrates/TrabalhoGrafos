#ifndef GRAFO_H_
#define GRAFO_H_
#include <iostream>
#include <string>
#include <vector>
#include <queue>


class Grafo{
    public:
      Grafo();
      ~Grafo();
      int m_numArestas;
      int m_numVertices;
      vector<int> BFS();
    //  int getVert() {return m_numVertices;};
    protected:
      std::string m_savePath = "output"; // editar
};

#endif
