#include <stdio.h>
#include <stdlib.h>
#include "getch.h"
#include "board.h"
#include <time.h>

int direction_getch();

int main()
{
	int direction=0;
    int board[4][4];
    int flag;
    srand(time(NULL));
    ini_board(board);
    while(1)
	{
		system("clear");
		print_board(board);
		direction=direction_getch();
		flag=0;
		switch(direction)
		{
			case 1:
			{
				if(board_up(board)==1)
				{
					flag=1;//continue;// no moves
				if(check_full(board)==0)
				{
					continue;		
				}
				}
				break;
			}
			case 2:
			{
				if(board_down(board)==1)
				{
					flag=1;//continue;// no moves
				if(check_full(board)==0)
				{
					continue;		
				}
				}
				break;		
			}
			case 3:
			{
				if(board_right(board)==1)
				{
					flag=1;//continue;// no moves
				if(check_full(board)==0)
				{
					continue;		
				}
				}
				break;		
			}
			case 4:
			{	
				if(board_left(board)==1)
				{
					flag=1;//continue;// no moves
				if(check_full(board)==0)
				{
					continue;		
				}
				}
				break;		
			}
			default:
			{
				continue;
			}
		}
		if(board_plus(board)==1&&flag==1)
		{
			printf("game over\n");
			break;
		}
	}
	return 0;		
}

int  direction_getch()
{
    int ch;
    getch();
    getch();
    ch=getch();
	if(ch==65)
	{
		return 1;
	}
	else if(ch==66)
	{
		return 2;
	}
	else if(ch==67)
	{
		return 3;
	}
	else if(ch==68)
	{
		return 4;
	}
	else
	{
		//printf("please input direction\n");	
	}
	return 0;
}
