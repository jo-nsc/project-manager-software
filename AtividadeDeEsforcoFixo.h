#ifndef ATIVIDADEDEESFORCOFIXO_H
#define ATIVIDADEDEESFORCOFIXO_H
#include "Atividade.h"
#include "Recurso.h"
#include <stdexcept>



class AtividadeDeEsforcoFixo : public Atividade
{
    public:
        AtividadeDeEsforcoFixo(string nome, int horasNecessarias);
        virtual ~AtividadeDeEsforcoFixo();
        int getHorasNecessarias();
        int getDuracao();

    protected:

    private:
        int horasNecessarias;
};

#endif // ATIVIDADEDEESFORCOFIXO_H
