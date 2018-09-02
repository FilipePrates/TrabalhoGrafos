#ifndef LISTA_H_
#define LISTA_H_

#include "Grafo.h"
#include <string>
#include <vector>



class Lista : public Grafo{
    public:
        Lista(std::string path);
        ~Lista();
        void Grau();
        //ListInfo** getLista();

    protected:
        ListInfo** m_pLista;
        void addAresta(int v0,int vf);
        std::string m_path;


};
#endif
