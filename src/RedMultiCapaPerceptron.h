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
  void calcularError();
  void backPropagation(vector<float> salidas);
  void ajustarPesos();
  void feedForward(vector<float> entradas);
public:
  vector<Capa> capaVector;
  vector<float> ultimaActivacion;
  vector<Caso> *dataTrain;
  RedMultiCapaPerceptron(int capas, int entradas, int salidas, int ocultas);
  void inicializarPesos();
  void activar();
  void entrenar();
};

#endif /* REDMULTILABELPERCEPTRON_H_ */
