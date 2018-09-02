#ifndef GRAFO_H_
#define GRAFO_H_
#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct ListInfo{
    int vertice;
    ListInfo *pNext, *pPrev;
};

class Grafo{
    public:
      Grafo();
      ~Grafo();
      int m_numArestas;
      int m_numVertices;
      std::vector<int> BFS(int raiz);
    //  int getVert() {return m_numVertices;};
    protected:
      std::string m_savePath = "output"; // editar
      virtual ListInfo** getLista();
};

#endif
