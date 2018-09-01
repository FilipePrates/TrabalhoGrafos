#ifndef MATRIZ_H_
#define MATRIZ_H_

#include "Grafo.h"
#include <string>


// struct int1bit{
// 	int x:1;
// }int1bit;
//

class Matriz : public Grafo{
    public:
        Matriz(std::string path);
        ~Matriz();
    protected:
				//void iniciaMatriz(int m_numVertices);
        void addAresta(int v0,int vf);
				bool** m_Matriz;


};

#endif
