/*
 * Data.cpp
 *
 *  Created on: 22 de oct. de 2015
 *      Author: german
 */

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include "Data.h"

Data::Data(std::string archivo) {
	std::ifstream leer;
	nHiddenLayers = 0;
	nNodesPerHiddenLayer = 0;
	nInputs = 0;
	nOutputs = 0;
	leer.open(archivo.c_str());
	leer >> nHiddenLayers >> nNodesPerHiddenLayer >> nInputs >> nOutputs;
	while(!leer.eof()) {
		inputs_t inputsReader;
		outputs_t outputsReader;
		double readVar;
		for(int i = 0; i < nInputs; i++) {
			leer >> readVar;
			inputsReader.push_back(readVar);
		}
		for(int j = 0; j < nOutputs; j++) {
			leer >> readVar;
			outputsReader.push_back(readVar);
		}
		data_inputs.push_back(inputsReader);
		data_outputs.push_back(outputsReader);
	}
}
