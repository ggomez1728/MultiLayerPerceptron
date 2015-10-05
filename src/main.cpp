//============================================================================
// Name        : PerceptronMultiCapa.cpp
// Author      : German Gomez
// Version     :
// Copyright   : intensivo
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <vector>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//#include "cargar.h"
using namespace std;
#include "RedMultiCapaPerceptron.h"
#include "Data.h"
#include "Case.h"
int main() {
  vector<Case> dataTrain;
  srand (time(NULL));
  Data data;
  string key;
  dataTrain=data.leerData("data_train.txt");
  RedMultiCapaPerceptron RNA(data.getCapasRNA(),data.getEntradasRNA(),data.getOcultasRNA(),data.getSalidasRNA());
  RNA.setData(&dataTrain);
inicializar:
  cout<<"(1) Inicializar Conexiones Aleatoriamente \n(2) Cargar Conexiones Sinápticas \n(x) Salir \n >";
  cin>>key;
  if (key=="1"){
	//inicializacion mediante modelo aleatorio
	RNA.randomWeights();
	//mostrar pesos iniciales
	cout<<"Conexiones Inicializadas Aleatoriamente"<<endl;
  }
  else if(key =="2"){
	//inicializacion mediante archivo de los pesos o conexiones
    cout<<"Conexiones Inicializadas desde Archivo"<<endl;
  }
  else if(key =="x"){
    goto finPrograma;
  }
  else goto inicializar;
Acciones:
  cout<<"(1) Entrenar Perceptron \n(2) Ejecutar Perceptron \n(3) Meter Ruido \n(x) Salir \n >";
  cin>>key;
  if(key=="1"){
	  RNA.trainingNeuralNetwork();
  }
  else if(key=="2"){

  }
  else if(key=="3"){

  }
  else if(key=="x"){
    goto finPrograma;
  }
  else goto Acciones;

	cout << "!!!Perceptron MultiCapa!!!" << endl; // prints !!!Hello World!!!
finPrograma:
  cout<<"Saliendo...";
	return 0;
}
