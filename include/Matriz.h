#include "Grafo.h"
#include <string>
#include <new>

struct MatrizInfo{
	int **m_Matriz;
	int vertices;
};


class Matriz : public Grafo{
    public:
        Matriz(std::string path);
        ~Matriz();
    protected:
			  bool m_Matriz[m_numVertices][m_numVertices];
				void iniciaMatriz(int vertices);
        void addAresta(int v0,int vf);


};
