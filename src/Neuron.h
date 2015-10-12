/*
 * Neuron.h
 *
 *  Created on: 10 de oct. de 2015
 *      Author: German Gomez
 */

#ifndef NEURON_H_
#define NEURON_H_
#include <functional>
#include <iostream>
#include "alias.h"
#include "transferFunctions.h"

class Neuron {
	private:
	    //const transfer_function_t transfer_function = transferFunctions::sigmoid; // se puede parametrizar;
		inputs_t weights;
		output_t last_output;
	public:
		Neuron(int nInputs);
		output_t activate(const inputs_t& inputs);
		void setParams(params_t::const_iterator& param_iterator);
		void getParams(params_t::iterator& param_iterator);
		int nParams();
};

#endif /* NEURON_H_ */
