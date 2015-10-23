//============================================================================
// Name        : MPL.cpp
// Author      : German Gomez
// Version     :
// Copyright   : Ucla Developer
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <algorithm>
#include <cstdlib>
#include <ctime>        // std::time

#include "MLP.h"
#include "Trainer.h"
#include "Data.h"
#include "alias.h"
using namespace std;
#include <stdio.h>

// function generator:
double RandomNumber () { return (((double) rand() / (RAND_MAX))); }

int main() {
	cout << "!!!Multi Layer Perceptron!!!" << endl; // prints !!!Multi Layer Perceptron!!!
	std::srand ( unsigned ( std::time(0) ) );
	Data data("data_train.txt");
	MLP mlp (data.nHiddenLayers, data.nNodesPerHiddenLayer, data.nInputs, data.nOutputs);
	params_t params(mlp.getParams());
	std::generate(params.begin(), params.end(), RandomNumber); // with C function rand()
	mlp.setParams(params);
	Trainer trainer(mlp);
	trainer.training_inputs = data.data_inputs;			//load Data inputs
	trainer.training_outputs =	data.data_outputs;		//load Data outputs
	trainer.train();
	return 0;
}
