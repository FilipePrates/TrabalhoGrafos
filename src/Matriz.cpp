#include "Matriz.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <new>

using namespace std;

Matriz::Matriz(string path){

  int1bit **m_Matriz = new int1bit*[m_numVertices];
  for (int i = 0; i < m_numVertices; i++){
    m_Matriz[i] = new int1bit[m_numVertices];
  }

  for (int i = 0; i < m_numVertices; i++){
    for (int j = 0; j < m_numVertices; j++){
      m_Matriz[i][j].x = 0;
    }
  }

  ifstream myFile;
  myFile.open(path);
  if(!myFile){
    cout << "Location not Found";
  }
  myFile >> m_numVertices;
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
  }
  ofstream myOutput;
  myOutput.open(m_savePath + "/info.txt");
  myOutput << "numero vertices:" << m_numVertices << endl;
  myOutput << "numero arestas:" << m_numArestas << endl;
}

void Matriz::addAresta(int v0, int vf){
      m_Matriz[v0][vf].x = 1;
}

Matriz::~Matriz(){
  for(int i=0;i<m_numVertices;i++){
         delete []m_Matriz[i];
  }
  delete []m_Matriz;
}
