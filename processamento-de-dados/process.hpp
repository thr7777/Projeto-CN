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

double aproximar(double x, int escolha_ajuste, int n);
//seletor de operacao

//operacoes principais

#endif