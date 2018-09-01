#include "Matriz.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <new>
#include <vector>

using namespace std;

Matriz::Matriz(string path){
  cout << "antes" << endl;
  //int1bit m_Matriz[m_numVertices][m_numVertices];
  //vector<vector<int1bit>> m_Matriz[m_numVertices][m_numVertices];
  // int1bit **m_Matriz = new int1bit *[m_numVertices];
  // for (int i = 0; i < m_numVertices; i++){
  //   m_Matriz[i] = new int1bit[m_numVertices];
  // }
  ifstream myFile;
  myFile.open(path);
  if(!myFile){
    cout << "Location not Found";
  }
  myFile >> m_numVertices;

  m_Matriz = new bool*[m_numVertices];
  for (int i=0;i<m_numVertices;i++){
    m_Matriz[i] = new bool[m_numVertices];
  }

  for (int i = 0; i < m_numVertices; i++){
    for (int j = 0; j < m_numVertices; j++){
    //  if ((i%10 and j%10) == 0){cout<<"test"<<i<<j<<endl;};
      m_Matriz[i][j] = false;
    }
  }

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
      cout << m_numArestas << endl;}
    }
  }
  //cout << "sair do loop" << endl;
  ofstream myOutput;
  myOutput.open(m_savePath + "/info.txt");
  myOutput << "Mnumero vertices:" << m_numVertices << endl;
  myOutput << "Mnumero arestas:" << m_numArestas << endl;

}
void Matriz::addAresta(int v0, int vf){
      m_Matriz[v0][vf] = true;
}

Matriz::~Matriz(){
  for(int i=0;i<m_numVertices;i++){
         delete[] m_Matriz[i];
  }
  delete[] m_Matriz;
}
