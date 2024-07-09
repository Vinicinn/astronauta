#include "sistema.h"

#include <cstdlib>
#include <iomanip>
#include <iostream>
using std::cout, std::cin, std::endl, std::setw, std::setfill, std::left,
    std::right;

sistema::sistema() {}

sistema::~sistema() {}

void sistema::cadastrar_astronauta() {
    string cpf, nome;
    int idade;

    cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
    cout << setw(5) << setfill(' ') << left << '|' << setw(50)
         << "Digite o Nome do Astronauta:" << setw(5) << right << '|' << endl;
    ;
    cout << '|' << setw(7) << right << "-> ";

    cin >> nome;

    cout << "\033[F";
    cout << '|' << setw(7) << right << "-> " << nome << setw(52 - nome.size())
         << right << '|' << endl;

    cout << setw(5) << setfill(' ') << left << '|' << setw(50)
         << "Digite o CPF do Astronauta:" << setw(5) << right << '|' << endl;
    cout << " " << endl;

    do {
        cout << "\033[F";
        cout << setw(50) << setfill(' ') << right << ' ' << endl;
        cout << "\033[F";
        cout << '|' << setw(7) << right << "-> ";

        cin >> cpf;

        cout << "\033[F";
        cout << '|' << setw(7) << right << "-> " << cpf << setw(42 - cpf.size())
             << right << '|' << endl;

    } while (gerenteA.verificar_cpf(cpf));

    cout << "\033[F";
    cout << '|' << setw(7) << right << "-> " << cpf << setw(52 - cpf.size())
         << right << '|' << endl;

    cout << setw(5) << setfill(' ') << left << '|' << setw(50)
         << "Digite a Idade do Astronauta:" << setw(5) << right << '|' << endl;
    cout << '|' << setw(7) << right << "-> ";

    cin >> idade;

    cout << "\033[F";
    cout << '|' << setw(7) << right << "-> " << idade
         << setw(52 - std::to_string(idade).size()) << right << '|' << endl;
    cout << '|' << setw(59) << setfill('-') << right << '/' << endl;
    cout << '\\' << "-> ";

    gerenteA.inserir_astronauta(astronauta(cpf, nome, idade));
    cout << "Astronauta cadastrado." << endl;
}

void sistema::cadastrar_voo() {
    int opcao;
    int codigo;

    do {
        system("clear");
        cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "Deseja:" << setw(5) << right << '|' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "0 - Gerar codigo aleatorio." << setw(5) << right << '|'
             << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "1 - Digitar codigo desejado." << setw(5) << right << '|'
             << endl;
        cout << '|' << setw(59) << setfill('-') << right << '/' << endl;
        cout << '\\' << "-> ";
        cin >> opcao;
    } while (opcao != 1 && opcao != 0);

    if (opcao) {
        cout << "\033[F";
        cout << "\033[F";
        cout << '|' << setw(59) << setfill('-') << right << '|' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "Digite o Codigo do Voo:" << setw(5) << right << '|' << endl;
        cout << " " << endl;
        do {
            cout << "\033[F";
            cout << setw(50) << setfill(' ') << right << ' ' << endl;
            cout << "\033[F";
            cout << '|' << setw(7) << right << "-> ";

            cin >> codigo;

            cout << "\033[F";
            cout << '|' << setw(7) << right << "-> " << codigo
                 << setw(52 - std::to_string(codigo).size()) << right << '|'
                 << endl;

        } while (gerenteV.verificar_codigo(codigo, opcao));
        cout << '|' << setw(59) << setfill('-') << right << '/' << endl;
    } else {
        srand(time(0));

        do {
            codigo = (rand() % (1000 - 10 + 1)) + 10;
        } while (gerenteV.verificar_codigo(codigo, opcao));
        cout << "\033[F";
    }

    gerenteV.inserir_voo(voo(codigo));
    cout << '\\' << "-> Voo " << codigo << " cadastrado." << std::flush;
}

