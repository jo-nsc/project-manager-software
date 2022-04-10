#include "ErroDeArquivo.h"
#include <stdexcept>

ErroDeArquivo::ErroDeArquivo(string mensagem) : logic_error(mensagem)
{
}

ErroDeArquivo::~ErroDeArquivo()
{
    //dtor
}
