#include <iostream>
#include <string>



class Grafo{
    public:
      Grafo();
      virtual ~Grafo();
    protected:
      int m_numArestas;
      int m_numVertices;
      std::string m_savePath = "output"; // editar
};
