#include <Grafo.h>

Grafo::Grafo()
{

}
vector<int> Grafo::grau()
	{
		vector<int> vetorGrau = {0,10000000,0};
		for(int i=0;i <= vetorVertices.size() - 1;i++){
			if (vetorVertices[i].vetorVizinhos.size() > vetorGrau[0]){
				vetorGrau[0] = vetorVertices[i].vetorVizinhos.size();
			}
			if (vetorVertices[i].vetorVizinhos.size() < vetorGrau[1]){
				vetorGrau[1] = vetorVertices[i].vetorVizinhos.size();
			}
			vetorGrau[2] += vetorVertices[i].vetorVizinhos.size();
		}
		return vetorGrau;
	}
