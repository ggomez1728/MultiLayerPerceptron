/*
 * Trainer.h
 *
 *  Created on: 11 de oct. de 2015
 *      Author: german
 */
#include <vector>
#ifndef TRAINER_H_
#define TRAINER_H_
#include "MLP.h"
#include "alias.h"

class Trainer {
		MLP& nn;
	public:
		training_inputs_t training_inputs;
		training_outputs_t training_outputs;
		Trainer(MLP& nn): nn(nn){}
		//Trainer(MLP& _nn);
		double costFunctionPerCase(int _case);
		double costFunction();
		params_t costFunctionPrime();
		void train();
};

#endif /* TRAINER_H_ */
