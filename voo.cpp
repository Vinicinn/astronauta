#include "voo.h"

#include <iostream>

voo::voo() {}

voo::voo(int codigo) {
    this->codigo = codigo;
    planejamento = 1;
    explodiu = 0;
    finalizado = 0;
}

voo::~voo() {}

int voo::get_codigo() { return codigo; }

void voo::inserir_passageiro(astronauta* a) { passageiros.push_back(a); }

int voo::get_planejamento() { return planejamento; }

void voo::remover_passageiro(astronauta* a) {
    int indice = 0;
    for (vector<astronauta*>::iterator it = passageiros.begin();
         it != passageiros.end(); it++) {
        if ((*it)->get_cpf().compare((*a).get_cpf()) == 0) {
            break;
        }
        indice++;
    }
    if (indice < passageiros.size()) {
        for (int i = indice; i < passageiros.size() - 1; i++) {
            passageiros[i] = passageiros[i + 1];
        }
        passageiros.pop_back();
        std::cout << "Astronauta " << (*a).get_nome() << " removido do voo "
                  << codigo << "." << std::endl;
    } else {
        std::cout << "Astronauta informado nao esta cadastrado no voo."
                  << std::endl;
    }
}

int voo::vazio() {
    if (passageiros.size() == 0) {
        return 1;
    }
    return 0;
}

int voo::passageiros_disponiveis() {
    for (vector<astronauta*>::iterator it = passageiros.begin();
         it != passageiros.end(); it++) {
        if ((*it)->get_disponivel() == 0) {
            return 0;
        }
    }
    return 1;
}

void voo::listar_passageiros() {
    for (vector<astronauta*>::iterator it = passageiros.begin();
         it != passageiros.end(); it++) {
        std::cout << (*(*it)) << std::endl;
    }
}

void voo::decolar() {
    if (passageiros_disponiveis()) {
        for (vector<astronauta*>::iterator it = passageiros.begin();
             it != passageiros.end(); it++) {
            (*it)->set_disponivel(0);
        }
        planejamento = 0;
        std::cout << "Voo " << codigo << " lancado." << std::endl;
    } else {
        std::cout << "Todos precisam estar disponiveis." << std::endl;
    }
}

void voo::finalizar() {
    if (planejamento) {
        std::cout << "Voo nao foi lancado." << std::endl;
    } else {
        if (explodiu) {
            std::cout << "Nao é possivel finalizar um voo explodido."
                      << std::endl;
        } else {
            if (finalizado) {
                std::cout << "Voo ja foi finalizado." << std::endl;
            } else {
                for (vector<astronauta*>::iterator it = passageiros.begin();
                     it != passageiros.end(); it++) {
                    (*it)->set_disponivel(1);
                }
                finalizado = 1;
                std::cout << "Voo finalizado, passageiros disponiveis."
                          << std::endl;
            }
        }
    }
}

void voo::explodir() {
    if (planejamento) {
        std::cout << "Voo ainda em planejamento." << std::endl;
    } else {
        if (finalizado) {
            std::cout << "Voo ja finalizado." << std::endl;
        } else {
            if (explodiu) {
                std::cout << "Voo ja foi explodido." << std::endl;
            } else {
                for (vector<astronauta*>::iterator it = passageiros.begin();
                     it != passageiros.end(); it++) {
                    (*it)->set_morto();
                }
                explodiu = 1;
                std::cout << "Voo explodido, passageiros mortos." << std::endl;
            }
        }
    }
}

std::ostream& operator<<(std::ostream& o, voo const v) {
    o << v.codigo << "\t";

    if (v.planejamento) {
        o << "Sim\t\t";
    } else {
        o << "Nao\t\t";
    }

    if (v.explodiu) {
        o << "Sim\t\t";
    } else {
        o << "Nao\t\t";
    }

    if (v.finalizado) {
        o << "Sim";
    } else {
        o << "Nao";
    }
    return o;
}
