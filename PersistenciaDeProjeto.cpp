#include "PersistenciaDeProjeto.h"
#include "Atividade.h"
#include "AtividadeDeEsforcoFixo.h"
#include "ErroDeArquivo.h"
#include "AtividadeDePrazoFixo.h"


PersistenciaDeProjeto::PersistenciaDeProjeto(){}

PersistenciaDeProjeto::~PersistenciaDeProjeto(){}

void PersistenciaDeProjeto::salvar(Projeto* p, string arquivo){
    ofstream output;
    unsigned int j;
    int k;
    output.open(arquivo);
    if (output.fail()){
        cout << "Deu ruim" << endl;
    }
    output << p->getNome() << "\n";
    output << p->getRecursos()->size() << "\n";
    list<Recurso*>::iterator i = p->getRecursos()->begin();
    while (i != p->getRecursos()->end()){
        Pessoa *p1 = dynamic_cast<Pessoa*>(*i);
        if (p1 != NULL) {
            if (p1->recebeValorPadrao()){
                output << "P " << p1->getNome() << " -1 " << p1->getHorasDiarias() <<"\n";
            } else {
                output << "P " << p1->getNome() << " " << p1->getValorPorHora() << " " << p1->getHorasDiarias() <<"\n";
            }
        }
        Ferramenta *f1 = dynamic_cast<Ferramenta*>(*i);
        if (f1 != NULL){
            output << "F " << f1->getNome() << " " << f1->getCustoDiario() << "\n";
        }
        i++;
    }
    vector <Atividade*>* a = p->getAtividades();
    output << a->size() << "\n";
    for (j = 0; j != a->size(); j++){
        AtividadeDeEsforcoFixo *e = dynamic_cast<AtividadeDeEsforcoFixo*>((*a)[j]);
        if (e != NULL){
            if (e->estaTerminada()){
                output << "E " << e->getNome() << " " << e->getHorasNecessarias() << " T " << e->getDuracao() << "\n";
            } else {
                output << "E " << e->getNome() << " " << e->getHorasNecessarias() << " N " << "\n";
            }
            output << e->getQuantidadeDeRecursos() << "\n";
        }
        AtividadeDePrazoFixo *p = dynamic_cast<AtividadeDePrazoFixo*>((*a)[j]);
        if (p != NULL){
            if (p->estaTerminada()){
                output << "P" <<  p->getNome() << " " << p->getPrazo() << " T " << p->getDuracao() << "\n";
            } else{
                output << "P " << p->getNome() << " " << p->getPrazo() << " N " << "\n";
            }
            output << p->getQuantidadeDeRecursos() << "\n";
        }
        for (k = 0; k !=  (*a)[j]->getQuantidadeDeRecursos(); k++){
            output << (*a)[j]->getRecursos()[k]->getNome() << " ";
        }
    }
    output << "\n";
    output.close();
}

Projeto* PersistenciaDeProjeto::carregar(string arquivo){
    ifstream input;
    input.open(arquivo);
    if (input.fail()){
        throw new ErroDeArquivo("Arquivo nao encontrado");
    }
    int numero, numerofixo, i, horas, dur, dias, k;
    double vph;
    double cd;
    string n, test;
    input >> n;
    Projeto *p = new Projeto(n);
    Pessoa *pes;
    Ferramenta *f;
    AtividadeDeEsforcoFixo *e;
    AtividadeDePrazoFixo *x;
    input >> numerofixo;
    for (i = 0; i != numerofixo; i++){
        input >> test;
        if (test == "P"){
            input >> n;
            input >> vph;
            input >> horas;
            if (vph > 0){
                pes = new Pessoa(n, vph, horas);
                p->adicionar(pes);
            } else  {
                pes = new Pessoa(n, horas);
                p->adicionar(pes);
            }
        }
        if (test == "F"){
            input >> n;
            input >> cd;
            f = new Ferramenta(n, cd);
            p->adicionar(f);
        }
    }
    input >> numerofixo;
    for (i = 0; i != numerofixo; i++){
        input >> test;
        input >> n;
        if (test == "E"){
            input >> horas;
            e = new AtividadeDeEsforcoFixo(n, horas);
            input >> test;
            if (test == "T"){
                input >> dur;
                e->terminar(dur);
            }
            input >> numero;
            for (k = 0; k != numero; k++){
                input >> n;
                list<Recurso*>::iterator j = p->getRecursos()->begin();
                while  (j != p->getRecursos()->end()){
                    if ((*j)->getNome() == n){
                        e->adicionar(*j);
                    }
                    j++;
                }
            }
            p->adicionar(e);
        } else if (test == "P"){
            input >> dias;
            x = new AtividadeDePrazoFixo(n, dias);
            input >> test;
            if (test == "T"){
                input >> dur;
                x->terminar(dur);
            }
            input >> numero;
            for (k = 0; k != numero; k++){
                input >> n;
                list<Recurso*>::iterator j = p->getRecursos()->begin();
                while  (j != p->getRecursos()->end()){
                    if ((*j)->getNome() == n){
                        x->adicionar(*j);
                    }
                    j++;
                }
            }
            p->adicionar(x);
        }
    }
    return p;
}
