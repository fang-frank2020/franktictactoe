
//Frank's tic tac toe game made in c++

#include <iostream>
using namespace std;

const int SIZE = 3;
void printboard(char arr[][SIZE]);
void welcomescreen();
void getTurn(char arr[][SIZE]);
bool gamefinish(char arr[][SIZE]);
bool isFull(char arr[][SIZE]);

int main() {
    char arr[SIZE][SIZE] = {};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[i][j] = ' ';
        }
    }
    welcomescreen();
    printboard(arr);
    getTurn(arr);
    return 0;
}

void welcomescreen() {
    cout << "Welcome to Frank's tic tac toe game!" << endl;
    cout << "------------------------------------" << endl;
    cout << "Enter moves with letter than number(ex. \"A 0\")" << endl;
    cout << "X will be player 1 and O will be player 2" << endl;
    cout << "To win, you must get three in a row. Good Luck!" << endl;
    cout << endl;
}

void printboard(char arr[][SIZE]) {
    cout << "     A   B   C" << endl;
    cout << "   -------------" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i << "  | ";
        for (int j = 0; j < SIZE; j++) {
            cout << arr[i][j] << " | ";
        }
        cout << endl;
        cout << "   -------------";
        cout << endl;
    }
}


void getTurn(char arr[][SIZE]) {
    bool player1turn = true;
    while (!gamefinish(arr) && !isFull(arr)) {
        int row;
        char col;
        int columnnumber;
        if (player1turn) {
            cout << "Player 1's turn: ";
        }
        else {
            cout << "Player 2's turn: ";
        }
        cin >> col >> row;
        cout << endl;
        if (col == 'A') {
            columnnumber = 0;
        }
        else if (col == 'B') {
            columnnumber = 1;
        }
        else {
            columnnumber = 2;
        }
        if (player1turn) {
            arr[row][columnnumber] = 'X';
            player1turn = false;
        }
        else {
            arr[row][columnnumber] = 'O';
            player1turn = true;
        }
        printboard(arr);
        cout << endl;
    }
    if (gamefinish(arr)) {
        if (player1turn) {
            cout << "GAME OVER. Player 2 won!";
        }
        else {
            cout << "GAME OVER. Player 1 won!";
        }
    }
    else if (isFull(arr)) {
        cout << "GAME OVER. There is a tie.";
    }
}

bool gamefinish(char arr[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (arr[i][0] == 'X' || arr[i][0] == 'O') {
            if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) {
                return true;
            }
        }
    }
    for (int j = 0; j < SIZE; j++) {
        if (arr[0][j] == 'X' || arr[0][j] == 'O') {
            if (arr[0][j] == arr[1][j] && arr[0][j] == arr[2][j]) {
                return true;
            }
        }
    }
    if (arr[0][0] == 'X' || arr[0][0] == 'O') {
        bool diagonalforward = true;
        for (int z = 0; z < SIZE - 1; z++) {
            if (arr[z][z] != arr[z + 1][z + 1]) {
                diagonalforward = false;
            }
        }
        if (diagonalforward) {
        return true;
        }
    }
    if (arr[SIZE - 1][0] == 'X' || arr[SIZE - 1][0] == 'O') {
        bool diagonalbackwards = true;
        for (int k = 0; k < SIZE - 1; k++) {
            if (arr[SIZE - k - 1][k] != arr[SIZE - k - 2][k + 1]) {
                diagonalbackwards = false;
            }
        }
        if (diagonalbackwards) {
            return true;
        }
    }
    return false;
}

bool isFull(char arr[][SIZE]) {
    bool full = true;
    for (int a = 0; a < SIZE; a++) {
        for (int b = 0; b < SIZE; b++) {
            if (arr[a][b] == ' ') {
                full = false;
            }
        }
    }
    if (full) {
        return true;
    }
    return false;
}