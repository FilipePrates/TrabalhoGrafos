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
				bool** m_Matriz;
    protected:
				//void iniciaMatriz(int m_numVertices);
        void addAresta(int v0,int vf);


};
