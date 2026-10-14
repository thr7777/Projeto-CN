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

    //testes pré definidos
    testeManual(2, 2, "0.76545", "0.76541", 1, 4);
    somaDeDois(4.65464, 4.94544, 3);
    erroDeSomas(0.56786, 10, 4);

    string entradaUm;
    string entradaDois;

    //variaveis
    //double x_arredondado, y_arredondado;
    double x, y;
    double valor;
    double valorAproximado = 0;
    //digitos significativos;
    int n;

    int escolha, escolha2;
    int escolha_ajuste;

    

    do{

        cout << "Qual operacao: \n";
        cout << "[1] - Soma \n";
        cout << "[2] - Subtracao \n";
        cout << "[3] - Multiplicacao \n";
        cout << "[4] - Divisao \n";
        cout << "[0] - Sair \n";
        cin >> escolha;

        //valida a escolha
        if(escolha == 0)
            break;
        if(escolha > 4 || escolha < 1){
            continue;
        }

        cout << "Ajuste apos a operacao - [1] \n";
        cout << "Ajuste antes da operacao - [2] \n";
        cin >> escolha2;
        if(escolha2 > 2 || escolha2 < 1)
            continue;

        cout << "Digite o primeiro numero \n";
        cin >> entradaUm;
        cout << "Digite o segundo numero \n";
        cin >> entradaDois;

        //verifica se a entrada é valida
        if(!tratamentoDado(entradaUm, x) || !tratamentoDado(entradaDois, y)){
                cout << "valor invalido \n";
                continue;
            }

        cout << "Escolha do ajuste: \n";
        cout << "Arredondamento - [1]\n";
        cout << "Truncamento - [2]\n";
        cin >> escolha_ajuste;

        if(escolha_ajuste > 2 || escolha_ajuste < 1)
            continue;

        cout << "Digitos significativos: \n";
        cin >> n;
    

    //neste trexo de código, é escolhido a forma de ajuste (antes ou depois) e depois realizado a operacao desejada pelo usuario
       switch (escolha){
            case 1:
                //realiza soma
                if(escolha2 == 1){
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
                //subtracao
                if(escolha2 == 1){
                    valor = sub(x, y);
                    valorAproximado = aproximar(valor, escolha_ajuste, n);
                }
                else if(escolha2 == 2){
                    valor = sub(x, y);
                    ajustar(escolha_ajuste, x, y, n);
                    valorAproximado = sub(x, y);
                    valorAproximado = aproximar(valorAproximado, escolha_ajuste, n);
                }
        
            break;
            case 3:
                //multiplicacao
                if(escolha2 == 1){
                    valor = multNormal(x, y);
                    valorAproximado = aproximar(valor, escolha_ajuste, n);
                }
                else if(escolha2 == 2){
                    valor = multNormal(x, y);
                    ajustar(escolha_ajuste, x, y, n);
                    valorAproximado = multNormal(x, y);
                    valorAproximado = aproximar(valorAproximado, escolha_ajuste, n);
                }
            break;
            case 4:
            //divisao
                if(escolha2 == 1){
                    valor = div(x, y);
                    valorAproximado = aproximar(valor, escolha_ajuste, n);
                }
                else if(escolha2 == 2){
                    valor = div(x, y);
                    ajustar(escolha_ajuste, x, y, n);
                    valorAproximado = div(x, y);
                    valorAproximado = aproximar(valorAproximado, escolha_ajuste, n);
                }
            break;
       default:
        break;
       }

        

        //pegando erros para serem mostrados na tela
        double erroAbsoluto = erroAbs(valor, valorAproximado);
        double erroRelativo = erroRel(erroAbsoluto, valorAproximado);

        printf("======================RESULTADO====================\n");

        printf("Valores: x = %g, y = %g \n", x, y);
        cout << "Valor exato da operacao: \n";
        printf("%g x 10^%d", mantissa(valor), expoente(valor));
        p();
        cout << "Valor aproximado: \n";
        printf("%g x 10^%d", mantissa(valorAproximado), expoente(valorAproximado));
        p();
        printf("Erro absoluto:\n%g x 10^%d", mantissa(erroAbsoluto), expoente(erroAbsoluto));
        p();

        if(isnan(erroRelativo)){
            printf("Erro relativo indefinido\n");
        }else{
            printf("Erro relativo:\n%g x 10^%d ou %g%%", mantissa(erroRelativo), expoente(erroRelativo), erroRelativo*100);
            p();
        }
        printf("==================================================\n");

    }while(true);
}