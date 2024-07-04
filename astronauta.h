#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>
using std::string;

class astronauta {
   private:
    string cpf, nome;
    int idade, disponivel, morto;

   public:
    astronauta();
    astronauta(string cpf, string nome, int idade);
    ~astronauta();

    string get_cpf();
    string get_nome();
    int get_disponivel();
    int get_morto();
    void set_disponivel(int i);
    void set_morto();

    friend std::ostream& operator<<(std::ostream& o, astronauta const a);
};

#endif