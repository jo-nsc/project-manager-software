#include "Pessoa.h"
#include <stdexcept>
#include <iostream>
using namespace std;

double Pessoa::valorPorHoraPadrao = 10;

Pessoa::Pessoa(string nome, double valorPorHora, int horasDiarias) : Recurso(nome)
{
    if (valorPorHora <= 0 || horasDiarias <= 0){
                throw new invalid_argument ("Invalido");
    }
    this->valorPorHora = valorPorHora;
    this->horasDiarias = horasDiarias;
    recebeu = false;
}
Pessoa::Pessoa(string nome, int horasDiarias) : Recurso(nome)
{
    if (horasDiarias <= 0){
        throw new invalid_argument ("Numero de dias invalido");
    }
    recebeu = true;
    this->horasDiarias = horasDiarias;
    valorPorHora = Pessoa::valorPorHoraPadrao;
}
Pessoa::~Pessoa()
{
    //dtor
}
int Pessoa::getHorasDiarias()
{
    return horasDiarias;
}
double Pessoa::getValorPorHora()
{
    if (recebeu){
        return Pessoa::valorPorHoraPadrao;
    } else {
        return valorPorHora;
    }
}
double Pessoa::getCusto(int dias)
{
    if (dias <= 0){
        throw new invalid_argument ("Numero de dias invalido");
    }
    return dias*horasDiarias*valorPorHora;
}
void Pessoa::imprimir(){
    if (recebeu){
    cout << "Pessoa: " << nome << " - R$" << Pessoa::valorPorHoraPadrao << " - " << horasDiarias << " por dia" << endl;

    } else {
    cout << "Pessoa: " << nome << " - R$" << valorPorHora << " - " << horasDiarias << " por dia" << endl;
    }
}
bool Pessoa::recebeValorPadrao()
{
    return recebeu;
}

double Pessoa::getValorPorHoraPadrao(){
    return Pessoa::valorPorHoraPadrao;
}
void Pessoa::setValorPorHoraPadrao(double valor){
    Pessoa::valorPorHoraPadrao = valor;
}
