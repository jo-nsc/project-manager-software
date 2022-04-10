#include "Atividade.h"
#include <cmath>
#include <stdexcept>

Atividade::Atividade(string nome) : nome(nome)
{
    this->quantidadeDeRecursos = 0;
    terminada = false;
}

Atividade::~Atividade()
{
    //dtor
}
string Atividade::getNome(){
    return this->nome;
}
void Atividade::adicionar(Recurso* r){
    int i;
    bool igual = false;
    for (i = 0; i != this->quantidadeDeRecursos; i++){
        if (recursos[i] == r){
            igual = true;
        }
    }
    if (this->quantidadeDeRecursos >= MAX_RECURSOS){
        throw new overflow_error ("Stack Overflow");
    }
    if (igual){
        throw new invalid_argument ("Ja adicionado");
    }
    recursos[quantidadeDeRecursos] = r;
    quantidadeDeRecursos ++;
}
Recurso** Atividade::getRecursos(){
    return recursos;
}
int Atividade::getQuantidadeDeRecursos(){
    return this->quantidadeDeRecursos;
}
double Atividade::getCusto(){
    int i, soma = 0;
    if (getQuantidadeDeRecursos() == 0){
        return 0;
    }
    for (i = 0; i != getQuantidadeDeRecursos(); i++){
        soma += recursos[i]->getCusto(getDuracao());
    }
    return soma;
}
void Atividade::terminar(int duracaoReal){
    if (duracaoReal <= 0){
        throw new invalid_argument ("Duracao invalida");
    }

    terminada = true;
    this->duracaoReal = duracaoReal;
}
bool Atividade::estaTerminada(){
    return terminada;
}
void Atividade::imprimir(){
    cout << this->nome << " - " << getDuracao() << " dias - R$" << getCusto() << endl;
}
