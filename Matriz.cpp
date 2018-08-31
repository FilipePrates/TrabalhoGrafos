#include <Matriz.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Matriz::Matriz(string path){
  ifstream MyFile;
  myFile.open(path)
  if(!myFile){
    cout << "Location not Found";
  }
  myFile >> m_numVertices;
  m_Matriz = vector <vector<int>> m_Matriz(m_numVertices, vector<int>(m_numVertices);
  m_numArestas = 0;
  string s;
  while(getLine(myFile, s)){
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
  myOutput.open(m_savePath + ".txt");
  myOutput << "numero vertices:" << m_numVertices << endl;
  myOutput << "numero arestas:" << m_numArestas << endl;
}

void Matriz::AddAresta(int v0, int vf){
      m_Matriz[v0][vf] == 1;
}

void Matriz::~Matriz(){
    delete[] m_Matriz;
}
