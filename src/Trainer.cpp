/*
 * Trainer.cpp
 *
 *  Created on: 11 de oct. de 2015
 *      Author: german
 */

#include "Trainer.h"
#include <algorithm>    // std::transform
#include <iostream>

double Trainer::costFunctionPerCase(int _case) {
	auto& train_in = training_inputs[_case];
	auto& train_out = training_outputs[_case];
	outputs_t outputs = nn.feedForward(train_in);
	// error por cada neurona de salida: diferencia entre la salida obtenida y la esperada
	outputs_t errors(train_out.size());
	std::transform(train_out.begin(), train_out.end(), outputs.begin(), errors.begin(), std::minus<output_t>());
	// error local del caso: acumular cada una de las diferencias
	return std::accumulate(errors.begin(), errors.end(), 0.0);
}

// global error, media cuadrática del error de todo el conjunto de entrenamiento
double Trainer::costFunction() {
	double acum_error = 0;
	std::cout<<"entradas"<<training_inputs.size()<<std::endl;
	for (int i = 0; i < training_inputs.size()-1; i++) {
		double local_error = costFunctionPerCase(i);
		params_t gradients = costFunctionPrime(i);				//Calculo de deltas por caso
		nn.setParams(updateWeight(i));
		acum_error += local_error * local_error;
	}
	return 0.5 * acum_error;
}

params_t Trainer::updateWeight(int _case){
	params_t params = nn.getParams();
	auto& target = training_outputs[_case];
	auto deltas_layer = nn.deltas_layers.begin();
	auto delta = deltas_layer->begin();
	for (int neuron = 0; neuron < nn.nNodesPerHiddenLayer; neuron++)
	{																						//first layer
		for (int param = 0; param < nn.nInputs; param++)
		{
			params[(param + (neuron*(nn.nInputs + 1)))] -= (*delta) * target[param];
		}
		params[(((neuron + 1)*(nn.nInputs + 1)))] = *(delta);								//calculo bias
		delta++;
	}
	deltas_layer++;
	delta = deltas_layer->begin();
	auto layerSelector = nn.outputs_layers.begin();
	auto neuronSelector = layerSelector->begin();
	for (int neuron = 0; neuron < nn.nOutputs; neuron++)
	{																						//first hidden
		for (int param = 0; param < nn.nNodesPerHiddenLayer; param++)
		{
			params[(param + (neuron*(nn.nNodesPerHiddenLayer + 1)))] -= (*delta) * (*neuronSelector);
		}
		params[(((neuron + 1)*(nn.nInputs + 1)))] = *(delta);								//calculo bias
		neuronSelector++;
	}

	return params;
}

/*
 *
 */

// funcion derivada de la funcion costo
// debe retornar todos los gradientes de los pesos de toda la red
params_t Trainer::costFunctionPrime(int _case) {
	// use nn.outputs and start the back propagation
	auto& target = training_outputs[_case];
	params_t params = nn.getParams();
	params_t paramsPrime(nn.nParams());
	int selector;
	double sum;
	nn.deltas_layers = nn.outputs_layers;				//delta of layer output
	auto deltas_layer = nn.deltas_layers.rbegin();
	selector = 0;
	std::cout<<"capas>>>"<< nn.deltas_layers.size()<< std::endl;
	for(auto delta = deltas_layer->begin(); delta != deltas_layer->end(); delta++){
		*delta = -(*delta)*(1-(*delta))*(target[selector]-(*delta));
		std::cout << *delta<< std::endl;
		selector++;
	}
	auto deltaOut = deltas_layer->begin();		//Asigna el puntero de la capa de salida
	deltas_layer++;										//delta of layer last output
	int beginElement = nn.nParams()-(nn.nOutputs * (nn.nNodesPerHiddenLayer+1));
	int endElement;
	endElement = beginElement + (nn.nNodesPerHiddenLayer+1);
	auto deltaNext = deltaOut;

	for(auto delta = deltas_layer->begin(); delta != deltas_layer->end(); delta++){	//calculo de delta por neurona
		sum=0;
		for(int element = beginElement; element < endElement;  deltaNext++){
			sum += (params[beginElement])*(*deltaNext);
			element += (nn.nNodesPerHiddenLayer+1);
		}
		*delta = (*delta) * (1 - (*delta)) * sum;
		std::cout << *delta<< std::endl;
		deltaNext = deltaOut;
		beginElement++;
	}
		// use sigmoidPrime()
		// IMPLEMENTAR!
	return paramsPrime;
}


	// minimizar error
void Trainer::train() {
	// normalizar entradas y salidas.
	params_t params = nn.getParams();
	double error = 1;
	double epoch =100;
	do {
		error = costFunction();
		params_t gradients = costFunctionPrime(0);
		// usar gradients y hacer paso del gradiente
		// params =   // IMPLEMENTAR!
		nn.setParams(params);
		--epoch;
		std::cout<<"error>>"<< error << std::endl;
	} while ((error > 0e-4) && (epoch > 0) );
	std::cout << "salida" << std::endl;
}

