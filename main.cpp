#include <iostream>
#include <vector>
#include "functions.h"
using namespace std;

int main() {
    instructions();

    vector<char> board(9, EMPTY);
    char humanPiece = getHumanPiece();
    char computerPiece = getComputerPiece(humanPiece);
    char turn = X;
    int move;

    displayBoard(board);
    
    while(winner(board) == NO_ONE) {
        if (turn == humanPiece) {
            humanMove(board, humanPiece);
        }
        else {
            move = computerMove(board, computerPiece );
            board[move] = computerPiece;
        }
        displayBoard(board);
        turn = opponent(turn);
    }
    announceWinner(board, humanPiece, computerPiece);

}