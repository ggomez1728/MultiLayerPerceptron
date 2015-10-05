/*
 * Capa.cpp
 *
 *  Created on: 15 de ago. de 2015
 *      Author: German Gomez
 */
#include "Layer.h"

#include <algorithm>    // std::generate

Layer::Layer(int NumberOfNeurons, int InputsForNeuron) {
 	Neurons.resize(NumberOfNeurons,InputsForNeuron);
}

Neuron Layer::operator [](int neuronSelect){
  return Neurons[neuronSelect];
}
void Layer::initializeLayer(){
  std::vector<Neuron>::iterator neuronSelect;
  for(neuronSelect = Neurons.begin(); neuronSelect!=Neurons.end(); neuronSelect++){
	  neuronSelect->initializeNeuron();
  }
}

std::vector<double> Layer::calcularErrorCapa(std::vector<double> salidas){
  std::vector<double> diferencial;
  diferencial = salidas;
  for(int neuronSel = 0; neuronSel < salidas.size(); neuronSel++){
	  diferencial[neuronSel] -= Neurons[neuronSel].outputNeuron;
  }
  return diferencial;
}

std::vector<double> Layer::cargarEntrada(std::vector<double> entradas, bool multiEntrada){
	std::vector<double> salidasCapa;
  int numNeuron=0;
  std::vector<Neuron>::iterator neuronSel;
  for(neuronSel = Neurons.begin(); neuronSel!=Neurons.end(); neuronSel++){
	if(multiEntrada){
	  numNeuron=0;
	  std::vector<double>::iterator mm;
      for(mm = entradas.begin(); mm != entradas.end(); mm++){
        neuronSel->outputNeuron += *mm * entradas[numNeuron];
        numNeuron++;
      }
	}
	else{
	  neuronSel->outputNeuron = entradas[numNeuron] * neuronSel->weights[0];
	  numNeuron++;
	}
	salidasCapa.push_back(neuronSel->outputNeuron);
  }
  return salidasCapa;
}

void Layer::loadImputsForInputLayer(std::vector<double> inputsTest){
  for(int neuronSelect = 0; neuronSelect < Neurons.size(); neuronSelect++){
	Neurons[neuronSelect].setLoadOutput(inputsTest[neuronSelect]);
  }
}
void Layer::loadImputsForHiddenLayer(std::vector<double> entradas){
  for(int neuronSelector = 0; neuronSelector < (Neurons.size()-1); neuronSelector++){
	  Neurons[neuronSelector].setLoadInputs(entradas);
  }
}
void Layer::loadImputsForOutputLayer(std::vector<double> entradas){
  std::vector<Neuron>::iterator neuronSel;
  for(neuronSel = Neurons.begin(); neuronSel!=Neurons.end(); neuronSel++){
	  neuronSel->setLoadInputs(entradas);
  }
}
std::vector<double> Layer::ActivarCapa(){
  std::vector<double> outputLayer(Neurons.size());
  for (int neuronSelect = 0; neuronSelect < Neurons.size(); neuronSelect++){
	  outputLayer[neuronSelect]=Neurons[neuronSelect].getOutNeuron();
  }
  return outputLayer;
}
