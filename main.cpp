#include <unistd.h>
#include <stdio.h>

#include <iostream>

#include "sistema.h"
using std::cout, std::endl, std::cin;

// IMPRESSAO DO MENU DE SELECAO
void menu() {
    system("clear");
    cout << "1 - Cadastrar Astronauta." << endl;                // OK
    cout << "2 - Cadastrar Voo." << endl;                       // OK
    cout << "3 - Adicionar Astronauta em Voo." << endl;         // OK
    cout << "4 - Remover Astronauta de um Voo." << endl;        // OK
    cout << "5 - Lancar um Voo." << endl;                       // OK
    cout << "6 - Explodir Voo." << endl;                        // NOK
    cout << "7 - Finalizar um Voo" << endl;                     // NOK
    cout << "8 - Listar todos os Voos." << endl;                // NOK
    cout << "9 - Listar todos os Astronautas mortos." << endl;  // NOK
    cout << "0 - Encerrar." << endl;                            // OK
}

int main() {
    int opcao;
    sistema sistema;

    do {
        menu();
        cin >> opcao;

        switch (opcao) {
            case 1:
                system("clear");
                sistema.cadastrar_astronauta();
                sleep(3);
                break;
            case 2:
                system("clear");
                sistema.cadastrar_voo();
                sleep(3);
                break;
            case 3:
                system("clear");
                sistema.adicionar_em_voo();
                sleep(3);
                break;
            case 4:
                system("clear");
                sistema.remover_de_voo();
                sleep(3);
                break;
            case 5:
                system("clear");
                sistema.lancar_voo();
                sleep(3);
                break;
            case 6:
                system("clear");
                sistema.explodir_voo();
                sleep(3);
                break;
            case 7:
                system("clear");
                sistema.finalizar_voo();
                sleep(3);
                break;
            case 8:
                system("clear");
                sistema.listar_voos();
                cout << "Aperte qualquer tecla para voltar..." << endl;
                getchar();
                getchar();
                break;
            case 9:
                system("clear");
                sistema.listar_mortos();
                sleep(3);
                break;
        }
    } while (opcao != 0);

    return 0;
}