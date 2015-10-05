/*
 * Neurona.h

 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */
#ifndef NEURON_H_
#define NEURON_H_

#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Neuron {
public:
  std::vector<double> weights;
  double outputNeuron;
  double outputNeuronDerivate;
  double deltaValue;

  Neuron(int inputs);
  double getOutNeuron();
  double getOutNeuronDerivate();
  double getDeltaValue();

  void setLoadInputs(std::vector<double> inputs);
  void setLoadOutput(double outputNeuron);

  void updateOfWeights(std::vector<double> deltas);
  void initializeNeuron();

};

#endif /* NEURON_H_ */
