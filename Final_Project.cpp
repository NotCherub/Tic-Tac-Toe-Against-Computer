#include <iostream>
#include<bits/stdc++.h>

#define SIDE 3   // defining MAX_SIZE of board =3

using namespace std;

int geti(int pos)
{
	if (pos>=1&&pos<4)
		return 0;
	else if( pos>3 && pos <7)
		return 1;
	else
		return 2;
}
int getj(int pos)
{
	if (pos==1||pos==4||pos==7)
		return 0;
	else if(pos==2||pos==5||pos==8)
		return 1;
	else
		return 2;
}
void showBoard(char board[][SIDE])
{
    printf("\n\n");
     
    printf("\t\t\t  %c | %c  | %c  \n", board[0][0],
                             board[0][1], board[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", board[1][0],
                             board[1][1], board[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", board[2][0],
                             board[2][1], board[2][2]);
}
void showInstructions()
{
    printf("\t\t\t  Tic-Tac-Toe\n\n");
    printf("Choose a cell numbered from 1 to 9 as below"
            " and play\n\n");
     
    printf("\t\t\t  1 | 2  | 3  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  4 | 5  | 6  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  7 | 8  | 9  \n\n");
     
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
	printf("Computer Plays as O and Human plays as X");
}

bool rowCrossed(char board[][SIDE])
{
    for (int i=0; i<SIDE; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] && 
            board[i][0] != ' ')
            return (true);
    }
    return(false);
}

bool columnCrossed(char board[][SIDE])
{
    for (int i=0; i<SIDE; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] && 
            board[0][i] != ' ')
            return (true);
    }
    return(false);
}

bool diagonalCrossed(char board[][SIDE])
{
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] && 
        board[0][0] != ' ')
        return(true);
         
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
         board[0][2] != ' ')
        return(true);
 
    return(false);
}

bool gameOver(char board[][SIDE])
{
    return(rowCrossed(board) || columnCrossed(board)
            || diagonalCrossed(board) );
}

int check2row(char board[3][3])
{
	for (int i=0; i<3; i++)
    {
        if ((board[i][0] == board[i][1] && board[i][0]!=' ' && board[i][2]==' ' )||
		     (board[i][0] == board[i][2] && board[i][0]!=' ' && board[i][1]==' ')||
			  (board[i][1] == board[i][2] && board[i][1]!=' ' && board[i][0]==' ' ))
            return i;
    }
    return -1;
}

int check2col(char board[3][3])
{
	for (int i=0; i<3; i++)
    {
        if ((board[0][i] == board[1][i] && board[0][i]!=' ' && board[2][i]==' ' )||
            (board[0][i] == board[2][i] && board[0][i]!=' ' && board[1][i]==' ' )|| 
            (board[1][i] == board[2][i] && board[1][i]!=' ' && board[0][i]==' ' ))
            return i;
    }
    return -1;
}

int check2diagr(char board[3][3])
{
	if (board[0][0] == board[1][1] && board[0][0]!=' ' && board[2][2]==' ')
        return 2;
    else if (board[1][1] == board[2][2] && board[1][1]!=' ' && board[0][0]== ' ')
        return  0;
    else if (board[0][0] == board[2][2] && board [0][0]!=' ' && board[1][1]==' ')
    	return 1;
    return -1;
}

int check2diagl(char board[3][3])
{
	if(board[0][2] == board[1][1] && board[0][2]!=' ' && board[2][0]==' ')
		return 7;
	else if (board[1][1] == board[2][0] && board[1][1]!=' ' && board[0][2]== ' ')
		return 3;
	else if ((board[2][0] == board[0][2] && board [0][2]!=' ' && board[1][1]==' '))
		return 5;
	return -1;
}
void computerMoves(char board[3][3])
{
	int check = check2row(board);
	if (check!=-1)
	for(int j=0;j<3;++j)
	if(board[check][j]==' ')
	{
		board[check][j]= 'O';
		return;
	}

	check = check2col(board);
	if(check!=-1)
	for(int i=0;i<3;++i)
	if(board[i][check]==' ')
	{
		board[i][check]='O';
		return;
	}
	
	check = check2diagr(board);
	if(check!=-1)
	{
		board[check][check] = 'O';
		return;
	}
	check = check2diagl(board);
	if(check!=-1)
	{
		board[geti(check)][getj(check)] = 'O';
		return;
	}
	
	while(true)
	{
		srand (time(NULL));
		int pos = rand()%9+1;
		if (board[geti(pos)][getj(pos)]==' ')
		{
			board[geti(pos)][getj(pos)]= 'O';
			return;
		}
	}
}

bool checkDraw(char board[][3])
{
	for(int i=0;i<3;++i)
	for(int j=0;j<3;++j)
	if(board[i][j]==' ')
		return false;
	return true;	
}
int main()
{
	char board[3][3];
	
	for (int i=0; i<SIDE; i++)
    {
        for (int j=0; j<SIDE; j++)
            board[i][j] = ' ';
    }
    showInstructions();
    //board[1][1] = 'O';
    showBoard(board);
    int chance =1;
    while((!gameOver(board)) && (!checkDraw(board)))
    {
    	cout<<"\nYour Chance.Enter the position";
    	int pos;
    	cin>>pos;
    	if (board[geti(pos)][getj(pos)]!=' '||pos>9)
    	do
    	{
    		cout<<"\nError!Invalid position input.Enter new position";
    		cin>>pos;
    	}while(board[geti(pos)][getj(pos)]!=' '||pos>9);
    	board[geti(pos)][getj(pos)] = 'X';
    	chance++;
    	showBoard(board);
    	if (gameOver(board))
    		break;
    	if (checkDraw(board))
    	{
    		chance =-1;
    		break;
		}
    	computerMoves(board);
    	cout<<"\nComputer Moved";
    	showBoard(board);
    	chance++;
	}
	if (chance==-1)
	cout<<"Match Drawn";
	else if (chance%2==1)
		cout<<"\nComputer Wins!!";
	else
		cout<<"\nCongratulations!! You Won!";
    
}
