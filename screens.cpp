/* ___________________________________________________________
 * ____________<<<___#_R_V_C_G_E_E_K_S___>>>__________________
 * CREATED BY #RVCGEEKS @PUNE for more rvchavadekar@gmail.com
 *
 * #RVCGEEKS tic tac toe AI
 * minmax algorithm
 * created on 22.07.2018
 * 
 * screens.cpp   --make everything look good
 * 
*/

//_______________________EXTERNAL HELPERS___________________________

#include<stdlib.h>
int msleep(unsigned long milisec)
{
  struct timespec req={0};
  time_t sec=(int)(milisec/1000);
  milisec-=sec*1000;
  req.tv_sec=sec;
  req.tv_nsec=milisec*1000000L;
  while(nanosleep(&req,&req)==-1)
    continue;
  return 1;
}
void d(char dgt,int seg,int n)
{
  switch(dgt)
    {
    case 'X':switch(seg)
	{
	case 1:cout<<"\033[1;31m████  ████   \033[0m";break;
	case 2:cout<<"\033[1;31m  ██  ██     \033[0m";break;
	case 3:cout<<"\033[1;31m   ████      \033[0m";break;
	case 4:cout<<"\033[1;31m  ██  ██     \033[0m";break;
	case 5:cout<<"\033[1;31m████  ████   \033[0m";break;
        case 6:cout<<"\033[1;31m             \033[0m";break;
	}
      break;
    case 'O':switch(seg)
	{
	case 1:cout<<"\033[1;32m  ███████    \033[0m";break;
	case 2:cout<<"\033[1;32m███     ███  \033[0m";break;
	case 3:cout<<"\033[1;32m███     ███  \033[0m";break;
	case 4:cout<<"\033[1;32m███     ███  \033[0m";break;
	case 5:cout<<"\033[1;32m  ███████    \033[0m";break;
        case 6:cout<<"\033[1;32m             \033[0m";break;
	}
      break;
    default:switch(seg)
	{
	case 3:cout<<"     "<<n<<"       ";break;
	default:cout<<"             ";break;
	}
      break;
    }
}

//_____________________________________________________________________

void TicTacToe::printBoard() 
{
    int i,j,k,flag=1;cout<<"\a";
    again:for(k=1;k<=6;k++)
    {
        cout<<"\n\033[2J\033[1;1H\n\n\n\n\n\n                                               #RVCGEEKS Tic Tac Toe AI game\n\t\t\t\t\t   for more geeks rvchavadekar@gmail.com\n\t\t\t     ___________________________________________________________________\n\n\n\n\n";
        for(i=0;i<3;i++)
        {
            for(j=1;j<=6;j++)
            {
                cout<<"                                           ";
                if(v.x==i&&v.y==0&&flag)
                {
                    if(j==k)
                        d(board[i][0],k,1+i*3);
                    else 
                        d('X',6,1+i*3);
                    
                }
                else 
                    d(board[i][0],j,1+i*3);
                if(v.x==i&&v.y==1&&flag)
                {
                    if(j==k)
                        d(board[i][1],k,2+i*3);
                    else
                        d('X',6,2+i*3);
                    
                }
                else 
                    d(board[i][1],j,2+i*3);
                if(v.x==i&&v.y==2&&flag)
                {
                    if(j==k)
                        d(board[i][2],k,3+i*3);
                    else 
                        d('X',6,3+i*3);
                }
                else 
                    d(board[i][2],j,3+i*3);
                cout<<"\n";
            }
            
        }
        if(flag)
        msleep(100);
    }
    if(flag)
    {
        flag=0;
        goto again;
    }
}
void TicTacToe::zap()
{
  if(win=='X'||win=='O')  
  for(int i=0;i<15;i++)
    {
      msleep(300);
      cout<<"\n\033[2J\033[1;1H\n\n\n\n\n\n";
      if(i%3!=0)
      {
          cout<<"\n\033[2J\033[1;1H\n\n\n\n\n\n\n\n\n";
          if(win=='X')
                  cout<<"                                     Human Player Wins !!\n\n";
          else if(win=='O')
                  cout<<"                                    Computer Player Wins !!\n\n";
          for(int i=1;i<=6;i++)
          {
              cout<<"                                           ";
              d(win,i,0);
              cout<<endl;
          }
      }
    }
}