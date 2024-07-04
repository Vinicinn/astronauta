#include "gerenciadorVoo.h"

#include <iostream>

gerenciadorVoo::gerenciadorVoo() {}

gerenciadorVoo::~gerenciadorVoo() {}

void gerenciadorVoo::inserir_voo(voo v) { lista_voos.push_back(v); }

voo *gerenciadorVoo::encontrar_por_codigo(int codigo) {
    for (vector<voo>::iterator it = lista_voos.begin(); it != lista_voos.end();
         it++) {
        if ((*it).get_codigo() == codigo) {
            return &(*it);
        }
    }
    return nullptr;
}

int gerenciadorVoo::vazio() {
    if (lista_voos.size() == 0) {
        return 1;
    }

    return 0;
}

vector<voo> gerenciadorVoo::get_lista() { return lista_voos; }

int gerenciadorVoo::verificar_codigo(int codigo, int opcao) {
    for (vector<voo>::iterator it = lista_voos.begin(); it != lista_voos.end();
         it++) {
        if ((*it).get_codigo() == codigo) {
            if (opcao) {
                std::cout << "CODIGO EM USO" << std::endl;
            }
            return 1;
        }
    }

    return 0;
}
