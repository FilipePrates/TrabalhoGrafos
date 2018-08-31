#include <Grafo.h>
#include <string>

using namespace std;

typedef struct
	{
	int vertexNum  :1;
	} int1bit;


class Matriz : public Grafo{
    public:
        Matriz(string path);
        ~Matriz();
    protected:
        int m_Matriz[m_numVertices][m_numVertices];
        void addAresta(int v0,int vf)


};

//put(int v, bool value){
//vArray[i][j] = value

// totalBytes = (int) ceil(m_numVertices/Bit_size) + Bit_size;
// vArray = new bitse<Bit_size>[totalBytes];

//for (i [1, m_numVertices])
//		this<-put(i,setTrue);
