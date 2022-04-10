#include "AtividadeDeEsforcoFixo.h"


AtividadeDeEsforcoFixo::AtividadeDeEsforcoFixo(string nome, int horasNecessarias) : Atividade(nome)
{
    if (horasNecessarias <= 0){
        throw new invalid_argument ("Horas invalidas");
    }
    this->horasNecessarias = horasNecessarias;
}

AtividadeDeEsforcoFixo::~AtividadeDeEsforcoFixo()
{
    //dtor
}
int AtividadeDeEsforcoFixo::getHorasNecessarias(){
    return horasNecessarias;
}
int AtividadeDeEsforcoFixo::getDuracao(){
    int i, soma;
    soma = 0;
    for (i = 0; i != quantidadeDeRecursos; i++){
        Pessoa *p1 = dynamic_cast<Pessoa*>(recursos[i]);
        if (p1 != NULL) {
            soma += p1->getHorasDiarias();
        }
    }
    if (soma != 0)
    return double(horasNecessarias)/double(soma) ;
    else return 0;
}
