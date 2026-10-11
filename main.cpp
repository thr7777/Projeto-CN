#include"operacoes/operacoes.hpp"
#include"processamento-de-dados/process.hpp"
#include"tratamento-de-caracteres/tratamento.hpp"

#include<iostream>
#include<string>

#include<iomanip>

using namespace std;

/*int main(){


    double x, y;
    int escolha;
    int escolha_ajuste;
    double valor;
    double ajuste;
    int digitos;
    string entradaUm;
    string entradaDois;
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

        switch (escolha)
        {
            case 1:
                cout << "primeiro numero: \n";
                cin >> entradaUm;
                cout << "segundo numero: \n";
                cin >> entradaDois;
                if(!tratamentoDado(entradaUm, x) || !tratamentoDado(entradaDois, y)){
                    cout << "numero invalido \n";
                    continue;
                }

                valor = soma(x, y);
            break;
        
            case 2:
                cout << "primeiro numero: \n";
                cin >> entradaUm;
                cout << "primeiro numero: \n";
                cin >> entradaDois;
                if(!tratamentoDado(entradaUm, x) || !tratamentoDado(entradaDois, y)){
                    cout << "numero invalido \n";
                    continue;
                }

                valor = sub(x, y);
             
            break;
            case 3:
                cout << "primeiro numero: \n";
                cin >> entradaUm;
                cout << "primeiro numero: \n";
                cin >> entradaDois;
                if(!tratamentoDado(entradaUm, x) || !tratamentoDado(entradaDois, y)){
                    cout << "numero invalido \n";
                    continue;
                }

                valor = mult(x, y);
              
            break;
            case 4:
                cout << "primeiro numero: \n";
                cin >> entradaUm;
                cout << "primeiro numero: \n";
                cin >> entradaDois;
                if(!tratamentoDado(entradaUm, x) || !tratamentoDado(entradaDois, y)){
                    cout << "numero invalido \n";
                    continue;
                }

                valor = div(x, y);
              
            break;
        default:
            break;
        }

        cout << "Ajuste: \n";
        cout << "[1] - truncamento \n";
        cout << "[2] - arredondamento \n";
        cin >> escolha_ajuste;

        cout << "Digitos significativos: \n";
        cin >> digitos;

        //mostrando o ajuste escolhido

        switch (escolha_ajuste)
        {
            case 1:
                ajuste = tru(valor, digitos);
            break;

            case 2:
                ajuste = ard(valor, digitos);
            break;
        default:
            break;
        }

        printf("valor: %f, ajuste: %f \n", valor, ajuste);

    }while(true);

}*/

void p(){
    printf("\n");
}
#include<cmath>

int main(){


    string entradaUm;
    string entradaDois;

    //variaveis
    double x_arredondado, y_arredondado;
    double x, y;
    double valor;
    double valorAproximado;
    //digito
    int n;

    int escolha;
    int escolha_ajuste;
    do{

        cout << "qual operacao: \n";
        cout << "[1] - soma \n";
        cout << "[2] - subtracao \n";
        cout << "[3] - multiplicacao \n";
        cout << "[4] - divisao \n";
        cout << "[0] - sair \n";
        cin >> escolha;

        if(escolha == 1 || escolha == 2){

            cin >> entradaUm;
            cin >> entradaDois;
            if(!tratamentoDado(entradaUm, x) || !tratamentoDado(entradaDois, y)){
                cout << "valor invalido \n";
                continue;
            }

            printf("%f \n", sub(x, y));
            cout << "qual ajuste: \n";
            cout << "arredondamento - [1]\n";
            cout << "truncamento - [2]\n";
            cin >> escolha_ajuste;

            cout << "digitos significativos: \n";
            cin >> n;

            switch (escolha_ajuste){
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
            }
            switch (escolha){

                case 1:
                    valor = soma(x_arredondado, y_arredondado);
                    valorAproximado = aproximar(valor, escolha_ajuste, n);
                break;

                case 2:
                    valor = sub(x_arredondado, y_arredondado);
                    valorAproximado = aproximar(valor, escolha_ajuste, n);

                break;

                default:
                break;
            }

        }

        if(escolha == 0)
            break;
        
        cout << valor;
        p();
        cout << valorAproximado;

    }while(true);

}