/*
 * Caso.h
 *
 *  Created on: 15 de ago. de 2015
 *      Author: german
 */

#ifndef CASE_H_
#define CASE_H_
#include <vector>
class Case {
public:
  std::vector<double> inputsCase;
  std::vector<double> outputsCase;
  Case();
  void cargarCaso(std::vector<double> inputs, std::vector<double> outputs);
};

#endif /* CASE_H_ */
