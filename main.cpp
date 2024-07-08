#include <stdio.h>
#include <unistd.h>

#include <iomanip>
#include <iostream>

#include "sistema.h"
using std::cout, std::endl, std::cin, std::setw, std::setfill, std::left,
    std::right;

void menu() {
    system("clear");

    cout << '/' << setw(59) << setfill('-') << right << '\\' << endl;

    cout << setw(5) << setfill(' ') << left << "|" << setw(50)
         << "1 - Cadastrar Astronauta." << setw(5) << right << '|' << endl;
    cout << setw(5) << setfill(' ') << left << "|" << setw(50)
         << "2 - Cadastrar Voo." << setw(5) << right << '|' << endl;
    cout << setw(5) << setfill(' ') << left << "|" << setw(50)
         << "3 - Adicionar Astronauta em Voo." << setw(5) << right << '|'
         << endl;
    cout << setw(5) << setfill(' ') << left << "|" << setw(50)
         << "4 - Remover Astronauta de um Voo." << setw(5) << right << '|'
         << endl;
    cout << setw(5) << setfill(' ') << left << '|' << setw(50)
         << "5 - Lancar um Voo." << setw(5) << right << '|' << endl;
    cout << setw(5) << setfill(' ') << left << '|' << setw(50)
         << "6 - Explodir Voo." << setw(5) << right << '|' << endl;
    cout << setw(5) << setfill(' ') << left << '|' << setw(50)
         << "7 - Finalizar um Voo." << setw(5) << right << '|' << endl;
    cout << setw(5) << setfill(' ') << left << '|' << setw(50)
         << "8 - Listar todos os Voos." << setw(5) << right << '|' << endl;
    cout << setw(5) << setfill(' ') << left << '|' << setw(50)
         << "9 - Listar todos os Astronautas mortos." << setw(5) << right << '|'
         << endl;
    cout << setw(5) << setfill(' ') << left << '|' << setw(50)
         << "0 - Encerrar." << setw(5) << right << '|' << endl;

    cout << '|' << setw(59) << setfill('-') << right << '/' << endl;
    cout << '\\' << "-> ";
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
                cout << "Aperte Enter para voltar..." << endl;
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