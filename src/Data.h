/*
 * Data.h
 *
 *  Created on: 22 de oct. de 2015
 *      Author: german
 */
#include "alias.h"
#ifndef DATA_H_
#define DATA_H_

class Data {
public:
	int nHiddenLayers, nNodesPerHiddenLayer, nInputs, nOutputs;
	training_inputs_t data_inputs;
	training_outputs_t data_outputs;
	Data(std::string archivo);
};

#endif /* DATA_H_ */
