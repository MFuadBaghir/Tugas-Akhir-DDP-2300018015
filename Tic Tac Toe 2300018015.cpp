#include <iostream>
using namespace std;

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int win() {
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

void papan() {
    system("cls");
    cout << "       Tic Tac Toe" << endl
         << endl;
    cout << "Player 1 (X) - Player 2 (O)" << endl;
    cout << endl;

    cout << "_______________________" << endl;
    cout << "|     |       |       |" << endl;
    cout << "|  " << square[1] << "  |   " << square[2] << "   |   " << square[3] << "   |   " << endl;
    cout << "|_____|_______|_______|" << endl;
    cout << "|     |       |       |" << endl;

    cout << "|  " << square[4] << "  |   " << square[5] << "   |   " << square[6] << "   |   " << endl;
    cout << "|_____|_______|_______|" << endl;
    cout << "|     |       |       |" << endl;

    cout << "|  " << square[7] << "  |   " << square[8] << "   |   " << square[9] << "   |   " << endl;
    cout << "|_____|_______|_______|" << endl;
}

int main() {
    int player = 1;
    int pilihan;
    int i;
    char tanda;

    do {
        // Reset the board for a new game
        for (int j = 1; j <= 9; ++j) {
            square[j] = '0' + j;
        }

        do {
            papan();
            player = (player % 2) ? 1 : 2;
            cout << "Player " << player << ", Masukkan angka : ";
            cin >> pilihan;

            tanda = (player == 1) ? 'X' : 'O';
            if (pilihan >= 1 && pilihan <= 9 && square[pilihan] == '0' + pilihan) {
                square[pilihan] = tanda;
                player++;
            } else {
                cout << "Pilihan tidak valid, coba lagi." << endl;
                cin.ignore();
                cin.get();
            }

            i = win();
        } while (i == -1);

        papan();
        if (i == 1) {
            cout << "Player " << --player << " Wins!" << endl;
        } else {
            cout << "Game Draw" << endl;
        }

        cout << "Ingin bermain lagi? (y/n): ";
        char playAgain;
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            break;  
        }
    } while (true);

    return 0;
}

