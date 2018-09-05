#ifndef MATRIZ_H_
#define MATRIZ_H_

#include "Grafo.h"
#include <string>
#include <vector>


typedef struct int1bit{
	int x:1;
}int1bit;

using namespace std;

class Matriz : public Grafo{
    public:
        Matriz(std::string path);
        ~Matriz();
        void Grau();
        vector<int> vizinhos(int v);
        void Grau2();
        vector<bool> DFS(int raiz);
        vector<int> BFS(int raiz);
    protected:
				//void iniciaMatriz(int m_numVertices);
        void addAresta(int v0,int vf);
				int1bit** m_Matriz;


};

#endif
