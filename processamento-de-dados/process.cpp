#include"process.hpp"
#include<cmath>
#include<sstream>
#include<string>
#include<iomanip>

using namespace std;

//implementacao das funcoes

//notacao
std::string notacao(double x){
    double mant = mantissa(x);



}
double mantissa(double x){
    //descobrindo grandeza
    int expoente = floor(log10(x)) + 1;
    return ( x / pow(10, expoente)); 
}

//descobrindo digito significativo
int posicao(double x){

    string numeroParaString = to_string(x);
    int tam = numeroParaString.size();
    int pos = 0;
    //percorrendo para encontrar o primeiro digito significativo
    for(int i; i<tam; i++){
        if(numeroParaString[i] >= '1' && numeroParaString[i] <= 9)
            pos = i;
    }
}
//truncamento
double tru(double x, int n){
    string numeroParaString = to_string(x);
    //truncamento
    int ponto = numeroParaString.find(".");
    numeroParaString.erase(n);
    //converter para numero
    return stod(numeroParaString);
}
double ard(double x, int n){
}