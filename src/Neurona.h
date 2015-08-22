/*
 * Neurona.h

 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */
#ifndef NEURONA_H_
#define NEURONA_H_

#define RAND_MAX = 1
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


using namespace std;
class Neurona {
  vector<float> pesos;
  float salida;
public:
  Neurona(int entradas);
  float Activar(vector<float> entradas) const;
  vector<float> Actualizar_Pesos(vector<float> deltas);
  void actualizarPesos();
  void iniciarlizarNeurona();
};

#endif /* NEURONA_H_ */
