#include <time.h>

int board_merge(int board[4][4],int x,int y,int x2,int y2)
{
	board[y][x]+=board[y2][x2];
	board[y2][x2]=0;
}

int clear_board(int board[4][4])
{
	int i,k;
	for(i=0;i<4;i++)
	{
		for(k=0;k<4;k++)
		{
			board[i][k]=0;		
		}
	}
	return 0;
}

int board_up(int board[4][4])
{
	int i,k,n,n_tp;
	int tp_board[4][4];
	int flag=1;
	clear_board(tp_board);
	for(i=1;i<4;i++)
	{
		for(k=0;k<4;k++)
		{
			n_tp=i;	
			if(board[i][k]==0)
			{
				continue;		
			}
			for(n=i-1;n>=0;n--)
			{
				if(board[n][k]!=0)		
				{	
					if((board[i][k]==board[n][k])&&(tp_board[n][k]==0))
					{
						n_tp=n;
					}
					break;
				}
				else
				{
					n_tp=n;
				}
			}
			if(n_tp!=i)
			{
				if(board[n_tp][k]!=0)
				{
					tp_board[n_tp][k]=1;
				}
				board_merge(board,k,n_tp,k,i);
				flag=0;
			}
		}
	}
	return flag;
}

int board_down(int board[4][4])
{
	int i,k,n,n_tp;
	int tp_board[4][4];
	int flag=1;
	clear_board(tp_board);
	for(i=2;i>=0;i--)
	{
		for(k=0;k<4;k++)
		{
			n_tp=i;
			if(board[i][k]==0)
			{
				continue;		
			}
			for(n=i+1;n<4;n++)
			{
				if(board[n][k]!=0)		
				{	
					if((board[i][k]==board[n][k])&&(tp_board[n][k]==0))
					{
						n_tp=n;
					}
					break;
				}
				else
				{
					n_tp=n;
				}
			}
			if(n_tp!=i)
			{
				if(board[n_tp][k]!=0)
				{
					tp_board[n_tp][k]=1;
				}
				board_merge(board,k,n_tp,k,i);
				flag=0;
			}
		}
	}
	return flag;
}

int board_left(int board[4][4])
{
	int i,k,n,n_tp;
	int tp_board[4][4];
	int flag=1;
	clear_board(tp_board);
	for(k=1;k<4;k++)
	{
		for(i=0;i<4;i++)
		{
			n_tp=k;
			if(board[i][k]==0)
			{
				continue;		
			}
			for(n=k-1;n>=0;n--)
			{
				if(board[i][n]!=0)		
				{	
					if((board[i][k]==board[i][n])&&(tp_board[i][n]==0))
					{
						n_tp=n;
					}
					break;
				}
				else
				{
					n_tp=n;
				}
			}
			if(n_tp!=k)
			{
				if(board[i][n_tp]!=0)
				{
					tp_board[i][n_tp]=1;			
				}
				board_merge(board,n_tp,i,k,i);
				flag=0;
			}
		}
	}
	return flag;
}

int board_right(int board[4][4])
{
	int i,k,n,n_tp;
	int tp_board[4][4];
	clear_board(tp_board);
	int flag=1;
	for(k=2;k>=0;k--)
	{
		for(i=0;i<4;i++)
		{
			n_tp=k;	
			for(n=k+1;n<4;n++)
			{
				if(board[i][k]==0)
				{
					continue;		
				}
				if(board[i][n]!=0)		
				{	
					if((board[i][k]==board[i][n])&&(tp_board[i][n]==0))
					{
						n_tp=n;
					}
					break;
				}
				else
				{
					n_tp=n;
				}
			}
			if(n_tp!=k)
			{
				if(board[i][n_tp]!=0)
				{
					tp_board[i][n_tp]=1;		
				}
				board_merge(board,n_tp,i,k,i);
				flag=0;
			}
		}
	}
	return flag;
}
int print_board(int board[4][4])
{
	int i,k;
	int cou=0;
	for(i=0;i<4;i++)
	{
		for(k=0;k<4;k++)
		{
			if(board[i][k]==0)
			{
				printf("%6c",'.');
			}
			else
			{
				printf("%6d",board[i][k]);		
			}
		}
		printf("\n");
	}
}

int ini_board(int board[4][4])
{
	int i,k;
	int num,num2;
	int x,y,x2,y2;
	num=(rand()%2+1)*2;
	if(num==4)
	{
		num2=2;		
	}
	else
	{
		num2=(rand()%2+1)*2;		
	}
	x=rand()%4;
	y=rand()%4;
	while(1)
	{
		x2=rand()%4;
		y2=rand()%4;
		if((x2!=x)&&(y2!=y))
		{
			break;		
		}
	}
	clear_board(board);
	board[y][x]=num;
	board[y2][x2]=num2;
	return 0;
}

int board_plus(int board[4][4])
{
	int i,k;
	int cou,cou_tp,tp;
    int x,y;
    cou=0;
    for(i=0;i<4;i++)
	{
		for(k=0;k<4;k++)
		{
			if(board[i][k]==0)
			{
				cou++;		
			}
		}
	}
	if(cou==0)//game over
	{
		return 1;		
	}
	else
	{
		tp=rand()%cou;
		cou=0;
		for(i=0;i<4;i++)
		{
			for(k=0;k<4;k++)
			{
				if(board[i][k]==0)
				{
					if(cou==tp)
					{
						board[i][k]=(rand()%2+1)*2;		
					}
					cou++;
				}
			}
		}
	}
	return 0;
}

int check_full(int board[4][4])
{
	int i,k;
	int cou=0;
	for(i=0;i<4;i++)
	{
		for(k=0;k<4;k++)
		{
			if(board[i][k]!=0)
			{
				cou++;		
			}
		}
	}
	if(cou==16)
	{
		return 1;		
	}
	return 0;
}
