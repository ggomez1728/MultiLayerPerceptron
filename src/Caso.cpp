/*
 * Caso.cpp
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */

#include "Caso.h"

Caso::Caso() {
	// TODO Auto-generated constructor stub
}
void Caso::cargarCaso(vector<float> entradas, vector<float> salidas){
entradasCaso=entradas;
salidasCaso=salidas;
}

vector<float> Caso::getSalidasCaso(){
  return salidasCaso;
}
vector<float> Caso::getEntradasCaso(){
  return entradasCaso;
}

Caso::~Caso() {
	// TODO Auto-generated destructor stub
}
