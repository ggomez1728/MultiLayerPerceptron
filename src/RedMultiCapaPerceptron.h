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
#include "PrintInfo.h"
using namespace std;
class RedMultiCapaPerceptron {
  PrintInfo printinfo;
  int numCapas;
  //learning rate
  float learn_rate;
  float momentum;
  //umbral
  float threshold;
  int epochs;
  float errorTotal;
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
  void imprimirError(vector<float> errores);


};

#endif /* REDMULTILABELPERCEPTRON_H_ */
