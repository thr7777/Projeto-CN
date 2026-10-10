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
/*int posicao(double x){
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
}*/


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
    double numeroArredondado = truncamento / escala;
    return numeroArredondado;
}
//=========arredondammento===================
/*double ard(double x, int n){

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
*/
/*double ard(double x, int n){
    double notacaoMantissa =  mantissa(x);
    std::string numeroParaString = to_string(notacaoMantissa);

    //expoente
    int expoente = floor(log10(x)) + 1;
    //posicao do primeiro digito significativo
    int pos = posicao(notacaoMantissa);
    //variavel de controle para casos de arredondamento
    int verificacaoErase =  numeroParaString[pos+n] - '0';
    
    //primeiro caso (1-4) ===================================
    if(verificacaoErase >= 1 && verificacaoErase <= 4){
        //apaga o restante
        numeroParaString.erase(pos+n);
        //tira da mantissa e retorna
        return stod(numeroParaString) * (pow(10, expoente));
    }//=======================================================
    else if(verificacaoErase >= 5 && verificacaoErase <= 9){
        
        numeroParaString.erase(pos+n);
        //pega o ultimo numero de dentro da string
        int ultimoNumero = numeroParaString[numeroParaString.size() -1] - '0';
        
        //soma com um ( arredonda ) e coloca novamente dentro da string

        //primeiro caso - o ultimo nao ser 9
        if(ultimoNumero != 9){
            ultimoNumero+=1;
            numeroParaString[numeroParaString.size()-1] = ultimoNumero + '0';
            return stod(numeroParaString);
        }

        //segundo caso - o ultimo é igual a nove
        else if(ultimoNumero == 9){
            int aux = 0;
            for(int i = numeroParaString.size() - 1; i>=0; i--){
                if(numeroParaString[i] == '.'){
                    numeroParaString.insert(2, 1, '1');
                    break;
                }
                //procura o primeiro numero diferente de 9 para somar mais um
                //caso nao ache ele vai zerando todos
                if(numeroParaString[i] == '9'){
                    numeroParaString[i] = '0';
                }else if(numeroParaString[i] != 9){
                    int aux = numeroParaString[i] - '0';
                    aux+=1;
                    numeroParaString[i] = aux + '0';
                }
            }
            //retorno
            return stod(numeroParaString);
        }
    }
}
*/
double ard(double x, int n){
    //caso seja enviado 0.0, o programa retorna o proprio 0.0
    if(x == 0.0)
        return 0.0;

    //pegar em qual escala está o numero
    double escala = pow(10.0, n-1 - floor(log10(abs(x))));
    double numeroArredondado = x * escala;
    double arredendamento = round(numeroArredondado);
    numeroArredondado = arredendamento / escala;
    return numeroArredondado;
}