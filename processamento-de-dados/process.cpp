#include"process.hpp"
#include<cmath>
#include<sstream>
#include<string>
#include<iomanip>

#include<iostream>

using namespace std;

//implementacao das funcoes

//notacao
/*std::string notacao(double x){
    double mant = mantissa(x);

}*/

//=======================================================
double mantissa(double x){

    //descobrindo grandeza
    int expoente = floor(log10(x)) + 1;
    return ( x / pow(10, expoente)); 
}
//=======================================================

//descobrindo digito significativo
int posicao(double x){

    //transformacao de numero para string
    string numeroParaString = to_string(x);
    int tam = numeroParaString.size();
    int pos = 0;

    //percorrendo para encontrar o primeiro digito significativo
    for(int i = 0; i<tam; i++){
        if(numeroParaString[i] >= '1' && numeroParaString[i] <= '9'){
            pos = i;
            break;
        }      
    }
    //retorno da posicao
    return pos;
}






//===========truncamento====================
double tru(double x, int n){

    //posicao
    int pos = posicao(x);
    string numeroParaString = to_string(x);
    //truncamento
    numeroParaString.erase(pos + n +1);
    //converter para numero
    return stod(numeroParaString);
}

//=========arredondammento===================
double ard(double x, int n){

    //posicao do primeiro digito significativo
    int pos = posicao(x);
    
    string numeroParaString = to_string(x);

    //pegando o caractere para verificacao
    int verificacao = numeroParaString[n+pos+1] - '0';
    //apagando o restante
    numeroParaString.erase(n + pos + 1);

    //logica do arredondamento
    
    //verificando (5-9)
    if(verificacao >=5 && verificacao <=9){
        //posicao do ultimo
        int ultimo = numeroParaString.size() - 1;
        //transformando ultimo em numero
        int ultimoNumero = numeroParaString[ultimo] - '0';
        //somando o ultimo com 1
        ultimoNumero+=1;
        //verificar se a soma deu 10

            if(ultimoNumero == 10){
                int verificaNove = 0;

                for(int i=numeroParaString.size()-1 ; i>=0 ; i--){

                    //ignora o ponto
                    if(numeroParaString[i] == '.')
                        continue;
                        
                    if(numeroParaString[i] != '9'){
                        
                        //se chegou no ultimo e ele é o sinal negativo
                        if(numeroParaString[i] == '-'){
                             numeroParaString.insert(1, 1, '1');
                            //apago o ultimo para ajustar o numero para n digitos
                            numeroParaString.erase(numeroParaString.end());
                        }

                        verificaNove = 1;
                        int proximaSoma = numeroParaString[i] - '0';
                        proximaSoma+=1;
                        numeroParaString[i] = proximaSoma + '0';
                        break;

                    }else{
                        numeroParaString[i] = '0';
                    }
                }

                //caso em que nao achou o diferente de 9
                if(!verificaNove){
                    numeroParaString.insert(0, 1, '1');
                    //apago o ultimo para ajustar o numero para n digitos
                    numeroParaString.erase(numeroParaString.end());
                }
            }else{
                //trocando o ultimo com ultimo numero
                numeroParaString[ultimo] = ultimoNumero + '0';
            }
    }

    return stod(numeroParaString);
}



int main(){

    double y = ard(9.99999, 4);
    double x = tru(3.959585, 4);
    int pos = posicao(3.89898);
    
    cout << y;
    cout << x;
   

    return 0;
}