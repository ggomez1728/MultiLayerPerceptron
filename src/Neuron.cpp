/*
 * Neuron.cpp
 *
 *  Created on: 10 de oct. de 2015
 *      Author: german
 */
#include <iostream>
#include "Neuron.h"
#include <numeric>      // std::inner_product

Neuron::Neuron(int nInputs) {
	nInputs++; // add bias
	weights = inputs_t(nInputs);
	last_output = NULL;
}

output_t Neuron::activate(const inputs_t& inputs) {
	auto weighted_sum = std::inner_product(inputs.begin(), inputs.end(), weights.begin(), 0.0);
	weighted_sum += weights.back(); // add input for bias (weight*1)
	return (1.0 / (1.0 + exp(-weighted_sum)));
	//return last_output = transfer_function(weighted_sum);
}

// para asignar pesos externamente
void Neuron::setParams(params_t::const_iterator& param_iterator) {
	for (auto i = 0; i < weights.size(); ++i) {
		weights[i] = *param_iterator;
		++param_iterator;
	}
}

void Neuron::getParams(params_t::iterator& param_iterator) {
	for (auto weight: weights) {
		*param_iterator = weight;
		++param_iterator;
	}
}

int Neuron::nParams() {
	return weights.size();
}
