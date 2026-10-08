#ifndef PROCESSAMENTO_H
#define PROCESSAMENTO_H
#include<string>

//declaração de funções

//notação cientifica
std::string notacao(double x);

//ajustes
double ard(double v, int n);
double tru(double v, int n);

//seletor de operacao
double calc(double x, double y);

//operacoes principais
double som(double x, double y);
double sub(double x, double y);
double mult(double x, double y);
double div(double x, double y);


int posicao(double x);

#endif