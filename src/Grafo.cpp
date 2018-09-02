#include "Grafo.h"
#include <vector>
#include <queue>

using namespace std;

Grafo::Grafo()
{

}

Grafo::~Grafo()
{

}

vector<int> Grafo::BFS(int raiz) {

//	clock_t begin = clock();

	int src = raiz-1;
	// Initialize vectors and queue
	vector<bool> visitado(m_numVertices,0);
	vector<int> pai(m_numVertices,-1);
	vector<int> nivel(m_numVertices,-1);
	vector<int> explorado;
	queue<int> fila;

	//Mark src as visitado and add it to the queue
	visitado[src] = 1;
	nivel[src] = 0;
	fila.push(src);

	cout << endl<< "BFS(" << raiz << ") Running..." << endl;

	while(!fila.empty()) {
		//Dequeue a vertex from queue and print it
		int s = fila.front();
	//	cout << "Vertex " << s+1 << " explorado." << endl;
		fila.pop();

		if (true) {                                  // IF eh usa Lista de Adjacencia
			// Adjency list
      ListInfo** m_pLista = getLista();
			ListInfo* pCrawl = m_pLista[s];
	        while (pCrawl!=NULL) {
	      		if(visitado[pCrawl->vertice] == 0) {
	//				cout << "Vertex " << pCrawl->dest+1 << " discovered." << endl;
	      			visitado[pCrawl->vertice] = 1;
	      			pai[pCrawl->vertice] = s;
	      			nivel[pCrawl->vertice]=nivel[s]+1;
	      			fila.push(pCrawl->vertice);
	      		}
		        pCrawl = pCrawl->pNext;
		    }
		} else {                                   //else eh uma Matriz de adjacencia
		// 	//Adjency matrix
		// 	for(int i=0;i<m_numVertices;i++) {
		// 		if(m_Matriz[s][i] == 1 && visitado[i] == 0) {
		// 		      //cout << "Vertex " << i+1 << " discovered." << endl;
		// 			visitado[i] = 1;
		// 			pai[i] = s;
	  //     			nivel[i]=nivel[s]+1;
		// 			fila.push(i);
		// 		}
		// 	}
		 }
	}

	//for (int i=9;i<50;i=i+10) cout << "pai of " << i+1 << " = " << pai[i]+1 << "; " << "nivel " << nivel[i] << endl;

//	clock_t	end = clock();
//	double elapsed_time = double(end-begin)/CLOCKS_PER_SEC;

	//cout << "-------------------" << endl << "Elapsed time: " << elapsed_time << "s" << endl;

	return explorado;
}
