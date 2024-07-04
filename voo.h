#ifndef VOO_H
#define VOO_H

#include <vector>
using std::vector;

#include "astronauta.h"

class voo {
   private:
    int codigo, planejamento, explodiu, finalizado;
    vector<astronauta*> passageiros;

   public:
    voo();
    voo(int codigo);
    ~voo();

    int get_codigo();
    int get_planejamento();

    void inserir_passageiro(astronauta* a);
    void remover_passageiro(astronauta* a);
    void decolar();
    void finalizar();
    void explodir();
    int vazio();
    int passageiros_disponiveis();

    void listar_passageiros();

    friend std::ostream& operator<<(std::ostream& o, voo const v);
};

#endif