/*
 * redMultiLabelPerceptron.h
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */
#include "Capa.h"

#ifndef REDMULTILABELPERCEPTRON_H_
#define REDMULTILABELPERCEPTRON_H_
#include <vector>
using namespace std;
class redMultiLabelPerceptron {
  int numCapas;
  vector<Capa> capaVector;
  vector<float> ultimaActivacion;
  void calcularError();
  void backPropagation();
  void AjustarPesos();
public:
	redMultiLabelPerceptron(int capas, int entradas, int salidas, int ocultas);
	void inicializarPesos();
	void activar(vector<float> entradas);
	//void entrenar(vector<Caso> datosEntrenamiento);
	virtual ~redMultiLabelPerceptron();
};

#endif /* REDMULTILABELPERCEPTRON_H_ */
