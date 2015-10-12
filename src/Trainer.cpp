/*
 * Trainer.cpp
 *
 *  Created on: 11 de oct. de 2015
 *      Author: german
 */

#include "Trainer.h"
#include <algorithm>    // std::transform


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
	for (int i = 0; i < training_inputs.size(); ++i) {
		double local_error = costFunctionPerCase(i);
		acum_error += local_error * local_error;
	}
	return 0.5 * acum_error;
}

// funcion derivada de la funcion costo
// debe retornar todos los gradientes de los pesos de toda la red
params_t Trainer::costFunctionPrime() {
		// use nn.outputs and start the back propagation

		// use sigmoidPrime()

		// IMPLEMENTAR!
}


	// minimizar error
void Trainer::train() {
	// normalizar entradas y salidas.
	params_t params = nn.getParams();
	double error;
	do {
		error = costFunction();
		params_t gradients = costFunctionPrime();

		// usar gradients y hacer paso del gradiente
		// params =   // IMPLEMENTAR!
		nn.setParams(params);

	} while (error > 0e-4);
}

