/*
 * PrintInfo.h
 *
 *  Created on: 1 de oct. de 2015
 *      Author: german
 */
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */

#include "Layer.h"
#ifndef PRINTINFO_H_
#define PRINTINFO_H_
using namespace std;

namespace printInfo {

void InputOutput(vector<double> entradas, vector<double> salidas){
  vector<double>::iterator valores;
  cout<< "CASO DE PRUEBA"<< endl;
  cout<< "   ->Entradas: ";
  for (valores = entradas.begin(); valores != entradas.end(); valores++ ){
	  cout << " " << *valores;
  }
  cout<< endl << "   ->Salidas: ";
  for (valores = salidas.begin();valores !=salidas.end(); valores++){
	  cout << " " << *valores;
  }
  cout<< endl;
}

void Model(vector<Layer> MLP){
  //impresion de pesos del modelo
  cout << "Impresion de pesos del sistema:" << endl;
  for(int noCapa = 0; noCapa < MLP.size(); noCapa++){
	cout << "Capa(" << noCapa <<")" << endl;
	for(int noNeuron = 0; noNeuron < MLP[noCapa].Neurons.size(); noNeuron++){
	  cout << "        Neurona(" << noNeuron << ")= " ;
	  for(int noPeso = 0; noPeso < MLP[noCapa].Neurons[noNeuron].weights.size(); noPeso++){
		cout << MLP[noCapa].Neurons[noNeuron].weights[noPeso] << " ";
	  }
	  cout <<  ">>>>" << MLP[noCapa].Neurons[noNeuron].getOutNeuron() << endl;
	  cout << "        Delta(" << MLP[noCapa].Neurons[noNeuron].getDeltaValue() << ")"<<endl ;
	}
  }
}
};

#endif /* PRINTINFO_H_ */


