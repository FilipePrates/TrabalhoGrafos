#include <iostream>
#include <string>



class Grafo{
    public:
      Grafo();
      virtual ~Grafo();
      int m_numArestas;
      int m_numVertices;
      int getVert() {return m_numVertices;};
    protected:
      std::string m_savePath = "output"; // editar
};
