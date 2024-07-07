#pragma once
#include "functions.cpp"
#include <vector>
using namespace std;

void instructions();
char getHumanPiece();
char getComputerPiece(char humanPiece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
void humanMove(vector<char>& board, char humanPiece);
bool isLegal(const vector<char>& board, int move);
int computerMove(vector<char> board, char computerPiece);
char opponent(char piece);
void announceWinner(const vector<char>& board, char humanPiece, char computerPiece);