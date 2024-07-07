#include "functions.h"
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;
const char X = 'X';
const char O = 'O';
const char NO_ONE = 'N';
const char DRAW = 'D';
const char EMPTY = ' ';

void instructions() {
    cout << "\t\tWelcome to Tic-Tac-Toe\n\n";
    cout << "To make a move, enter a number from 0 to 8\n";
    cout << "\n\t" << '0' << " | " << '1' << " | " << '2';
    cout << "\n\t" << "----------";
    cout << "\n\t" << '3' << " | " << '4' << " | " << '5';
    cout << "\n\t" << "----------";
    cout << "\n\t" << '6' << " | " << '7' << " | " << '8';
    cout << "\n\n";
}

char getHumanPiece() {
    char goFirst;
    do {
        cout << "Do you want to play with X or O: ";
        cin >> goFirst;
    } while (tolower(goFirst) != 'x' and tolower(goFirst) != 'o');

    return toupper(goFirst);
}

char getComputerPiece(char humanPiece) {
    if (humanPiece == X) return O;
    else return X;
}

void displayBoard(const vector<char>& board) {
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "----------";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "----------";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}

char winner(const vector<char>& board) {
    const int WINNING_ROWS[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7}, 
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };
    for(int row = 0; row < 8; row++) {
        if ( (board[WINNING_ROWS[row][0]] != EMPTY) and
        (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) and
        (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]] )) {
            return board[WINNING_ROWS[row][0]];
        }
    }
    if ((count(board.begin(), board.end(), ' ') == 0)) {
        return DRAW;
    }

    return NO_ONE;
}

inline bool isLegal(const vector<char>& board, int move) {
    return (board[move] == EMPTY);  

}

char opponent(char piece) {
    if (piece == X) {
        return O;
    }
    else {
        return X;
    }
}

void humanMove(vector<char>& board, char humanPiece) {
    int move;
    cout << "Where will you move (0 - 8): ";
    cin >> move;
    while(!isLegal(board, move)) {
        cout << "\nThat square is already occupied.\n\n";
        cout << "Where will you move (0 - 8): ";
        cin >> move;
    }
    board[move] = humanPiece;
}

int computerMove(vector<char> board, char computerPiece) {
    int move = 0;
    bool found = false;
    while (!found and move < board.size()) {
        if (isLegal(board, move)) {
            board[move] = computerPiece;
            found = winner(board) == computerPiece;
            board[move] = EMPTY;
        }
        if(!found) {
            ++move;
        }
    }
    if (!found) {
        move = 0;
        char humanPiece = opponent(computerPiece);
        while(!found and move < board.size()) {
            if(isLegal(board, move)) {
                board[move] = humanPiece;
                found = winner(board) == humanPiece;
                board[move] = EMPTY;
            }
            if (!found) {
                ++move;
            }
        }
    }
    if (!found) {
        move = 0;
        int i = 0;
        const int BEST_MOVES[] = { 4, 1, 3, 5, 7, 0, 2, 6, 8};
        while(!found and i < board.size()) {
            move = BEST_MOVES[i];
            if(isLegal(board, move)) {
                found = true;
            }
            i++;
        }
    }
    cout << "I shall take square number " << move << endl;
    return move;
}

void announceWinner(const vector<char>& board, char humanPiece, char computerPiece) {
    char winnerPiece = winner(board);
    if (winnerPiece == humanPiece) {
        cout << "Congratulations! You won!\n";
    }
    else if(winnerPiece == computerPiece) {
        cout << "The computer won. Try again.\n";
    }
    else {
        cout << "Draw. Nobody won.\n";
    }
}