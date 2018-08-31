#include "Matriz.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <new>

using namespace std;

Matriz::Matriz(string path){
  ifstream myFile;
  myFile.open(path);
  if(!myFile){
    cout << "Location not Found";
  }
  myFile >> m_numVertices;

  bool **m_Matriz = new bool*[m_numVertices];
  for (int i = 0; i < m_numVertices; ++i){
    m_Matriz[i] = new bool[m_numVertices];
  }

  for (int i = 0; i < m_numVertices; ++i){
    for (int j = 0; j < m_numVertices; ++j){
      m_Matriz[i][j] = 0;
    }
  }


  //m_Matriz = new MatrizInfo*[m_numVertices+1]();   //Passa pelo espaco que alocou e preenche tudo com 0
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

// void iniciaMatriz(int m_numVertices){
//   int linhas = m_numVertices;
//   int colunas = m_numVertices;
//   m_Matriz = new int*[m_numVertices];
//   for (int i = 0; i < linhas; i++){
//     m_Matriz[i] = new int[colunas];
//   }
//
//   for (int i = 0; i < linhas; i++){
//     for (int j = 0; j < colunas; j++){
//       m_Matriz[i][j] = 0;
//     }
//   }
//
// }

void Matriz::addAresta(int v0, int vf){
      m_Matriz[v0][vf] = true;
}

Matriz::~Matriz(){
    delete[] m_Matriz;
}
