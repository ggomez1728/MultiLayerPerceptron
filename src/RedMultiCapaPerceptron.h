/*
 * redMultiLabelPerceptron.h
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */
#include "Capa.h"

#ifndef REDMULTILABELPERCEPTRON_H_
#define REDMULTILABELPERCEPTRON_H_
#include <vector>
#include "Caso.h"
using namespace std;
class RedMultiCapaPerceptron {
  int numCapas;
  vector<Capa> capaVector;
  vector<float> ultimaActivacion;
  void calcularError();
  void backPropagation();
  void AjustarPesos();
  void FeedForward(vector<float> entradas);
public:
  vector<Caso> *dataTrain;
  RedMultiCapaPerceptron(int capas, int entradas, int salidas, int ocultas);
  void inicializarPesos();
  void activar();
  //void entrenar(vector<Caso> datosEntrenamiento);
};

#endif /* REDMULTILABELPERCEPTRON_H_ */
