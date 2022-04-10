#include <iostream>
#include "Projeto.h"
#include "PersistenciaDeProjeto.h"
#include "AtividadeDeEsforcoFixo.h"
#include "AtividadeDePrazoFixo.h"
#include "Atividade.h"

using namespace std;
void printRecursos(Projeto *p);
int main()
{
    string resposta = "0", arquivo, nome;
    int test, y, z;
    int i;
    double x;
    Projeto *p = new Projeto("LIXO");
    while (resposta != "s" && resposta != "n" ){
        cout << "Deseja carregar um novo projeto (s/n) ? ";
        cin >> resposta;
    }
    if (resposta == "s"){
        cout << "Digite o nome do arquivo: ";
        cin >> arquivo;
        PersistenciaDeProjeto *per = new PersistenciaDeProjeto();
        p = per->carregar(arquivo);
    }
    if (resposta == "n"){
        cout << "Digite o nome do Projeto: ";
        cin >> nome;
        p = new Projeto(nome);
    }
    do {
        cout << "1 - Adicionar recurso" << endl;
        cout << "2 - Adicionar atividade" << endl;
        cout << "3 - Terminar atividade" << endl;
        cout << "4 - Imprimir projeto" << endl;
        cout << "5 - Definir valor por hora padrao" << endl;
        cout << "6 - Salvar" << endl;
        cout << "0 - Sair" << endl;
        cin >> test;
        if (test == 1){
            cout << "Ferramenta (f) ou Pessoa (p): ";
            cin >> resposta;
            if (resposta == "f"){
                cout << "Nome: ";
                cin >> nome;
                cout << "Custo diario: ";
                cin >> x;
                Ferramenta *f = new Ferramenta(nome, x);
                p->adicionar(f);
            }
            if (resposta == "p"){
                cout << "Nome: ";
                cin >> nome;
                cout << "Horas diarias: ";
                cin >> y;
                resposta = "0";
                while (resposta != "s" && resposta != "n"){
                    cout << "Valor por hora padrao (s/n) ? ";
                    cin >> resposta;
                    if (resposta == "s"){
                        Pessoa *p1 = new Pessoa(nome, y);
                        p->adicionar(p1);
                    }
                    if (resposta == "n"){
                        cout << "Valor por hora (em R$): ";
                        cin >> x;
                        Pessoa *p1 = new Pessoa(nome, x, y);
                        p->adicionar(p1);
                    }
                }
            }
        }
        if (test == 2){
            cout << "Nome: ";
            cin >> nome;
            cout << "Prazo fixo (p) ou trabalho fixo (t) ? ";
            cin >> resposta;
            if (resposta == "p"){
                cout << "Dias necessarios: ";
                cin >> y;
                AtividadeDePrazoFixo *a = new AtividadeDePrazoFixo(nome, y);
                do {
                    cout << "Deseja adicionar um recurso (s/n) ? ";
                    cin >> resposta;
                    if (resposta == "s"){
                        printRecursos(p);
                        cout << "Escolha um recurso ou 0 para cancelar ";
                        i = 1;
                        cin >> y;
                        if (y > 0 && y <= (int)p->getRecursos()->size()){
                            list<Recurso*>::iterator k = p->getRecursos()->begin();
                            while (y != i){
                                i++;
                                k++;
                            }
                            try {
                                a->adicionar(*k);
                            } catch (invalid_argument *e){
                                cout << "Erro: " << e->what();
                                delete e;
                            } catch (overflow_error *o){
                                cout << "Erro: " << o->what();
                                delete o;
                            }
                        } else{
                            cout << "Nao foi possivel adicionar recurso" << endl;
                        }
                    }
                } while (resposta != "n");
                p->adicionar(a);
            }
            if (resposta == "t"){
                cout << "Horas necessarias: ";
                cin >> y;
                AtividadeDePrazoFixo *a = new AtividadeDePrazoFixo(nome, y);
                do {
                    cout << "Deseja adicionar um recurso (s/n) ? ";
                    cin >> resposta;
                    if (resposta == "s"){
                        printRecursos(p);
                        cout << "Escolha um recurso ou 0 para cancelar ";
                        i = 1;
                        cin >> y;
                        if (y > 0){
                            list<Recurso*>::iterator k = p->getRecursos()->begin();
                            while (y != i){
                                i++;
                                k++;
                            }
                            a->adicionar(*k);
                        }
                    }
                } while (resposta != "n");
                p->adicionar(a);
            }
        }
        if (test == 3){
            vector<Atividade*>* atividades = p->getAtividades();
            for (i = 0; i != (int)atividades->size(); i++){
                cout << i + 1 << " - " << (*atividades)[i]->getNome() << endl;
            }
            cout << "Escolha uma atividade ou 0 para cancelar: ";
            cin >> z;
            if ((*atividades)[z - 1]->estaTerminada()){
                cout << "Atividade ja terminada" << endl;
            } else {
                cout << "Duracao real: ";
                cin >> y;
                (*atividades)[z - 1]->terminar(y);
            }
        }
        if (test == 4){
            p->imprimir();
        }
        if (test == 5){
            cout << "Valor atual R$" << Pessoa::getValorPorHoraPadrao() << "por hora" << endl;
            cout << "Novo valor: ";
            cin >> x;
            Pessoa::setValorPorHoraPadrao(x);
        }
        if (test == 6){
            cout << "Nome do arquivo: ";
            cin >> arquivo;
            PersistenciaDeProjeto *per = new PersistenciaDeProjeto();
            per->salvar(p, arquivo);
        }


    } while (test != 0);
    cout << "Obrigado por ultilizar meu software, ate a proxima" << endl;
    return 0;
}

void printRecursos(Projeto *p){
    int j = 1;
    list<Recurso*>::iterator i = p->getRecursos()->begin();
    while (i != p->getRecursos()->end()){
        cout << j << " - ";
        (*i)->imprimir();
        j++;
        i++;
    }
}
