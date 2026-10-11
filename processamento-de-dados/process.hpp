#ifndef PROCESSAMENTO_H
#define PROCESSAMENTO_H
#include<string>

//declaração de funções

//notação cientifica
std::string notacao(double x);

//ajustes
double ard(double v, int n);
double tru(double v, int n);
double mantissa(double x);
double erroAbs(double valEx, double valApr);
double erroRel(double valEx, double valApr);
//seletor de operacao

//operacoes principais

#endif
