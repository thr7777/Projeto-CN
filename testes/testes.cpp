#include"operacoes/operacoes.hpp"
#include"processamento-de-dados/process.hpp"
#include"tratamento-de-caracteres/tratamento.hpp"
#include"testes.hpp"

#include<iostream>
#include<string>

#include<iomanip>

using namespace std;

void p2(){
    printf("\n");
}

void testeManual(int escolha, int escolha2, string entradaUm,string entradaDois, int escolha_ajuste, int n){

    //para evitar erros de logica
     if(escolha2 > 2 || escolha2 < 1){
        printf("valor invalido \n");
        exit(1);
     }
     if(escolha_ajuste > 2 || escolha_ajuste < 1){
        printf("Valor invalido\n");
        exit(1);
     }
     if(escolha > 2 || escolha < 1){
        printf("valor invalido \n");
        exit(1);
     }

    //variaveis
    double x, y;
    double valor;
    double valorAproximado = 0;
    //digito
   
        if(escolha == 1 || escolha == 2){


            if(!tratamentoDado(entradaUm, x) || !tratamentoDado(entradaDois, y)){
                cout << "valor invalido \n";
                exit(1);
            }
            

            //verifica a escolha / caso 1 é soma e caso 2 é subtracao
            switch (escolha){
                case 1:

                    //escolha de ajustar primeiro ou depois
                    if(escolha2 == 1){
                        //ajustar depois
                        valor = soma(x, y);
                        valorAproximado = aproximar(valor, escolha_ajuste, n);
                    }
                    else if(escolha2 == 2){
                        valor = soma(x, y);
                        ajustar(escolha_ajuste, x, y, n);
                        valorAproximado = soma(x, y);
                        valorAproximado = aproximar(valorAproximado, escolha_ajuste, n);
                    }
                break;

                case 2:
                        //escolha de ajustar primeiro ou depois
                        
                        if(escolha2 == 1){
                        //ajustar depois
                        valor = sub(x, y);
                        valorAproximado = aproximar(valor, escolha_ajuste, n);
                        }
                        else if(escolha2 == 2){
                            //ajustar antes
                            valor = sub(x, y);
                            ajustar(escolha_ajuste, x, y, n);
                            valorAproximado = sub(x, y);
                            valorAproximado = aproximar(valorAproximado, escolha_ajuste, n);
                        }
                break;

                default:
                break;
            }

        }

        //para soma e multiplicacao
        else if(escolha == 3 || escolha == 4){

            //verifica as entradas e as coloca em x e y
            if(!tratamentoDado(entradaUm, x) || !tratamentoDado(entradaDois, y)){
                cout << "valor invalido \n";
                exit(1);
            }

             //verifica a escolha / caso 1 é soma e caso 2 é subtracao
            switch (escolha)
            {
                case 3:

                    if(escolha2 == 1){
                        //caso ajuste depois
                        valor = multNormal(x, y);
                        valorAproximado = aproximar(valor, escolha_ajuste, n);
                    }
                    else if(escolha2 == 2){
                        //caso ajuste antes
                        valor = multNormal(x, y);
                        ajustar(escolha_ajuste, x, y, n);
                        valorAproximado = multNormal(x, y);
                        valorAproximado = aproximar(valorAproximado, escolha_ajuste, n);
                     }
                break;

                case 4:
                     if(escolha2 == 1){
                        //caso ajuste depois
                        valor = div(x, y);
                        valorAproximado = aproximar(valor, escolha_ajuste, n);
                    }
                    else if(escolha2 == 2){
                        //caso ajuste antes
                        valor = div(x, y);
                        ajustar(escolha_ajuste, x, y, n);
                        valorAproximado = div(x, y);
                        valorAproximado = aproximar(valorAproximado, escolha_ajuste, n);
                     }

                break;
            
            default:
                break;
            }
            //verifica o tipo de ajuste, antes ou depois
        }

        //pegando os erros
        double erroAbsoluto = erroAbs(valor, valorAproximado);
        double erroRelativo = erroRel(erroAbsoluto, valorAproximado);


        printf("==================TESTES===============\n");
        //apresentacao dos testes
        printf("Valor exato: %g x 10^%d", mantissa(valor), expoente(valor));
        p2();
        printf("Valor aproximado: %g x 10^%d", mantissa(valorAproximado), expoente(valorAproximado));
        p2();
        printf("Erro absoluto: %g x 10^%d", mantissa(erroAbsoluto), expoente(erroAbsoluto));
        p2();
        printf("Erro relativo: %g x 10^%d ou %f%%\n", mantissa(erroRelativo), expoente(erroRelativo), erroRelativo * 100);
        p2();
        printf("=================================================\n");
}


