/*
 * Neurona.h

 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */
#ifndef NEURONA_H_
#define NEURONA_H_

#define RAND_MAX = 1
#include <math.h>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


using namespace std;
class Neurona {
  float binary_sigmoidal(float in_value);
  float bipolar_sigmoidal( float in_value);
public:
  vector<float> pesos;
  float salida;
  float valorDelta;
  bool esBias;

  Neurona(int entradas);
  float activarEntradas(vector<float> entradas) const;
  vector<float> actualizarPesos(vector<float> deltas);
  void actualizarPesos();
  void iniciarlizarNeurona();
  void cargarEntradas(vector<float> entradas);
};

#endif /* NEURONA_H_ */
