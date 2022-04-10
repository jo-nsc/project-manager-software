#include "Ferramenta.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Ferramenta::Ferramenta(string nome, double custoDiario) : Recurso(nome)
{
    this->custoDiario = custoDiario;
}
Ferramenta::~Ferramenta()
{
    cout << "Ferramenta destruida" << endl;
}

double Ferramenta::getCusto(int dias)
{
    if (dias <= 0){
        throw new invalid_argument ("Numero de dias invalido");
    }
    return dias*custoDiario;
}
double Ferramenta::getCustoDiario()
{
    return custoDiario;
}
void Ferramenta::imprimir()
{
    cout << "Ferramenta: " << nome << " - R$" << custoDiario << " por dia" << endl;
}
