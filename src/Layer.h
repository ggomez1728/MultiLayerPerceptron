/*
 * Capa.h
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */
#include <vector>

#include "Neuron.h"
#ifndef CAPA_H_
#define CAPA_H_
class Layer {
public:
  std::vector<Neuron> Neurons;
  Layer(int NumberOfNeurons,  int InputsForNeuron);
  Neuron operator[](int neuronSelect);
  void initializeLayer();
  void functionInitializeNeuron (Neuron neuronSelect);
  std::vector<double> calcularErrorCapa(std::vector<double> salidaEsperada);
  std::vector<double> cargarEntrada(std::vector<double> entradas, bool multiEntrada);
  void loadImputsForOutputLayer(std::vector<double> entradas);
  void loadImputsForInputLayer(std::vector<double> entradas);
  void loadImputsForHiddenLayer(std::vector<double> entradas);

  std::vector<double> ActivarCapa();
};

#endif /* CAPA_H_ */