void sistema::adicionar_em_voo() {
    if (gerenteV.vazio() || gerenteA.vazio()) {
        cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "Nao existem voos ou astronautas cadastrados." << setw(5)
             << right << '|' << endl;
        cout << '\\' << setw(59) << setfill('-') << right << '/' << endl;
    } else {
        int codigo;
        string cpf;

        cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "Digite o codigo do Voo:" << setw(5) << right << '|' << endl;
        cout << '|' << setw(7) << right << "-> ";

        cin >> codigo;

        cout << "\033[F";
        cout << '|' << setw(7) << right << "-> " << codigo
             << setw(52 - std::to_string(codigo).size()) << right << '|'
             << endl;

        voo *voo = gerenteV.encontrar_por_codigo(codigo);
        if (voo == nullptr) {
            cout << '|' << setw(59) << setfill('-') << right << '/' << endl;
            cout << '\\' << "-> Voo nao encontrado." << std::flush;
        } else {
            if ((*voo).get_planejamento()) {
                cout << setw(5) << setfill(' ') << left << "|" << setw(50)
                     << "Digite o Cpf do Astronauta:" << setw(5) << right << '|'
                     << endl;
                cout << '|' << setw(7) << right << "-> ";

                cin >> cpf;

                cout << "\033[F";
                cout << '|' << setw(7) << right << "-> " << cpf
                     << setw(52 - cpf.size()) << right << '|' << endl;
                cout << '|' << setw(59) << setfill('-') << right << '/' << endl;

                astronauta *astronauta = gerenteA.encontrar_por_cpf(cpf);
                if (astronauta == nullptr) {
                    cout << '\\' << "-> Astronauta nao encontrado."
                         << std::flush;
                } else {
                    if ((*astronauta).get_morto()) {
                        cout << '\\' << "-> Passageiro selecionado esta morto."
                             << std::flush;
                    } else {
                        if ((*astronauta).get_disponivel()) {
                            cout << '\\' << "-> ";
                            (*voo).inserir_passageiro(astronauta);
                            cout << "Passageiro " << (*astronauta).get_nome()
                                 << " cadastrado no Voo " << codigo << "."
                                 << endl;
                        } else {
                            cout << '\\' << "-> Passageiro indisponivel."
                                 << std::flush;
                        }
                    }
                }
            } else {
                cout << '|' << setw(59) << setfill('-') << right << '/' << endl;
                cout << '\\' << "-> O voo nao esta em planejamento."
                     << std::flush;
            }
        }
    }
}

