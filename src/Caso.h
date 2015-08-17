/*
 * Caso.h
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */

#ifndef CASO_H_
#define CASO_H_
#include <vector>
using namespace std;
class Caso {
	vector<float> entradasCaso;
	vector<float> salidasCaso;
public:
	Caso();
	void cargarCaso(vector<float> entradas, vector<float> salidas);
	vector<float> getEntradasCaso();
	vector<float> getSalidasCaso();
	virtual ~Caso();
};

#endif /* CASO_H_ */
