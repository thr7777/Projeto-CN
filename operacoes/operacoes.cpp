#include"operacoes.hpp"
#include"processamento-de-dados/process.hpp"
#include<iostream>

using namespace std;

double soma(double x, double y){
    return (x + y);
}

double sub(double x, double y){


    return (x - y);
}

//essa funcao retorna de forma recursiva pegando os erros com o truncamento
double mult(double x, double y, int n){
    if (y != (int)y) {
        return x * y;
    }

    if (y < 0.0) {
        return -mult(x, -y, n);
    }

    if(y == 0.0)
        return 0.0;
    double resul = mult(x, y-1.0, n);
    return tru(resul + x, n);
}

double multNormal(double x, double y){
    return (x * y);
}

double div(double x, double y){
    if(y == 0.0)
        exit(1);
    return (x / y);
}