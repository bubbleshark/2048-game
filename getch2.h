#include <termios.h>

struct termios o_termios,n_termios;

void ini_termios()
{
	tcgetattr(0,&o_termios);
	n_termios=o_termios;
	n_termios.c_lflag&=~ICANON;
	n_termios.c_lflag&=~ECHO;
	tcsetattr(0,TCSANOW,&n_termios);
}

void rst_termios()
{
	tcsetattr(0,TCSANOW,&o_termios);
}

char getch()
{
	char c;
	ini_termios();
	scanf("%c",&c);//c=getchar();
	rst_termios();
	return c;
}

