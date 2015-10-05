/*
 * Neuron.cpp
 *
 *  Created on: 15 de ago. de 2015
 *      Author: Germán Gómez
 */
#include <numeric>
#include <algorithm>    // std::generate
#include "Neuron.h"
#include "math.h"

Neuron::Neuron(int inputs) {
  // TODO Auto-generated constructor stub
  outputNeuron = 1;
  outputNeuronDerivate=0;
  weights.resize(inputs,0);
  deltaValue=0;
}
double Neuron::getOutNeuron(){
  return outputNeuron;
}
double Neuron::getOutNeuronDerivate(){
  return outputNeuronDerivate;
}
double Neuron::getDeltaValue(){
  return deltaValue;
}

void Neuron::initializeNeuron(){
  std::generate(weights.begin(), weights.end(), math::RandomNumber);
}

void Neuron::setLoadOutput(double setOutputNeuron){
	outputNeuron = setOutputNeuron;
}

void Neuron::setLoadInputs(std::vector<double> inputsValues){
	outputNeuron = std::inner_product(weights.begin(), weights.end(), inputsValues.begin(), 0.0);
	outputNeuron = math::binary_sigmoidal(outputNeuron);
	outputNeuronDerivate = math::binary_sigmoidal_derivative(outputNeuron);
}

void Neuron::updateOfWeights(std::vector<double> Weights){

}
