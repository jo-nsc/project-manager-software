#include "Recurso.h"
using namespace std;

Recurso::Recurso(string nome) : nome(nome)
{
}

Recurso::~Recurso()
{
}
 string Recurso::getNome()
{
    return nome;
}
