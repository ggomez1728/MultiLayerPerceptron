/*
 * alias.cpp
 *
 *  Created on: 10 de oct. de 2015
 *      Author: Germán Gómez
 */
#include <vector>
#include <functional>
#include <iostream>
typedef double output_t;
typedef std::vector<output_t> outputs_t;
typedef std::vector<double> inputs_t;
typedef std::function<double(double)> transfer_function_t;
typedef std::vector<double> params_t;
typedef std::vector<inputs_t> training_inputs_t;
typedef	std::vector<outputs_t> training_outputs_t;
typedef std::vector<outputs_t> outputs_layers_t;
