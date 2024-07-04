#include "astronauta.h"

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
    o << a.cpf << "\t" << a.nome << "\t" << a.idade << "\t";

    if (a.disponivel) {
        o << "Sim\t\t";
    } else {
        o << "Nao\t\t";
    }

    if (a.morto) {
        o << "Sim";
    } else {
        o << "Nao";
    }

    return o;
}
