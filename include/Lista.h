#include "Grafo.h"
#include <string>


struct ListInfo{
    int vertice;
    ListInfo *pNext, *pPrev;
};

class Lista : public Grafo{
    public:
        Lista(std::string path);
        ~Lista();
    protected:
        ListInfo** m_pLista;
        void addAresta(int v0,int vf);


};
