#include "astronauta.h"

#include <iomanip>
#include <iostream>

astronauta::astronauta() {}

astronauta::astronauta(string cpf, string nome, int idade) {
    this->cpf = cpf;
    this->nome = nome;
    this->idade = idade;
    this->disponivel = 1;
    this->morto = 0;
}

astronauta::~astronauta() {}

string astronauta::get_cpf() { return cpf; }

int astronauta::get_disponivel() { return disponivel; }

int astronauta::get_morto() { return morto; }

void astronauta::set_disponivel(int i) { disponivel = i; }

void astronauta::set_morto() { morto = 1; }

string astronauta::get_nome() { return nome; }

std::ostream& operator<<(std::ostream& o, astronauta const a) {
    o << std::setw(12) << std::setfill(' ') << a.cpf << std::setw(13) << a.nome
      << std::setw(6) << a.idade;

    if (a.disponivel) {
        o << std::setw(11) << "Sim";
    } else {
        o << std::setw(11) << "Nao";
    }

    if (a.morto) {
        o << std::setw(5) << "Sim";
    } else {
        o << std::setw(5) << "Nao";
    }

    return o << std::setw(3) << std::right << "|";
}
