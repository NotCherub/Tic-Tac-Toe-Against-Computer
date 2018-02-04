#include<stdio.h>
#include<conio.h>
int win_check(char a[3][3])
{
	if(a[0][0]==a[0][1]&&a[0][1]==a[0][2])
	return 1;
	else if(a[1][0]==a[1][1]&&a[1][1]==a[1][2])
	return 1;
	else if(a[2][0]==a[2][1]&&a[2][1]==a[2][2])
	return 1;
	else if(a[0][0]==a[1][0]&&a[1][0]==a[2][0])
	return 1;
	else if(a[0][1]==a[1][1]&&a[1][1]==a[2][1])
	return 1;
	else if(a[0][2]==a[1][2]&&a[1][2]==a[2][2])
	return 1;
	else if(a[0][0]==a[1][1]&&a[1][1]==a[2][2])
	return 1;
	else if(a[0][2]==a[1][1]&&a[2][0]==a[1][1])
	return 1;
	else
	return 0;
}
void ttb(char a[3][3])
{
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",a[0][0],a[0][1],a[0][2]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",a[1][0],a[1][1],a[1][2]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %C  \n",a[2][0],a[2][1],a[2][2]);
	printf("     |     |     \n");
}
int main()
{
	int x, pointer=0, choice;
	char a[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
	printf("\n\n Player 1->X         Player 2->O\n\n");
	printf("Layout of the Tic-Tac Board\n\n\n");
	printf("     |     |     \n");
	printf("  1  |  2  |  3  \n");
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  4  |  5  |  6  \n");
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  7  |  8  |  9  \n");
	printf("     |     |     \n");
	printf("press 0 to begin\n");
	scanf("%d",&x);
	if(x!=0)
	printf("bye bye");
	else
	{
		while(win_check(a)!=1 || win_check(a)!=0){
		
			if(pointer%2==0){
			printf("player 1's move:");
			scanf("%d",&choice);
				if(a[0][0]==' '&&choice==1)
				a[0][0]='X';
				else if(a[0][1]==' '&&choice==2)
				a[0][1]='X';
				else if(a[0][2]==' '&&choice==3)
				a[0][2]='X';
				else if(a[1][0]==' '&&choice==4)
				a[1][0]='X';
				else if(a[1][1]==' '&&choice==5)
				a[1][1]='X';
				else if(a[1][2]==' '&&choice==6)
				a[1][2]='X';
				else if(a[2][0]==' '&&choice==7)
				a[2][0]='X';
				else if(a[2][1]==' '&&choice==8)
				a[2][1]='X';
				else if(a[2][2]==' '&&choice==9)
				a[2][2]='X';
				else
				printf("invalid move");
			}else
			printf("Player 2's move:");
			scanf("%d",&choice);
				if(a[0][0]==' '&&choice==1)
				a[0][0]='O';
				else if(a[0][1]==' '&&choice==2)
				a[0][1]='O';
				else if(a[0][2]==' '&&choice==3)
				a[0][2]='O';
				else if(a[1][0]==' '&&choice==4)
				a[1][0]='O';
				else if(a[1][1]==' '&&choice==5)
				a[1][1]='O';
				else if(a[1][2]==' '&&choice==6)
				a[1][2]='O';
				else if(a[2][0]==' '&&choice==7)
				a[2][0]='O';
				else if(a[2][1]==' '&&choice==8)
				a[2][1]='O';
				else if(a[2][2]==' '&&choice==9)
				a[2][2]='O';
				else
				printf("invalid move");
			ttb(a);
			if (win_check(a)==0);
			{
				printf("Nobody wins");
			}
			
			
		}
		
	}
}
