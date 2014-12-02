#include <iostream>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>
using namespace std;
int x[100],y[100],ex,ey,dead;
int n=1,flag;
int px,py;
char tr=(char) 219;
const WORD colors[] =
        {
        0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x01, 0x02, 0x03, 0x04, 0x05, 0x06
        };

    HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
    HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
    WORD   index   = 0;
   CONSOLE_SCREEN_BUFFER_INFO csbi;
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

COORD currpos( )
{
	CONSOLE_SCREEN_BUFFER_INFO *cord = new CONSOLE_SCREEN_BUFFER_INFO;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	return cord->dwCursorPosition;
}

int currrow( )
{
	COORD pos = currpos( );
	return pos.Y;
}

int currcol( )
{
	COORD pos = currpos( );
	return pos.X;
}
void clear()
{//to clear screen
	for(int i=0;i<n;i++)
	{
     gotoxy(x[i],y[i]);
     cout<<" ";
	}
}
void check()//to check if snake has bitten itself or not 
{  if(n>1)
	{
	for(int i=n-2;i>=0;i--)
	{
		if((x[n-1]==x[i])&&(y[n-1]==y[i]))
			{dead=1;return ;}
	}
	
    }
    ;
    if((x[n-1]==ex)&&(y[n-1]==ey))
    	{flag=0;return ;}
	return ;
}
void move(char &w){
	switch(w){
		case 'w':
		 if(currrow())
		 	{py--;
		 		return ;
		 	}
		 else return ;
		 
		case 's':
		 if(currrow()!=100)
		 	{py++;
		 return ;
		 	}
		 else return ;
		 
		 case 'a':
		 if((currcol()-1)>1)//as after one step pointer moves to next column
		 	{px--;
		 return ;
		 	}
		 else return ;
		 
		case 'd':
		 if((currcol()+1)!=80)//81 is max number of columns 
		 	{px++;
		 return ;
		 	}
		 else { return ;
		 }
		}
}
int main(int argc, char const *argv[])
{
	int i;	char t,c[100],te,es=tr;
	char choice;
do
{
	system("cls");
    t='d';
    srand( time(NULL) );
     	flag=1;n=1;dead=0;
     strcpy(c," ");
	for(i=0;i<n;i++)
	{
	c[i]=tr;
    }

     for(i=0;i<n;i++)
     {    SetConsoleTextAttribute( hstdout, colors[ 1 ] );
     	x[i]=currcol()+(rand()%13);
     	y[i]=currrow()+(rand()%19);
     	     gotoxy(x[i],y[i]);
     cout<<c[i];
     }
     while(!dead)
     {     	flag=1;dead=0;
     ex=rand() % 75;;
		ey=rand() % 30;;
        SetConsoleTextAttribute( hstdout, colors[ 2 ] );
		gotoxy(ex,ey);
		cout<<es;
	while((flag)&&(!dead))
	{te=t;
	D:
	while(!kbhit())
	{   px=x[n-1];
     py=y[n-1];
		move(t);
	   		clear();
		for(i=0;i<n-1;i++)
     {
     	x[i]=x[i+1];
     	y[i]=y[i+1];
     }x[n-1]=px;
     y[n-1]=py;
     check();
	   if(flag&&(!dead))
	   	;
	   else
	   	break;

		for(i=0;i<n;i++)
		{gotoxy(x[i],y[i]);
			 if(i==n-1)
        SetConsoleTextAttribute( hstdout, colors[ 1 ] );
     else
     	SetConsoleTextAttribute( hstdout, colors[0] );
			cout<<c[i];
		}Sleep(100);
	  
	}
	if(!dead&&flag)
	{
	t=getch();
    }
	if((t!='w')&&(t!='a')&&(t!='s')&&(t!='d'))
	{t=te;goto D;}
	}strcat(c,"*");
	n++;
	c[n-1]=tr;
     x[n-1]=ex;
     y[n-1]=ey;
   }
   gotoxy(20,4);
SetConsoleTextAttribute( hstdout, colors[4] );
   cout<<"GAME OVER!";for(i=0;i<n;i++)
		{gotoxy(x[i],y[i]);
			 if(i==n-1)
        SetConsoleTextAttribute( hstdout, colors[ 1 ] );
     else
     	SetConsoleTextAttribute( hstdout, colors[0] );
			cout<<c[i];
		}gotoxy(19,13);
		SetConsoleTextAttribute( hstdout, colors[6] );
		cout<<"Again...Y/N..?";
      choice=getch();
}while(choice=='y');
   return 0;
}