#include "AtividadeDePrazoFixo.h"
#include <stdexcept>

AtividadeDePrazoFixo::AtividadeDePrazoFixo(string nome, int dias) : Atividade(nome)
{
    if (dias <= 0){
        throw new invalid_argument ("N de dias invalido");
    }
    prazo = dias;
}

AtividadeDePrazoFixo::~AtividadeDePrazoFixo()
{
    //dtor
}
int AtividadeDePrazoFixo::getPrazo(){
    return prazo;

}

int AtividadeDePrazoFixo::getDuracao(){
    if (!(terminada)){
        return prazo;
    }
    return duracaoReal;
}
