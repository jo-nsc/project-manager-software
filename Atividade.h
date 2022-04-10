#ifndef ATIVIDADE_H
#define ATIVIDADE_H
#include "Recurso.h"
#include "Ferramenta.h"
#include "Pessoa.h"
#include <iostream>
using namespace std;

class Atividade
{
    public:
        Atividade(string nome);
        virtual ~Atividade();
        virtual string getNome();
        virtual void adicionar(Recurso* r);
        virtual Recurso** getRecursos();
        virtual int getQuantidadeDeRecursos();
        virtual int getDuracao() = 0;
        virtual double getCusto();
        virtual void imprimir();
        virtual void terminar(int duracaoReal);
        virtual bool estaTerminada();
        static const int MAX_RECURSOS = 10;

    protected:
        int quantidadeDeRecursos;
        Recurso* recursos[MAX_RECURSOS];
        bool terminada;
        int duracaoReal;
    private:
        string nome;
};

#endif // ATIVIDADE_H
