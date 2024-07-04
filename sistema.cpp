#include "sistema.h"

#include <iostream>
using std::cout, std::cin, std::endl;
#include <cstdlib>

sistema::sistema() {}

sistema::~sistema() {}

void sistema::cadastrar_astronauta() {
    string cpf, nome;
    int idade;

    cout << "Digite o Nome do Astronauta: ";
    cin >> nome;
    do {
        cout << "Digite o CPF do Astronauta: ";
        cin >> cpf;
    } while (gerenteA.verificar_cpf(cpf));
    cout << "Digite a Idade do Astronauta: ";
    cin >> idade;

    gerenteA.inserir_astronauta(astronauta(cpf, nome, idade));
    cout << "Astronauta cadastrado." << endl;
}

void sistema::cadastrar_voo() {
    int opcao;
    int codigo;

    do {
        cout << "Deseja: " << endl;
        cout << "0 - Gerar codigo aleatorio." << endl;
        cout << "1 - Digitar codigo desejado." << endl;
        cin >> opcao;
    } while (opcao != 1 && opcao != 0);

    if (opcao) {
        do {
            cout << "Digite o Codigo do Voo: ";
            cin >> codigo;
        } while (gerenteV.verificar_codigo(codigo, opcao));
    } else {
        srand(time(0));

        do {
            codigo = (rand() % (1000 - 10 + 1)) + 10;
        } while (gerenteV.verificar_codigo(codigo, opcao));
    }

    gerenteV.inserir_voo(voo(codigo));
    cout << "Voo " << codigo << " cadastrado." << endl;
}

void sistema::adicionar_em_voo() {
    if (gerenteV.vazio() || gerenteA.vazio()) {
        cout << "Nao existem voos ou astronautas cadastrados." << endl;
    } else {
        int codigo;
        string cpf;

        cout << "Digite o codigo do Voo: ";
        cin >> codigo;

        voo *voo = gerenteV.encontrar_por_codigo(codigo);
        if (voo == nullptr) {
            cout << "Voo nao encontrado." << endl;
        } else {
            if ((*voo).get_planejamento()) {
                cout << "Digite o Cpf do Astronauta: ";
                cin >> cpf;

                astronauta *astronauta = gerenteA.encontrar_por_cpf(cpf);
                if (astronauta == nullptr) {
                    cout << "Astronauta nao encontrado." << endl;
                } else {
                    if ((*astronauta).get_morto()) {
                        cout << "Passageiro selecionado esta morto." << endl;
                    } else {
                        if ((*astronauta).get_disponivel()) {
                            (*voo).inserir_passageiro(astronauta);
                            cout << "Passageiro " << (*astronauta).get_nome()
                                 << " cadastrado no Voo " << codigo << "."
                                 << endl;
                        } else {
                            cout << "Passageiro indisponivel." << endl;
                        }
                    }
                }
            } else {
                cout << "O voo nao esta em planejamento." << endl;
            }
        }
    }
}

void sistema::remover_de_voo() {
    if (gerenteV.vazio() || gerenteA.vazio()) {
        cout << "Nao existem voos ou astronautas cadastrados." << endl;
    } else {
        int codigo;
        string cpf;

        cout << "Digite o codigo do Voo: ";
        cin >> codigo;

        voo *voo = gerenteV.encontrar_por_codigo(codigo);
        if (voo == nullptr) {
            cout << "Voo nao encontrado." << endl;
        } else {
            if (voo->vazio()) {
                cout << "Voo nao possui passageiros" << endl;
            } else {
                if (voo->get_planejamento() == 0) {
                    cout << "Voo fora de planejamento, nao é possivel remover "
                            "passageiro."
                         << endl;
                } else {
                    cout << "Digite o cpf do astronauta: ";
                    cin >> cpf;
                    astronauta *astronauta = gerenteA.encontrar_por_cpf(cpf);
                    if (astronauta == nullptr) {
                        cout << "Astronauta nao encontrado." << endl;
                    } else {
                        voo->remover_passageiro(astronauta);
                    }
                }
            }
        }
    }
}

void sistema::lancar_voo() {
    if (gerenteV.vazio()) {
        cout << "Nenhum voo cadastrado." << endl;
    } else {
        int codigo;

        cout << "Digite o codigo do Voo: ";
        cin >> codigo;

        voo *voo = gerenteV.encontrar_por_codigo(codigo);
        if (voo == nullptr) {
            cout << "Voo nao encontrado." << endl;
        } else {
            if ((*voo).vazio()) {
                cout << "Precisa que tenha pelo menos 1 passageiro." << endl;
            } else {
                if ((*voo).get_planejamento()) {
                    (*voo).decolar();
                } else {
                    cout << "O voo selecionado esta voando ou ja finalizou."
                         << endl;
                }
            }
        }
    }
}

void sistema::explodir_voo() {
    if (gerenteV.vazio()) {
        cout << "Nenhum voo cadastrado." << endl;
    } else {
        int codigo;

        cout << "Digite o codigo do Voo: ";
        cin >> codigo;

        voo *voo = gerenteV.encontrar_por_codigo(codigo);
        if (voo == nullptr) {
            cout << "Voo nao encontrado." << endl;
        } else {
            (*voo).explodir();
        }
    }
}

void sistema::finalizar_voo() {
    if (gerenteV.vazio()) {
        cout << "Nenhum voo cadastrado." << endl;
    } else {
        int codigo;

        cout << "Digite o codigo do Voo: ";
        cin >> codigo;

        voo *voo = gerenteV.encontrar_por_codigo(codigo);
        if (voo == nullptr) {
            cout << "Voo nao encontrado." << endl;
        } else {
            (*voo).finalizar();
        }
    }
}

void sistema::listar_voos() {
    if (gerenteV.vazio()) {
        cout << "Nenhum voo cadastrado." << endl;
    } else {
        cout << "Codigo\tPlanejamento\tExplodiu\tFinalizado" << endl;
        vector<voo> voos = gerenteV.get_lista();
        for (vector<voo>::iterator it = voos.begin(); it != voos.end(); it++) {
            cout << (*it) << endl;
            if ((*it).vazio()) {
                cout << "Sem passageiros" << endl;
            } else {
                cout << "Passageiros:" << endl;
                cout << "Cpf\tNome\tIdade\tDisponivel\tMorto" << endl;
                (*it).listar_passageiros();
            }
            cout << endl;
        }
    }
}

void sistema::listar_mortos() { gerenteA.mortos(); }
