#include "Lista.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

Lista::Lista(string path){
    ifstream myFile;
    myFile.open(path);
    if(!myFile){
      cout << "Location not Found";
    }
    myFile >> m_numVertices;
    m_pLista = new ListInfo*[m_numVertices+1]();   //Passa pelo espaco que alocou e preenche tudo com 0
    m_numArestas = 0;
    string s;
    while(getline(myFile, s)){
      if(s.empty() == false){
        istringstream tmp(s);                         //Leitura de Arquivo
        int v0 ,vf;
        tmp >> v0 >> vf;
        this->addAresta(v0, vf);
        this->addAresta(vf, v0);
        m_numArestas++;
      }
    //  cout << "sair do loop1" << endl;
    }
    //cout << "sair do loop2" << endl;

    ofstream myOut;
    myOut.open (m_savePath + "/info.txt");
    myOut << "numero vertices:" << m_numVertices << endl;
    myOut << "numero arestas:" << m_numArestas << endl;
    myOut.close();



}

void Lista::addAresta(int v0, int vf){
  ListInfo* vizinho = new ListInfo;                     //Nao precisa adicionar no m_pLista[vf] , porque chama o addAresta 2 vezes na leitura
  vizinho->vertice = vf;


  if (m_pLista[v0] != NULL) m_pLista[v0]->pPrev = vizinho;    //se vertice v0 tem alguma aresta,
  vizinho->pNext = m_pLista[v0];
  vizinho->pPrev = NULL;
  this->m_pLista[v0] = vizinho;

}

vector<int> Lista::vizinhos(int v){
  vector<int> vizinhos;
  ListInfo* pCrawl = new ListInfo;
  pCrawl = m_pLista[v+1];
  while(pCrawl != NULL){
    vizinhos.push_back(pCrawl->vertice);
    pCrawl = pCrawl->pNext;
  }
  return vizinhos;
}

vector<int> Lista::BFS(int raiz) {

//	clock_t begin = clock();

	int s = raiz-1;
	// Initialize vectors and queue
	vector<bool> visitado(m_numVertices,0);
	vector<int> pai(m_numVertices,-1);
	vector<int> nivel(m_numVertices,-1);
	vector<int> explorado;
	queue<int> fila;

	//Mark src as visitado and add it to the queue
	visitado[s] = 1;
	nivel[s] = 0;
	fila.push(s);

	cout << endl<< "BFS(" << raiz << ") Running..." << endl;

	while(!fila.empty()){
		int v = fila.front();
		fila.pop();
    vector<int> w = vizinhos(v);
    for(int i = 0;i< w.size();i++){
      if(visitado[w[i]] == 0) {
        visitado[w[i]] == 1;
        pai[w[i]] == v;
        fila.push(w[i]);
      }
    }
    explorado.push_back(v);
  }
	return explorado;
}


void Lista::Grau(){
  vector<int> vetorGrau = {0,10000000,0};
  int count = 0;
  ListInfo* aux = new ListInfo;
  int avg = 0;
  //cout << "test" << endl;
  for (int i=1;i<m_numVertices;i++){
    //cout << "test2" << endl;
    aux = m_pLista[i]->pNext;
    while(aux != NULL){
      //cout << "test3" << endl;
      aux = aux->pNext;
      count++;

    }
    //cout << "test4" << endl;
    avg = avg + count;
    if (count > vetorGrau[0]) {vetorGrau[0] = count+1;}
    if (count < vetorGrau[1]) {vetorGrau[1] = count+1;}
    count = 0;
  }
  cout << "test5" << endl;
  ofstream myOut;
  myOut.open (m_savePath + "/grau.txt");
  myOut << "GrauMax: " << vetorGrau[0] << endl;
  myOut << "GrauMin:" << vetorGrau[1] << endl;
  myOut << "GrauMedio: " << (avg/m_numVertices)+1 << endl;
  myOut << "GrauMediana: " << vetorGrau[3] << endl;
  myOut.close();
}

Lista::~Lista(){
    ListInfo* aux;
    for(int i=1;i<=m_numVertices;i++){
        for(ListInfo* neigh = m_pLista[i]; neigh != NULL;){
          aux = neigh;
          neigh=neigh->pNext;
          delete aux;
          }
    }
  delete[] m_pLista;
}
