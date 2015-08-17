/*
 * CargarData.cpp
 *
 *  Created on: 16 de ago. de 2015
 *      Author: german
 */

#include "Data.h"

Data::Data() {
  // TODO Auto-generated constructor stub
  capasRNA=0;
  entradasRNA=0;
  ocultasRNA=0;
  salidasRNA=0;
}
int Data::getCapasRNA(){
  return capasRNA;
}

int Data::getEntradasRNA(){
  return entradasRNA;
}

int Data::getOcultasRNA(){
  return ocultasRNA;
}

int Data::getSalidasRNA(){
  return salidasRNA;
}

vector<Caso> Data::leerData(string archivo){
	 ifstream leer;
	  leer.open(archivo.c_str());
	  leer >> capasRNA >> entradasRNA >> ocultasRNA >> salidasRNA;
	  vector<Caso> dataReader;
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

Data::~Data() {
	// TODO Auto-generated destructor stub
}

