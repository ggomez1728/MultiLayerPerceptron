/*
 * Capa.h
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */
#include <vector>
#include "Neurona.h"
#ifndef CAPA_H_
#define CAPA_H_
using namespace std;
class Capa {
public:
  vector<Neurona> Neuronas;
  float Delta;
  Capa(int neuronas,  int entradaXneurona, bool isBias);
  void inicializarCapa();
  void agregarBias();
  vector<float> calcularErrorCapa(vector<float> salidaEsperada);
  vector<float> cargarEntrada(vector<float> entradas, bool multiEntrada);
  void cargarMultiEntradas(vector<float> entradas);
  void cargarSimpleEntradas(vector<float> entradas);
  vector<float> ActivarCapa();
};

#endif /* CAPA_H_ */
