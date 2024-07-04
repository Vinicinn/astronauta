#ifndef SISTEMA_H
#define SISTEMA_H

#include "gerenciadorAstronauta.h"
#include "gerenciadorVoo.h"

class sistema {
   private:
    gerenciadorAstronauta gerenteA;
    gerenciadorVoo gerenteV;

   public:
    sistema();
    ~sistema();

    void cadastrar_astronauta();
    void cadastrar_voo();
    void adicionar_em_voo();
    void remover_de_voo();
    void lancar_voo();
    void explodir_voo();
    void finalizar_voo();
    void listar_voos();
    void listar_mortos();
};

#endif