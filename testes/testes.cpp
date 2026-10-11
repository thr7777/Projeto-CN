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

void testeDoProfessor(int escolha, int escolha2, string entradaUm,string entradaDois, int escolha_ajuste, int n){

    

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
            /*switch (escolha_ajuste){
                case 1:
                    x_arredondado = ard(x, n);
                    y_arredondado = ard(y, n);
                break;

                case 2:
                    x_arredondado = tru(x, n);
                    y_arredondado = tru(y, n);
                break;
            
                default:
                break;
            }*/

            
            switch (escolha){
                case 1:

                    
                    if(escolha2 == 1){
                        valor = soma(x, y);
                        valorAproximado = aproximar(valor, escolha_ajuste, n);
                    }
                    else if(escolha2 == 2){
                        valor = soma(x, y);
                        ajustar(escolha_ajuste, x, y, n);
                        valorAproximado = soma(x, y);
                    }
                break;

                case 2:
                        if(escolha2 == 1){
                        valor = sub(x, y);
                        valorAproximado = aproximar(valor, escolha_ajuste, n);
                        }
                        else if(escolha2 == 2){
                            valor = sub(x, y);
                            ajustar(escolha_ajuste, x, y, n);
                            valorAproximado = sub(x, y);
                        }
                break;

                default:
                break;
            }

        }

        else if(escolha == 3 || escolha == 4){

            
            if(!tratamentoDado(entradaUm, x) || !tratamentoDado(entradaDois, y)){
                cout << "valor invalido \n";
                exit(1);
            }
            switch (escolha)
            {
                case 3:
                    if(escolha2 == 1){
                        valor = multNormal(x, y);
                        valorAproximado = aproximar(valor, escolha_ajuste, n);
                    }
                    else if(escolha2 == 2){
                        valor = multNormal(x, y);
                        ajustar(escolha_ajuste, x, y, n);
                        valorAproximado = multNormal(x, y);
                     }
                break;

                case 4:
                     if(escolha2 == 1){
                        valor = div(x, y);
                        valorAproximado = aproximar(valor, escolha_ajuste, n);
                    }
                    else if(escolha2 == 2){
                        valor = div(x, y);
                        ajustar(escolha_ajuste, x, y, n);
                        valorAproximado = div(x, y);
                     }

                break;
            
            default:
                break;
            }
            //verifica o tipo de ajuste, antes ou depois
        }

        //mostrando erros
        double erroAbsoluto = erroAbs(valor, valorAproximado);
        double erroRelativo = erroRel(erroAbsoluto, valorAproximado);



        //interface bonitinha hehehehhehehehehehe

        double mantisa = mantissa(valorAproximado);
        int exp = expoente(valorAproximado);

        printf("======================TESTE=======================\n");
        
        printf("valor em notacao: %f x 10^ %d \n", mantisa, exp);

        cout << "Erro absoluto: \n";

        
        printf("%f x 10^%d", mantissa(erroAbsoluto), expoente(erroAbsoluto));
        p2();
        cout << "Erro relativo: \n";
        printf("%f x 10^%d", mantissa(erroRelativo), expoente(erroRelativo));
        cout << "ou \n";
        printf("%f%% \n", erroRelativo * 100);
        p2();
        cout << "Valor exato: \n";
        printf("%f x 10^%d", mantissa(valor), expoente(valor));
        p2();
        cout << "Valor aproximado: \n";
        printf("%f x 10^%d", mantissa(valorAproximado), expoente(valorAproximado));
        p2();
        printf("=================================================\n");

        

}


void somaDeDois(double x, double y, int n){
    double somaTeste = soma(x, y);
    double truncamentoTeste = tru(somaTeste, n);
    double arredondamentoTeste = ard(somaTeste, n);
    double erroAbsolutoTruncamento = erroAbs(somaTeste, truncamentoTeste);
    double erroAbsolutoArredondamento = erroAbs(somaTeste, arredondamentoTeste);

    double erroRelativoTruncamento = erroRel(erroAbsolutoTruncamento, truncamentoTeste);
    double erroRelativoArredondamento = erroRel(erroAbsolutoArredondamento, arredondamentoTeste);

     printf("======================TESTE=======================\n");
        
        cout << "Valor exato: \n";
        printf("%f x 10^%d", mantissa(somaTeste), expoente(somaTeste));
        p2();





        cout << "Valor aproximado com truncamento: \n";
        printf("%f x 10^%d", mantissa(truncamentoTeste), expoente(truncamentoTeste));
        p2();

        cout << "Erro absoluto com truncamento: \n";
        printf("%f x 10^%d", mantissa(erroAbsolutoTruncamento), expoente(erroAbsolutoTruncamento));
        p2();
        cout << "Erro relativo com truncamento : \n";
        printf("%f x 10^%d \n", mantissa(erroRelativoTruncamento), expoente(erroRelativoTruncamento));
        printf("ou entao \n");
        printf("%f%% \n", erroRelativoTruncamento * 100);
        p2();






        cout << "Valor aproximado com arredondamento: \n";
        printf("%f x 10^%d", mantissa(arredondamentoTeste), expoente(arredondamentoTeste));
        p2();
        cout << "Erro absoluto com arredondamento: \n";
        printf("%f x 10^%d", mantissa(erroAbsolutoArredondamento), expoente(erroAbsolutoArredondamento));
        p2();
        cout << "Erro relativo com arredondamento: \n";
        printf("%f x 10^%d \n", mantissa(erroRelativoArredondamento), expoente(erroRelativoArredondamento));
        printf("ou entao \n");
        printf("%f%%", erroRelativoArredondamento * 100);
        p2();

        
        printf("=================================================\n");
}
void erroDeSomas(double x, double y, int n){
    
    double valorExato = multNormal(x, y);
    double valorComErros = mult(x, y, n);

    printf("======================TESTE SOMA ACUMULADA ================\n");
    printf("valor exato: %f \n", valorExato);
    printf("Valor com erros acumulados: %f \n", valorComErros);
    printf("=================================================\n");
}