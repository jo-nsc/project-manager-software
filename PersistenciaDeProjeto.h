#ifndef PERSISTENCIADEPROJETO_H
#define PERSISTENCIADEPROJETO_H
#include <fstream>
#include "Projeto.h"


class PersistenciaDeProjeto
{
    public:
        PersistenciaDeProjeto();
        virtual ~PersistenciaDeProjeto();
        void salvar(Projeto* p, string arquivo);
        Projeto* carregar(string arquivo);

    protected:

    private:
};

#endif // PERSISTENCIADEPROJETO_H
