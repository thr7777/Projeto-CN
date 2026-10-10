#include"operacoes.hpp"
#include<iostream>

using namespace std;

double soma(double x, double y){
    return (x + y);
}

double sub(double x, double y){
    return (x - y);
}

double mult(double x, double y){
    return (x * y);
}

double div(double x, double y){
    if(y == 0.0)
        exit(1);
    return (x / y);
}