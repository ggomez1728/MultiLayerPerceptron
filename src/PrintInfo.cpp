/*
 * PrintInfo.cpp
 *
 *  Created on: 1 de oct. de 2015
 *      Author: german
 */

#include "PrintInfo.h"

void PrintInfo::printInOut(vector<float> entradas, vector<float> salidas){
  vector<float>::iterator valores;
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

void PrintInfo::printModel(vector<Capa> MLP){
  //impresion de pesos del modelo
  cout << "Impresion de pesos del sistema:" << endl;
  for(int noCapa = 0; noCapa < MLP.size(); noCapa++){
	cout << "Capa(" << noCapa <<")" << endl;
	for(int noNeurona = 0; noNeurona < MLP[noCapa].Neuronas.size(); noNeurona++){
	  cout << "        Neurona(" << noNeurona << ")= " ;
	  for(int noPeso = 0; noPeso < MLP[noCapa].Neuronas[noNeurona].pesos.size(); noPeso++){
		cout << MLP[noCapa].Neuronas[noNeurona].pesos[noPeso] << " ";
	  }
	  if(MLP[noCapa].Neuronas[noNeurona].esBias) cout << "(bias)";
	  cout <<  ">>>>" << MLP[noCapa].Neuronas[noNeurona].salida << endl;
	}
  }
}

