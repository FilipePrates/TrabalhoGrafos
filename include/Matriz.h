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
			  matrizInfo
        void iniciaMatriz(int vertices);
        void addAresta(int v0,int vf);


};
