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
#include "alias.h"
using namespace std;
#include <stdio.h>

// function generator:
double RandomNumber () { return (((double) rand() / (RAND_MAX))); }

int main() {
	cout << "!!!Multi Layer Perceptron!!!" << endl; // prints !!!Multi Layer Perceptron!!!
	std::srand ( unsigned ( std::time(0) ) );
	MLP mlp(1,2,2,1);
	params_t params(mlp.getParams());
	std::generate(params.begin(), params.end(), RandomNumber); // with C function rand()
	mlp.setParams(params);
	Trainer trainer(MLP);
	return 0;
}
