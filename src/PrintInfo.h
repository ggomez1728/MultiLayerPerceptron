/*
 * PrintInfo.h
 *
 *  Created on: 1 de oct. de 2015
 *      Author: german
 */
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include "Capa.h"
#ifndef PRINTINFO_H_
#define PRINTINFO_H_
using namespace std;

class PrintInfo {
public:
	void printInOut(vector<float> entradas, vector<float> salidas);
	void printModel(vector<Capa> MLP);
};

#endif /* PRINTINFO_H_ */
