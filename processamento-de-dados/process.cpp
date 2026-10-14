#include"process.hpp"
#include<cmath>
#include<sstream>
#include<string>
#include<iomanip>

#include<iostream>

using namespace std;

//implementacao das funcoes
//=======================================================

//coloca o numero em notacao

double mantissa(double x){
    //descobrindo grandeza
    if(x == 0.0)
        return 0;
    int expoente = floor(log10(abs(x))) + 1;
    return ( x / pow(10, expoente));
}

//devolve o expoente para por na notacao
int expoente(double x){
    if(x == 0.0)
        return 0;
    int expoente = floor(log10(abs(x))) + 1;
    return expoente;
}
//=======================================================

//===========truncamento==================== //
/*double tru(double x, int n){

    //posicao
    int pos = posicao(x);
    string numeroParaString = to_string(x);
    //truncamento
    numeroParaString.erase(pos + n +1);
    //converter para numero
    return stod(numeroParaString);
}*/
double tru(double x, int n){
    if(x == 0.0)
        return 0.0;

    //pega a escala do numero
    double escala = pow(10.0, n-1-floor(log10(abs(x))));
    //aplica o truncamento
    double truncamento = trunc(x * escala);
    //volta para o numero antigo
    double numeroTruncado = truncamento / escala;
    //retorna o numero truncado
    return numeroTruncado;
}
//=========arredondammento===================
double ard(double x, int n){
    //caso seja enviado 0.0, o programa retorna o proprio 0.0
    if(x == 0.0)
        return 0.0;

    //pegar em qual escala está o numero
    double escala = pow(10.0, n-1 - floor(log10(abs(x))));
    double numeroArredondado = x * escala;
    //aplica o arredondamento
    double arredendamento = round(numeroArredondado);
    numeroArredondado = arredendamento / escala;
    //retorna o numero arredondado
    return numeroArredondado;
}
//aproximar para arredondamento ou truncamento
double aproximar(double x, int escolha_ajuste, int n){
    if(escolha_ajuste == 1){
        return ard(x, n);
    }
    else if(escolha_ajuste == 2){
        return tru(x, n);
    }
}
//ajusta x e y
void ajustar(int escolha_ajuste, double &x, double &y, int n){
    
    switch (escolha_ajuste){
                case 1:
                    x = ard(x, n);
                    y = ard(y, n);
                break;

                case 2:
                    x = tru(x, n);
                    y = tru(y, n);
                break;
            
                default:
                break;
            }
}
//erros
double erroAbs(double valEx, double valApr){
	//descobrindo o erro absoluto com função que transforma em modulo
	return abs(valEx - valApr);
}
double erroRel(double erroAbs, double valApr){
	//divisão por zero
	if(valApr == 0){
        return NAN;
	}
	//Calcula o erro relativo
	return erroAbs / abs(valApr);
}