void sistema::remover_de_voo() {
    if (gerenteV.vazio() || gerenteA.vazio()) {
        cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "Nao existem voos ou astronautas cadastrados." << setw(5)
             << right << '|' << endl;
        cout << '\\' << setw(59) << setfill('-') << right << '/' << endl;
    } else {
        int codigo;
        string cpf;

        cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "Digite o codigo do Voo:" << setw(5) << right << '|' << endl;
        cout << '|' << setw(7) << right << "-> ";

        cin >> codigo;

        cout << "\033[F";
        cout << '|' << setw(7) << right << "-> " << codigo
             << setw(52 - std::to_string(codigo).size()) << right << '|'
             << endl;

        voo *voo = gerenteV.encontrar_por_codigo(codigo);
        cout << '|' << setw(59) << setfill('-') << right << '/' << endl;
        if (voo == nullptr) {
            cout << '\\' << "-> Voo nao encontrado." << std::flush;
        } else {
            if (voo->vazio()) {
                cout << '\\' << "-> Voo nao possui passageiros" << std::flush;
            } else {
                if (voo->get_planejamento() == 0) {
                    cout << '\\'
                         << "-> Voo fora de planejamento, nao é possivel "
                            "remover "
                            "passageiro."
                         << std::flush;

                } else {
                    cout << "\033[F";
                    cout << setw(5) << setfill(' ') << left << "|" << setw(50)
                         << "Digite o Cpf do Astronauta:" << setw(5) << right
                         << '|' << endl;
                    cout << '|' << setw(7) << right << "-> ";

                    cin >> cpf;

                    cout << "\033[F";
                    cout << '|' << setw(7) << right << "-> " << cpf
                         << setw(52 - cpf.size()) << right << '|' << endl;
                    cout << '|' << setw(59) << setfill('-') << right << '/'
                         << endl;

                    astronauta *astronauta = gerenteA.encontrar_por_cpf(cpf);

                    if (astronauta == nullptr) {
                        cout << '\\' << "-> Astronauta nao encontrado."
                             << std::flush;
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
        cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "Nenhum voo cadastrado." << setw(5) << right << '|' << endl;
        cout << '\\' << setw(59) << setfill('-') << right << '/' << endl;
    } else {
        int codigo;

        cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "Digite o codigo do Voo:" << setw(5) << right << '|' << endl;
        cout << '|' << setw(7) << right << "-> ";

        cin >> codigo;

        cout << "\033[F";
        cout << '|' << setw(7) << right << "-> " << codigo
             << setw(52 - std::to_string(codigo).size()) << right << '|'
             << endl;

        voo *voo = gerenteV.encontrar_por_codigo(codigo);

        cout << '|' << setw(59) << setfill('-') << right << '/' << endl;

        if (voo == nullptr) {
            cout << '\\' << "-> Voo nao encontrado." << std::flush;
        } else {
            if ((*voo).vazio()) {
                cout << '\\' << "-> Necessario pelo menos 1 passageiro."
                     << std::flush;
            } else {
                if ((*voo).get_planejamento()) {
                    (*voo).decolar();
                } else {
                    cout << '\\'
                         << "-> O voo selecionado esta voando ou ja finalizou."
                         << std::flush;
                }
            }
        }
    }
}

void sistema::explodir_voo() {
    if (gerenteV.vazio()) {
        cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "Nenhum voo cadastrado." << setw(5) << right << '|' << endl;
        cout << '\\' << setw(59) << setfill('-') << right << '/' << endl;
    } else {
        int codigo;

        cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "Digite o codigo do Voo:" << setw(5) << right << '|' << endl;
        cout << '|' << setw(7) << right << "-> ";

        cin >> codigo;

        cout << "\033[F";
        cout << '|' << setw(7) << right << "-> " << codigo
             << setw(52 - std::to_string(codigo).size()) << right << '|'
             << endl;

        voo *voo = gerenteV.encontrar_por_codigo(codigo);
        cout << '|' << setw(59) << setfill('-') << right << '/' << endl;
        if (voo == nullptr) {
            cout << '\\' << "-> Voo nao encontrado." << std::flush;
        } else {
            (*voo).explodir();
        }
    }
}

void sistema::finalizar_voo() {
    if (gerenteV.vazio()) {
        cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "Nenhum voo cadastrado." << setw(5) << right << '|' << endl;
        cout << '\\' << setw(59) << setfill('-') << right << '/' << endl;
    } else {
        int codigo;

        cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "Digite o codigo do Voo:" << setw(5) << right << '|' << endl;
        cout << '|' << setw(7) << right << "-> ";

        cin >> codigo;

        cout << "\033[F";
        cout << '|' << setw(7) << right << "-> " << codigo
             << setw(52 - std::to_string(codigo).size()) << right << '|'
             << endl;

        voo *voo = gerenteV.encontrar_por_codigo(codigo);
        cout << '|' << setw(59) << setfill('-') << right << '/' << endl;
        if (voo == nullptr) {
            cout << '\\' << "-> Voo nao encontrado." << std::flush;
        } else {
            (*voo).finalizar();
        }
    }
}

void sistema::listar_voos() {
    if (gerenteV.vazio()) {
        cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "Nenhum voo cadastrado." << setw(5) << right << '|' << endl;
        cout << '\\' << setw(59) << setfill('-') << right << '/' << endl;
    } else {
        cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(10) << "Codigo"
             << setw(15) << "Planejamento" << setw(13) << "Explodiu" << setw(12)
             << "Finalizado" << setw(5) << right << '|' << endl;
        cout << '|' << setw(59) << setfill('-') << right << '|' << endl;

        vector<voo> voos = gerenteV.get_lista();

        for (vector<voo>::iterator it = voos.begin(); it != voos.end(); it++) {
            cout << (*it) << endl;
            cout << setw(10) << setfill(' ') << left << "|" << setw(12) << "CPF"
                 << setw(13) << "Nome" << setw(6) << "Idade" << setw(11)
                 << "Disponivel" << setw(5) << "Morto" << setw(3) << right
                 << '|' << endl;
            if ((*it).vazio()) {
                cout << "|" << setw(6) << right << '\\' << setw(52) << left
                     << "-> Sem passageiros" << '|';
            } else {
                (*it).listar_passageiros();
            }
            cout << endl;
        }
        cout << '\\' << setw(59) << setfill('-') << right << '/' << endl;
        cout << '\\' << "-> ";
    }
}

void sistema::listar_mortos() {
    if (gerenteA.vazio()) {
        cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(50)
             << "Nenhum astronauta cadastrado." << setw(5) << right << '|'
             << endl;
        cout << '\\' << setw(59) << setfill('-') << right << '/' << endl;
    } else {
        cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;
        cout << setw(5) << setfill(' ') << left << "|" << setw(12) << "CPF"
             << setw(13) << "Nome" << setw(6) << "Idade" << setw(11)
             << "Disponivel" << setw(5) << "Morto" << setw(8) << right << '|'
             << endl;
        cout << '|' << setw(59) << setfill('-') << right << '|' << endl;
        gerenteA.mortos();
        cout << '\\' << setw(59) << setfill('-') << right << '/' << endl;
    }
}
