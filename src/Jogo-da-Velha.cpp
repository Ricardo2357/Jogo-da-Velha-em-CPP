#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void Tabuleiro (const vector <char> & Casa) {
    cout << " " << Casa [0] << " | " << Casa [1] << " | "  << Casa [2] << endl;
    cout << "-----------" << endl;
    cout << " " << Casa [3] << " | " << Casa [4] << " | "  << Casa [5] << endl;
    cout << "-----------" << endl;
    cout << " " << Casa [6] << " | " << Casa [7] << " | "  << Casa [8] << endl;
}

void Jogada (vector <char> & Casa, int Ordem, char Jogador) {
    
    char Escolha;

    cout << "Jogador " << Ordem << " (" << Jogador << "), escolha uma posicao: ";

    bool Validez = false;

    while (!Validez) {

        cin >> Escolha;
        cout << endl;

        for (int i = 0; i < 9; i++) {
            if (Casa [i] == Escolha) {
                Casa [i] = Jogador;
                Validez = true;
                break;
            }
        }

        if (!Validez) {
            cout << "Posicao invalida ou ja ocupada! Escolha outra posicao." << endl;
        }
    }
}

bool Vencer (char Jogador, const vector <char> & Casa) {
    if (Casa [0] == Jogador && Casa [1] == Jogador && Casa [2] == Jogador) {
        return true;
    } else if  (Casa [3] == Jogador && Casa [4] == Jogador && Casa [5] == Jogador) {
        return true;
    } else if (Casa [6] == Jogador && Casa [7] == Jogador && Casa [8] == Jogador) {
        return true;
    } else if (Casa [0] == Jogador && Casa [3] == Jogador && Casa [6] == Jogador) {
        return true;
    } else if (Casa [1] == Jogador && Casa [4] == Jogador && Casa [7] == Jogador) {
        return true;
    } else if (Casa [2] == Jogador && Casa [5] == Jogador && Casa [8] == Jogador) {
        return true;
    } else if (Casa [0] == Jogador && Casa [4] == Jogador && Casa [8] == Jogador) {
        return true;
    } else if (Casa [2] == Jogador && Casa [4] == Jogador && Casa [6] == Jogador) {
        return true;
    } else {
        return false;
    }
}

int main () {

    char Continuar = 'S';

    while (Continuar == 'S') {

        vector <char> Casa = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        Tabuleiro (Casa);

        Jogada (Casa, 1, 'X');

        Tabuleiro (Casa); 

        Jogada (Casa, 2, 'O');

        Tabuleiro (Casa); 

        Jogada (Casa, 1, 'X');

        Tabuleiro (Casa); 

        Jogada (Casa, 2, 'O');

        Tabuleiro (Casa); 

        Jogada (Casa, 1, 'X');

        if (Vencer ('X', Casa)) {
            Tabuleiro (Casa);
            cout << "Parabens! Jogador 1 venceu!" << endl;
            cout << "Deseja jogar novamente? (S/N): ";
            cin >> Continuar;
            system("cls");
            continue;
        } 

        Tabuleiro (Casa);

        Jogada (Casa, 2, 'O');

        Tabuleiro (Casa); 

        if (Vencer ('O', Casa)) {
            cout << "Parabens! Jogador 2 venceu!" << endl;
            cout << "Deseja jogar novamente? (S/N): ";
            cin >> Continuar;
            system("cls");
            continue;
        } 

        Jogada (Casa, 1, 'X');

        Tabuleiro (Casa);

        if (Vencer ('X', Casa)) {
            cout << "Parabens! Jogador 1 venceu!" << endl;
            cout << "Deseja jogar novamente? (S/N): ";
            cin >> Continuar;
            system("cls");
            continue;
        } 

        Jogada (Casa, 2, 'O');

        Tabuleiro (Casa);

        if (Vencer ('O', Casa)) {
            cout << "Parabens! Jogador 2 venceu!" << endl;
            cout << "Deseja jogar novamente? (S/N): ";
            cin >> Continuar;
            system("cls");
            continue;
        } 

        Jogada (Casa, 1, 'X');

        Tabuleiro (Casa);

        if (Vencer ('X', Casa)) {
            cout << "Parabens! Jogador 1 venceu!" << endl;
            cout << "Deseja jogar novamente? (S/N): ";
            cin >> Continuar;
            system("cls");
            continue;
        } else {
            Tabuleiro (Casa);
            cout << "Empate! Nenhum jogador venceu." << endl;
            cout << "Deseja jogar novamente? (S/N): ";
            cin >> Continuar;
            system("cls");
            continue;
        }

    }
    return 0;
}
