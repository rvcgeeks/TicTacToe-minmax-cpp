/* ___________________________________________________________
 * ____________<<<___#_R_V_C_G_E_E_K_S___>>>__________________
 * CREATED BY #RVCGEEKS @PUNE for more rvchavadekar@gmail.com
 *
 * #RVCGEEKS tic tac toe AI
 * minmax algorithm
 * created on 22.07.2018
 * 
 * game.cpp     --game framework
 * dependencies --screens.cpp and ai.cpp
 * 
*/

#include"ai.cpp"
#include"screens.cpp"
TicTacToe::TicTacToe() {
        win='N';
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			board[i][j] = '-';
		}
	}
}

bool TicTacToe::gameOver() {
	if(checkWin(human)) return true;
	else if(checkWin(ai)) return true;

	bool emptySpace = true;
	for(int i = 0; i < 3; i++) {
		if(board[i][0] == '-' || board[i][1] == '-' || board[i][2] == '-')
			emptySpace = false;
	}
	return emptySpace;
}

bool TicTacToe::checkWin(char playerChar) {
	for(int i = 0; i < 3; i++) {
		// Check horizontals
		if(board[i][0] == playerChar && board[i][1] == playerChar
			&& board[i][2] == playerChar)
			return true;

		// Check verticals
		if(board[0][i] == playerChar && board[1][i] == playerChar
			&& board[2][i] == playerChar)
			return true;
	}

	// Check diagonals
	if (board[0][0] == playerChar && board[1][1] == playerChar 
		&& board[2][2] == playerChar) {
		return true;
	} else if (board[0][2] == playerChar && board[1][1] == playerChar 
		&& board[2][0] == playerChar) {
		return true;
	}

	return false;
}

int TicTacToe::score() {
	if(checkWin(human)) { return 10; }
	else if(checkWin(ai)) { return -10; }
	return 0; // draw
}
inline TicTacToe::pair TicTacToe::decode(int m)
{
    return
    {
        (m-1)/3,  //x value
        (m-1)%3   //y value
    };
}
void TicTacToe::getHumanMove() {
	int t; 
	invalid:cout << "                             Enter your move:\n                             ";
	cin>>t;v=decode(t);
        if(board[v.x][v.y]=='-'&&t>=1&&t<=9)
             board[v.x][v.y] = human;
        else {
             cout<<"  NO CHEATING BUDDY !!\n";
             goto invalid;
        }
}

void TicTacToe::play() {
	int turn = 0;
	while(!gameOver()) {
		// human move
                printBoard();
		if(turn % 2 == 0) {
			getHumanMove();
		} else {
			cout << endl << "Computer Player Move:\n";
			v = decode(minmax().y);
			board[v.x][v.y] = ai;
		}
		turn++;
	}
	printBoard();
        if(checkWin(human))win=human;
        else if(checkWin(ai))win=ai;
        else cout<<"Its a tie !!"<<endl;
}