#ifndef FERRAMENTA_H
#define FERRAMENTA_H
#include "Recurso.h"


class Ferramenta : public Recurso
{
    public:
        Ferramenta(string nome, double custoDiario);
        virtual ~Ferramenta();
        virtual double getCustoDiario();
        double getCusto(int dias);
        void imprimir();
    protected:

    private:
        double custoDiario;
};

#endif // FERRAMENTA_H
