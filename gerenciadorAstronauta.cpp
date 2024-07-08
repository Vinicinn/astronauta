#include "gerenciadorAstronauta.h"

#include <unistd.h>

#include <iomanip>
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
            std::cout << "\033[F";
            std::cout << '|' << std::setw(17) << std::right << "-> CPF EM USO"
                      << std::endl;
            sleep(3);
            return 1;
        }
    }
    return 0;
}

void gerenciadorAstronauta::mortos() {
    int verificar = 1;
    for (vector<astronauta>::iterator it = lista_astronautas.begin();
         it != lista_astronautas.end(); it++) {
        if ((*it).get_morto()) {
            if (verificar) {
                verificar = 0;
            }
            std::cout << (*it) << std::endl;
        }
    }
    if (verificar) {
        std::cout << '/' << std::setw(59) << std::setfill('-') << std::right
                  << '\\' << std::endl;
        std::cout << std::setw(5) << std::setfill(' ') << std::left << "|"
                  << std::setw(50) << "Nenhum astronauta morto." << std::setw(5)
                  << std::right << '|' << std::endl;
        std::cout << '\\' << std::setw(59) << std::setfill('-') << std::right
                  << '/' << std::endl;
    }
}

int gerenciadorAstronauta::vazio() {
    if (lista_astronautas.size() == 0) {
        return 1;
    }
    return 0;
}
