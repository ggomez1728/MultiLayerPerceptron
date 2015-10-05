
/*

 * redMultiLabelPerceptron.h
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */
#define  RAND_MAX = 1;
#include "Layer.h"
#include <vector>
#include "Case.h"
#ifndef REDMULTILABELPERCEPTRON_H_
#define REDMULTILABELPERCEPTRON_H_

class RedMultiCapaPerceptron {
  int numCapas;
  //learning rate
  double learn_rate;
  double momentum;
  //umbral
  double threshold;
  int epochs;
  double errorTotal;
  void feedForward(std::vector<double> inputTest);
  void backPropagation(std::vector<double> salidas);
  void ajustarPesos();
  std::vector<Case> *dataTrain;
public:
  void setData(std::vector<Case> *dataIn);
  std::vector<Layer> layerVector;
  std::vector<double> lastActivation;
  RedMultiCapaPerceptron(int capas, int entradas, int salidas, int ocultas);
  void randomWeights();
  void trainingNeuralNetwork();
  void activar();
  void imprimirError(std::vector<double> errores);
};

#endif /* REDMULTILABELPERCEPTRON_H_ */
