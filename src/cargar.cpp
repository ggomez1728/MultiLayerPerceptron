#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include "cargar.h"

dataFormat cargarData(string archivo) {
  ifstream leer;
  leer.open(archivo.c_str());
  leer >> capasRNA >> entradasRNA >> ocultasRNA >> salidasRNA;
  dataFormat dataReader;
  while(!leer.eof()) {
	Caso casoReader;
	vector<float> entradasReader;
	vector<float> salidasReader;
	float readVar;
	for(int i = 0; i < entradasRNA; i++) {
	  leer >> readVar;
	  entradasReader.push_back(readVar);
	}
	for(int j = 0; j < salidasRNA; j++) {
	  leer >> readVar;
      salidasReader.push_back(readVar);
	}
	casoReader.cargarCaso(entradasReader,salidasReader);
	dataReader.push_back(casoReader);
  }
  return dataReader;
}
