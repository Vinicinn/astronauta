#include "gerenciadorAstronauta.h"

#include <iostream>

gerenciadorAstronauta::gerenciadorAstronauta() {}

gerenciadorAstronauta::~gerenciadorAstronauta() {}

astronauta *gerenciadorAstronauta::encontrar_por_cpf(string cpf) {
    for (vector<astronauta>::iterator it = lista_astronautas.begin();
         it != lista_astronautas.end(); it++) {
        if ((*it).get_cpf().compare(cpf) == 0) {
            return &(*it);
        }
    }
    return nullptr;
}

void gerenciadorAstronauta::inserir_astronauta(astronauta a) {
    lista_astronautas.push_back(a);
}

int gerenciadorAstronauta::verificar_cpf(string cpf) {
    for (vector<astronauta>::iterator it = lista_astronautas.begin();
         it != lista_astronautas.end(); it++) {
        if ((*it).get_cpf().compare(cpf) == 0) {
            std::cout << "CPF EM USO." << std::endl;
            return 1;
        }
    }
    return 0;
}

void gerenciadorAstronauta::mortos() {
    for (vector<astronauta>::iterator it = lista_astronautas.begin();
         it != lista_astronautas.end(); it++) {
        if ((*it).get_morto()) {
            std::cout << (*it) << std::endl;
        }
    }
}

int gerenciadorAstronauta::vazio() {
    if (lista_astronautas.size() == 0) {
        return 1;
    }
    return 0;
}
