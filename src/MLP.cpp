#include "alias.h"
#include "MLP.h"
#include <utility>      // std::move
// vector::cbegin/cend
#include <iostream>
#include <vector>


void MLP::calculateNParams(int nInputNeurons, int nHiddenNeurons, int nOutputNeurons) {
	//calculates the total of links
	int nparams_per_input_neuron = layers.front().front().nParams();
	int nparams_per_other_neuron = layers.back().back().nParams();
	int nparams_input = nparams_per_input_neuron * nInputNeurons;
	int nparams_hidden = nparams_per_other_neuron * nHiddenNeurons;
	int nparams_output = nparams_per_other_neuron * nOutputNeurons;
	_nParams = nparams_input + nparams_hidden + nparams_output;
}

MLP::MLP(int nHiddenLayers_, int nNodesPerHiddenLayer_, int nInputs_, int nOutputs_) {
	nHiddenLayers = nHiddenLayers_;
	nNodesPerHiddenLayer = nNodesPerHiddenLayer_;
	nInputs = nInputs_;
	nOutputs = nOutputs_;
	layers = layers_t(nHiddenLayers+1);
	// create input layer
	layers[0] = layer_t(nNodesPerHiddenLayer, Neuron(nInputs));
	// create each hidden layer
	for (int i = 1; i < nHiddenLayers; ++i) {
		layers[i] = layer_t(nNodesPerHiddenLayer, Neuron(nNodesPerHiddenLayer));
	}
	// create output layer
	layers[nHiddenLayers] = layer_t(nOutputs, Neuron(nNodesPerHiddenLayer));
	calculateNParams(nNodesPerHiddenLayer, (layers.size() - 2) * nNodesPerHiddenLayer, nOutputs);
}

outputs_t MLP::feedForward(inputs_t inputs) {
	outputs_layers.clear();
	for (auto& layer: layers) {   			//runs through every layer
		outputs = outputs_t(layer.size());	// outputs per layer
		for(int j = 0; j < layer.size(); ++j) {
			outputs[j] = layer[j].activate(inputs);		//fills the outputs vector
		}
		outputs_layers.push_back(outputs);
		// si no es la última capa, volver los outputs de esta capa los inputs de la siguiente capa
		if (&layer != &layers.back()) inputs = std::move(outputs);
	}
	return outputs;
}

// para asignar pesos externamente, usado por la clase entrenadora
// recibe como parametro un iterador a un vector corrido de pesos,
// pero los asigna en la forma matricial de los pesos de la red
void MLP::setParams(const params_t& params) {
	auto param_iterator = params.cbegin();
	for (auto& layer: layers) {
		for (auto& neuron: layer) {
			neuron.setParams(param_iterator); // la función recibe el iterador por referencia y lo modifica
		}
	}
}

int MLP::nParams() {
	return _nParams;
}

// operacion contraria a setParams()
params_t MLP::getParams() {
	params_t params(_nParams);
	auto param_iterator = params.begin();
	for (auto& layer: layers) {
		for (auto& neuron: layer) {
			neuron.getParams(param_iterator); // la función recibe el iterador por referencia y lo modifica
		}
	}
	return params;
}
