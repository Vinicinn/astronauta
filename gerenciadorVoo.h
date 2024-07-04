#ifndef GERENCIADOR_VOO_H
#define GERENCIADOR_VOO_H

#include "voo.h"

class gerenciadorVoo {
   private:
    vector<voo> lista_voos;

   public:
    gerenciadorVoo();
    ~gerenciadorVoo();
    void inserir_voo(voo v);
    voo *encontrar_por_codigo(int codigo);
    int vazio();
    vector<voo> get_lista();
    int verificar_codigo(int codigo, int opcao);
};

#endif