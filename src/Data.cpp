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

std::vector<Case> Data::leerData(std::string archivo){
	std::ifstream leer;
	  leer.open(archivo.c_str());
	  leer >> capasRNA >> entradasRNA >> ocultasRNA >> salidasRNA;
	  std::vector<Case> dataReader;
	  while(!leer.eof()) {
		Case casoReader;
		std::vector<double> entradasReader;
		std::vector<double> salidasReader;
		double readVar;
		for(int i = 0; i < entradasRNA; i++) {
		  leer >> readVar;
		  entradasReader.push_back(readVar);
		}
		//carga la entrada del bias
		entradasReader.push_back(1);
		for(int j = 0; j < salidasRNA; j++) {
		  leer >> readVar;
	      salidasReader.push_back(readVar);
		}
		casoReader.cargarCaso(entradasReader,salidasReader);
		dataReader.push_back(casoReader);
	  }
	  return dataReader;
}
