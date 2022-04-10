#include "Projeto.h"
#include <list>
#include <stdexcept>
using namespace std;

Projeto::Projeto(string nome) : nome(nome)
{
    recursos = new list<Recurso*>();
    atividades = new vector<Atividade*>();
}

Projeto::~Projeto()
{

}

string Projeto::getNome(){
    return nome;
}

void Projeto::adicionar(Atividade* a){
    atividades->push_back(a);
}

vector<Atividade*>* Projeto::getAtividades(){
    return atividades;
}

void Projeto::adicionar(Recurso* r){
    bool igual = false;
    list<Recurso*>::iterator i = recursos->begin();
    while (i != recursos->end()){
        if ((*i) == r){
            throw new invalid_argument ("Ja adicionado");
            igual = true;
        }
        i++;
    }
    if (igual == false){
        recursos->push_back(r);
    }
}

list<Recurso*>* Projeto::getRecursos(){
    return recursos;
}

int Projeto::getDuracao(){
    int soma = 0;
    unsigned int i;
    for (i = 0; i != atividades->size(); i++){
        soma += (*atividades)[i]->getDuracao();
    }
    return soma;
}
int Projeto::getDuracao(bool terminadas){
    int soma = 0;
    unsigned int i;
    for (i = 0; i != atividades->size(); i++){
        if (terminadas == (*atividades)[i]->estaTerminada()){
            soma += (*atividades)[i]->getDuracao();
        }
    }
    return soma;
}

double Projeto::getCusto(){
    int soma = 0;
    unsigned int i;
    for (i = 0; i != atividades->size(); i++){
        soma += (*atividades)[i]->getCusto();
    }
    return soma;
}
void Projeto::imprimir(){
    unsigned int i;
    cout << nome << " - " << getDuracao() << " dias - R$" << getCusto() << endl;
    cout << "- Feito " << getDuracao(true) << " dias" << endl;
    cout << "- Falta " << getDuracao(false) << " dias" << endl;
    cout << "----" << endl;
    for (i = 0; i != atividades->size(); i ++){
        (*atividades)[i]->imprimir();
    }
}
