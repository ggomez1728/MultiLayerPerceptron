/*
 * MLP.h
 *
 *  Created on: 11 de oct. de 2015
 *      Author: german
 */

#ifndef MLP_H_
#define MLP_H_
#include "Neuron.h"
typedef std::vector<Neuron> layer_t;
typedef std::vector<layer_t> layers_t;

class MLP {
	private:
		layers_t layers;
		int _nParams;
		void calculateNParams(int nInputNeurons, int nHiddenNeurons, int nOutputNeurons);
	public:
		outputs_layers_t  outputs_layers;
		outputs_t outputs;
		MLP(int nHiddenLayers, int nNodesPerHiddenLayer, int nInputs, int nOutputs);
		outputs_t feedForward(inputs_t inputs);
		void setParams(const params_t& params);
		int nParams();
		params_t getParams();
};

#endif /* MLP_H_ */
