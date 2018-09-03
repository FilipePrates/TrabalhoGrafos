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


  ifstream myFile;
  myFile.open(path);
  if(!myFile){
    cout << "Location not Found";
  }
  myFile >> m_numVertices;

  ofstream myOut;
  myOut.open ("output/info.txt");
  myOut << "Mnumero vertices:" << m_numVertices << endl;


  m_Matriz = new bool*[m_numVertices]();
  for (int i=0;i<m_numVertices;i++){
    m_Matriz[i] = new bool[m_numVertices]();
  }

  for (int i = 0; i < m_numVertices; i++){
    for (int j = 0; j < m_numVertices; j++){
      //  if ((i%10 and j%10) == 0){cout<<"test"<<i<<j<<endl;};
      m_Matriz[i][j] = false;
    }
  }


  m_numArestas = 0;
  string s;
  // while(getline(myFile, s)){
  while(getline(myFile, s)){
    if(s.empty() == false){
      istringstream tmp(s);                         //Leitura de Arquivo
      int v0 ,vf;
      tmp >> v0 >> vf;
      m_Matriz[v0][vf] = true;
      m_Matriz[vf][v0] = true;
      // this->addAresta(v0, vf);
      // this->addAresta(vf, v0);
      m_numArestas++;
    }
  }
  cout << "sair do loop2" << endl;

  //ofstream myOut;
  //myOut.open ("output/info.txt");
  //myOut << "Mnumero vertices:" << m_numVertices << endl;
  myOut << "Mnumero arestas:" << m_numArestas << endl;
  myOut.close();

}
void Matriz::addAresta(int v0, int vf){
      m_Matriz[v0][vf] = true;
}

std::vector<int> Matriz::Grau(string path)
{
  // ifstream myFile;
  // myFile.open(path);
  // if(!myFile){
  //   cout << "Location not Found";
  // }
  // myFile >> m_numVertices;


  int aux2 = 0;
  vector<int> vetorGrau = {0,10000000,0};
  for(int i=0;i < m_numVertices ;i++){
    for(int j=0;j < m_numVertices ;j++){
      if (m_Matriz[i][j] = true){aux2++;}
    }
    if (aux2 > vetorGrau[0]) {vetorGrau[0] = aux2;}
    aux2 = 0;
  }
  ofstream myOut;
  myOut.open ("output/grau.txt");
  myOut << "GrauMax: " << vetorGrau[0] << endl;


  return vetorGrau;
}
//     if (vetorVertices[i].verticesVizinhos.size() < vetorGrau[1]){
//       vetorGrau[1] = vetorVertices[i].verticesVizinhos.size();
//     }
//     vetorGrau[2] += vetorVertices[i].verticesVizinhos.size();
//   }
//   return vetorGrau;
// }

Matriz::~Matriz(){
  for(int i=0;i<m_numVertices;i++){
         delete[] m_Matriz[i];
  }
  delete[] m_Matriz;
}
