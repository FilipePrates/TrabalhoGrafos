#ifndef LISTA_H_
#define LISTA_H_

#include "Grafo.h"
#include <string>
#include <vector>


struct ListInfo{
    int vertice;
    ListInfo *pNext, *pPrev;
};

class Lista : public Grafo{
    public:
        Lista(std::string path);
        ~Lista();
        void Grau();
        int partition(int *a, int m, int n);
        int quicksort(int *a, int m, int n);
    protected:
        ListInfo** m_pLista;
        void addAresta(int v0,int vf);
        std::string m_path;


};
#endif
