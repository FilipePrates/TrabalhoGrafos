#ifndef MATRIZ_H_
#define MATRIZ_H_

#include "Grafo.h"
#include <string>
#include <vector>


// struct int1bit{
// 	int x:1;
// }int1bit;
//
using namespace std;

class Matriz : public Grafo{
    public:
        Matriz(std::string path);
        ~Matriz();
        void Grau();
    protected:
				//void iniciaMatriz(int m_numVertices);
        void addAresta(int v0,int vf);
				bool** m_Matriz;
      //  vector<int> vizinhos(int v);


};

#endif
