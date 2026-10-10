#include"tratamento.hpp"
#include"operacoes/operacoes.hpp"
#include<string>
//verificacao de numeros
#include<cctype>

//para verificar a entrada
#include<sstream>

#include<cmath>

//para cout e cin
#include<iostream>

using namespace std;

bool tratamentoDado(string entrada, double &x){
    //pega a entrada diretamente para tratar como string e depois devolve o valor dentro de x
    istringstream fluxo(entrada);
    double numero;
    char extra;

    //se sobrar caracter, significa que tinha outra coisa além de numero
    if( (fluxo >> numero) && !(fluxo >> extra)){
        x = numero;
        return true;
    }
    return false;
}