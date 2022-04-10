#ifndef ATIVIDADEDEPRAZOFIXO_H
#define ATIVIDADEDEPRAZOFIXO_H
#include "Atividade.h"
#include "Recurso.h"
#include "Pessoa.h"
#include "Ferramenta.h"


class AtividadeDePrazoFixo : public Atividade
{
    public:
        AtividadeDePrazoFixo(string nome, int dias);
        virtual ~AtividadeDePrazoFixo();
        virtual int getPrazo();
        int getDuracao();

    protected:

    private:
        int prazo;
};

#endif // ATIVIDADEDEPRAZOFIXO_H
