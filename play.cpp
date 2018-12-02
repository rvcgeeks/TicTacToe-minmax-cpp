/* ___________________________________________________________
 * ____________<<<___#_R_V_C_G_E_E_K_S___>>>__________________
 * CREATED BY #RVCGEEKS @PUNE for more rvchavadekar@gmail.com
 *
 * #RVCGEEKS tic tac toe AI
 * minmax algorithm
 * created on 22.07.2018
 * 
 * play.cpp   --launcher file
 * dependency --game.h
 * 
*/

#include "game.hpp"
int main() 
{
        char opt='N';
        do
        { 
            TicTacToe game;       //set up the board
            game.play();          //ready to rock n' roll
            game.zap();           //winning ceremony ;p
            cout<<"Start a new game ? (Y/N) :";
            cin>>opt;
        }
        while(opt=='y'||opt=='Y');
        cout<<"\n\n\n\n                              THANKS FOR PLAYING !! stay tuned...\n\n\n\n"; 
	return 0;
}