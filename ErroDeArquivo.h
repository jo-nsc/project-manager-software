#ifndef ERRODEARQUIVO_H
#define ERRODEARQUIVO_H
#include <iostream>
#include <stdexcept>
using namespace std;


class ErroDeArquivo : public logic_error
{
    public:
        ErroDeArquivo(string mensagem);
        virtual ~ErroDeArquivo();

    protected:

    private:
};

#endif // ERRODEARQUIVO_H
