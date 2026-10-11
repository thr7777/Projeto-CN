// Autores
// Hercules Henrique dos Santos Pereira
// Emily Eloisa dos Santos Leite
// Milena França

//Univasf-ssf
//projeto feito para a disciplina de Calculo Numerico administrada pelo prof. Jorge Cavalcante



#include"operacoes/operacoes.hpp"
#include"processamento-de-dados/process.hpp"
#include"tratamento-de-caracteres/tratamento.hpp"
#include"testes/testes.hpp"

#include<iostream>
#include<string>

#include<iomanip>

using namespace std;
void p(){
    printf("\n");
}
#include<cmath>

int main(){

    testeDoProfessor(2, 2, "0.76545", "0.76541", 1, 4);
    somaDeDois(4.65464, 4.94544, 3);
    erroDeSomas(0.56786, 10, 4);
    
    string entradaUm;
    string entradaDois;

    //variaveis
    double x_arredondado, y_arredondado;
    double x, y;
    double valor;
    double valorAproximado = 0;
    //digito
    int n;

    int escolha, escolha2;
    int escolha_ajuste;

    


    do{

        cout << "qual operacao: \n";
        cout << "[1] - soma \n";
        cout << "[2] - subtracao \n";
        cout << "[3] - multiplicacao \n";
        cout << "[4] - divisao \n";
        cout << "[0] - sair \n";
        cin >> escolha;
        if(escolha == 0)
            break;
        if(escolha > 4 || escolha < 2){
            continue;
        }

        cout << "ajuste apos a operacao - [1] \n";
        cout << "ajuste antes da operacao - [2] \n";
        cin >> escolha2;

        cout << "digite o primeiro numero \n";
        cin >> entradaUm;
        cout << "digite o segundo numero \n";
        cin >> entradaDois;

        cout << "qual ajuste: \n";
        cout << "arredondamento - [1]\n";
        cout << "truncamento - [2]\n";
        cin >> escolha_ajuste;

        cout << "digitos significativos: \n";
        cin >> n;

        if(escolha == 1 || escolha == 2){


            if(!tratamentoDado(entradaUm, x) || !tratamentoDado(entradaDois, y)){
                cout << "valor invalido \n";
                continue;
            }

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
                continue;
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

        double mantisa = mantissa(56.65445);
        int exp = expoente(56.65445);
        
        printf("======================TESTE=======================\n");
        
        printf("valor em notacao: %f x 10^ %d \n", mantisa, exp);

        cout << "Erro absoluto: \n";

        
        printf("%f x 10^%d", mantissa(erroAbsoluto), expoente(erroAbsoluto));
        p();
        cout << "Erro relativo: \n";
        printf("%f x 10^%d", mantissa(erroRelativo), expoente(erroRelativo));
        p();
        cout << "Valor exato: \n";
        printf("%f x 10^%d", mantissa(valor), expoente(valor));
        p();
        cout << "Valor aproximado: \n";
        printf("%f x 10^%d", mantissa(valorAproximado), expoente(valorAproximado));
        p();
        printf("=================================================\n");

    }while(true);
}