#ifndef PROCESSAMENTO_H
#define PROCESSAMENTO_H
#include<string>

//declaração de funções

//notação cientifica
std::string notacao(double x);

//ajustes arredondamento e truncamento
double ard(double v, int n);
double tru(double v, int n);

//para notacao
double mantissa(double x);
int expoente(double x);

//aproximacoes e ajuste
double aproximar(double x, int escolha_ajuste, int n);
void ajustar(int escolha_ajuste, double &x, double &y, int n);

//erros
double erroAbs(double x, double y);
double erroRel(double x, double y);



//seletor de operacao

//operacoes principais

#endif