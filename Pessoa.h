#ifndef PESSOA_H
#define PESSOA_H
#include "Recurso.h"


class Pessoa : public Recurso
{
    public:
        Pessoa(string nome, double valorPorHora, int horasDiarias);
        Pessoa (string nome, int horasDiarias);
        virtual ~Pessoa();
        virtual double getValorPorHora();
        virtual int getHorasDiarias();
        virtual bool recebeValorPadrao();
        double getCusto(int dias);
        virtual void imprimir();
        static void setValorPorHoraPadrao(double valor);
        static double getValorPorHoraPadrao();


    protected:
        int horasDiarias;
        double valorPorHora;
        static double valorPorHoraPadrao;
    private:
        bool recebeu;
};

#endif // PESSOA_H
