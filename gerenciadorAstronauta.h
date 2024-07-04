#ifndef GERENCIADOR_ASTRONAUTA_H
#define GERENCIADOR_ASTRONAUTA_H

#include <vector>
using std::vector;

#include "astronauta.h"

class gerenciadorAstronauta {
   private:
    vector<astronauta> lista_astronautas;

   public:
    gerenciadorAstronauta();
    ~gerenciadorAstronauta();

    astronauta *encontrar_por_cpf(string cpf);
    void inserir_astronauta(astronauta a);
    int verificar_cpf(string cpf);
    void mortos();
    int vazio();
};

#endif