void somaDeDois(double x, double y, int n){

    //truncando e arredondando a soma
    double somaTeste = soma(x, y);
    double truncamentoTeste = tru(somaTeste, n);
    double arredondamentoTeste = ard(somaTeste, n);
    //pegando os dois tipos de ajustes
    double erroAbsolutoTruncamento = erroAbs(somaTeste, truncamentoTeste);
    double erroAbsolutoArredondamento = erroAbs(somaTeste, arredondamentoTeste);
    double erroRelativoTruncamento = erroRel(erroAbsolutoTruncamento, truncamentoTeste);
    double erroRelativoArredondamento = erroRel(erroAbsolutoArredondamento, arredondamentoTeste);

     printf("====================TESTE COM SOMA====================\n");
        //apresentacao do resultado

        printf("Valor exato %fx10^%d\n", mantissa(somaTeste), expoente(somaTeste));
        cout << "Valor aproximado com truncamento: \n";
        printf("%g x 10^%d", mantissa(truncamentoTeste), expoente(truncamentoTeste));
        p2();

        cout << "Erro absoluto com truncamento: \n";
        printf("%g x 10^%d", mantissa(erroAbsolutoTruncamento), expoente(erroAbsolutoTruncamento));
        p2();
        cout << "Erro relativo com truncamento : \n";
        printf("%g x 10^%d \n", mantissa(erroRelativoTruncamento), expoente(erroRelativoTruncamento));
        printf("ou entao \n");
        printf("%g%% \n", erroRelativoTruncamento * 100);
        p2();
        p2();
        cout << "Valor aproximado com arredondamento: \n";
        printf("%g x 10^%d", mantissa(arredondamentoTeste), expoente(arredondamentoTeste));
        p2();
        cout << "Erro absoluto com arredondamento: \n";
        printf("%g x 10^%d", mantissa(erroAbsolutoArredondamento), expoente(erroAbsolutoArredondamento));
        p2();
        cout << "Erro relativo com arredondamento: \n";
        printf("%g x 10^%d \n", mantissa(erroRelativoArredondamento), expoente(erroRelativoArredondamento));
        printf("ou entao \n");
        printf("%g%%", erroRelativoArredondamento * 100);
        p2();
        printf("=================================================\n");
}
void erroDeSomas(double x, double y, int n){
    
    
    double valorExato = multNormal(x, y);
    double valorComErros = mult(x, y, n);
    double erroAbsoluto = erroAbs(valorExato, valorComErros);
    double erroRelativo = erroRel(erroAbsoluto, valorComErros);

    //pegando valores para apresentar como notacao cientifica
    int expEx = expoente(valorExato);
    int expEr = expoente(valorComErros);

    double mantisaValorExato = mantissa(valorExato);
    double mantisaValorComErros = mantissa(valorComErros);

    //apresentacao do resultado
    printf("======================TESTE SOMA ACUMULADA ================\n");
    printf("Valor exato: %gx10^%d\n", mantisaValorExato, expEx);
    printf("Valor com erro acumulado: %fx10^%d\n", mantisaValorComErros, expEr);
    printf("Erro absoluto: %g\n", erroAbsoluto);
    printf("Erro relativo: %g ou %f%%\n", erroRelativo, erroRelativo *100);
    printf("=================================================\n");
}