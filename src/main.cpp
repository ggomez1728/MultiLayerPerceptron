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
#include "Caso.h"
int main() {
  vector<Caso> dataTrain;
  srand (time(NULL));
  Data data;
  string la;
  dataTrain=data.leerData("data_train.txt");
  RedMultiCapaPerceptron RNA(data.getCapasRNA(),data.getEntradasRNA(),data.getOcultasRNA(),data.getSalidasRNA());
  RNA.dataTrain = &dataTrain;
inicializar:
  cout<<"(1) Inicializar Conexiones Aleatoriamente \n(2) Cargar Conexiones Sinápticas \n(x) Salir \n >";
  cin>>la;
  if (la=="1"){
	//inicializacion mediante modelo aleatorio
	RNA.inicializarPesos();
	//mostrar pesos iniciales
	cout<<"Conexiones Inicializadas Aleatoriamente"<<endl;
  }
  else if(la =="2"){
	//inicializacion mediante archivo de los pesos o conexiones
    cout<<"Conexiones Inicializadas desde Archivo"<<endl;
  }
  else if(la =="x"){
    goto finPrograma;
  }
  else goto inicializar;
Acciones:
  cout<<"(1) Entrenar Perceptron \n(2) Ejecutar Perceptron \n(3) Meter Ruido \n(x) Salir \n >";
  cin>>la;
  if(la=="1"){
	  RNA.entrenar();
  }
  else if(la=="2"){

  }
  else if(la=="3"){

  }
  else if(la=="x"){
    goto finPrograma;
  }
  else goto Acciones;

	cout << "!!!Perceptron MultiCapa!!!" << endl; // prints !!!Hello World!!!
finPrograma:
  cout<<"Saliendo...";
	return 0;
}
