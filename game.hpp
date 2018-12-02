/* ___________________________________________________________
 * ____________<<<___#_R_V_C_G_E_E_K_S___>>>__________________
 * CREATED BY #RVCGEEKS @PUNE for more rvchavadekar@gmail.com
 *
 * #RVCGEEKS tic tac toe AI
 * minmax algorithm
 * created on 22.07.2018
 * 
 * game.hpp   --include file for launcher
 * dependency --game.cpp
 * 
*/

#ifndef __GAME_H
#define __GAME_H
const char human = 'X',ai = 'O';

class TicTacToe{
        struct pair{int x,y;};
        pair v,decode(int),minmax(bool);  //v is the active cell in the grid
        char board[3][3],win;
        bool gameOver(),checkWin(char);
        void getHumanMove(),printBoard();
        int score();
public:
	TicTacToe();
	void play(),zap();
};

#include<iostream>
using namespace std;
#include"game.cpp"
#endif