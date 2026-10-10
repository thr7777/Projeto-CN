#include"operacoes/operacoes.hpp"
#include"processamento-de-dados/process.hpp"

#include<iostream>
#include<string>

#include<iomanip>

using namespace std;

int main(){

    double x;
    double y;
    int n;

    cout << "x: \n" ;
    cin >> x;

    cout << " y \n";
    cin >> y;

    cout << "n \n";
    cin >> n;
    
    double truc = tru(x, n);
    cout << truc;
    
    return 0;
}