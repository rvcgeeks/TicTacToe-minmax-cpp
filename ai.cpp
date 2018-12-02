/* ___________________________________________________________
 * ____________<<<___#_R_V_C_G_E_E_K_S___>>>__________________
 * CREATED BY #RVCGEEKS @PUNE for more rvchavadekar@gmail.com
 *
 * #RVCGEEKS tic tac toe AI
 * minmax algorithm
 * created on 22.07.2018
 * 
 * ai.cpp   --minmax ai for tic tac toe 
 * 
*/


TicTacToe::pair TicTacToe::minmax(bool toggle=true)  //true for ai (max search) and false for human (min search)
{
    if(gameOver()) 
        return {score(),0};
    pair move,frame={(toggle?1:-1)*1000,0};    // x value of frame has best score and y value has best move integer
    for(int k=1;k<=9;k++)
    {
        move=decode(k);
        if(board[move.x][move.y]=='-')
        {
            board[move.x][move.y]=(toggle?ai:human);
            int temp=minmax(!toggle).x;
            if((temp>=frame.x&&!toggle)||(temp<=frame.x&&toggle))
               frame={temp,k};
            board[move.x][move.y]='-';
        }
    }
    return frame;
}