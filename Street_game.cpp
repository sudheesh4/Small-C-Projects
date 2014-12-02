#include <iostream>
#include <string.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#define m 20
#define s 19
using namespace std;
int px[s],py[s];
int x,y,flag=1,w=0,cl[s];
char cr[s];
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
void check()
{
	//(x==px?(y==py?flag=0:flag=1):flag=1);
	for(int j=0;j<s;j++)
	{
		if((x==px[j])&&(y==py[j]))
			{flag=0;return;}
		
	}
	flag=1;
}
int win()
{
	if(y<=1)
      return 1;
  else 
  	return 0;
}
void func()
{
/*	    px=py=3;
    px=0;*/char h='*';int i,l=(int)h;
    srand( time(NULL) );
    for(i=0;i<s;i++)
    {
        px[i]=rand()%s;
       //(i%2==0?px[i]=0:px[i]=m);
       py[i]=i+2 ;
       cr[i]=(char)(l+(rand()%(i+5)));
       cl[i]=rand()%12;
   }
    x=10;
    y=s+2;
    int t[s];
    
    for(i=0;i<s;i++)
    	{   l=rand();
            (l%2==0?t[i]=0:t[i]=1);
            //(i%2==0?t[i]=0:t[i]=1);
        }
char c;
    int  aw=s-1;
 //    cout<<"b";
for(;flag;)
{
 
 for(i=0;i<s;i++)
 {  gotoxy(px[i],py[i]);
    SetConsoleTextAttribute( hstdout, colors[ cl[i]] );
    cout<<cr[i];}
     gotoxy(x,y);
     SetConsoleTextAttribute( hstdout, colors[ cl[aw]] );
    cout<<"*";

   	while((!kbhit())&&flag)
    	{
    		for(i=0;i<s;i++)
    	  {if(px[i]==0)
    	  	t[i]=0;
    	  else if(px[i]==m)
    	  	t[i]=1;
    	  ;
    	  gotoxy(px[i],py[i]);
    	  cout<<" ";
    	  if(!t[i])
    	  	px[i]++;
    	  else 
    	  	px[i]--;
    	  gotoxy(px[i],py[i]);
          SetConsoleTextAttribute( hstdout, colors[ cl[i] ] );
    	  cout<<cr[i];
    	  }
    	  Sleep(100);
    	  check();
    	  if(!flag)
    	  	return;
    	}c=getch();
    	if((c=='w')&&(y>1))
    		{
    			gotoxy(x,y);
    			cout<<" ";
                 y--;
              }
    		
    		    	if((c=='s')&&(y<=s+2))
    		{
    			gotoxy(x,y);
    			cout<<" ";
                  y++;

    		}
    		    	if((c=='a')&&(x>=0))
    		{
    			gotoxy(x,y);
    			cout<<" ";
                x--;

    		}
    		    	if((c=='d')&&(x<m))
    		{
    			gotoxy(x,y);
    			cout<<" ";
               x++;
    		 
    		}
            gotoxy(x,y);
            cout<<"*";
    		check();
    		if(win())
    			{w=1;flag=0;}
    	}
}
void del()
{  int i,j;
    for(i=s+2;i>=0;i--)
    {
        gotoxy(0,i);
        for(j=0;j<59;j++)
        cout<<' ';
        Sleep(100);
    }
}

int main(int argc, char const *argv[])
{    char ty='y';
while(ty=='y')
{   w=0;flag=1;
    system("cls");
    system("color 0A");
	func();
   gotoxy(10,0);

  if(!w)
    	cout<<"game over!!";
   else 
   	cout<<"you win!!";
   gotoxy(40,13);
   cout<<"AGAin...y/n..??";
      ty=getch();
      del();
     }   return 0;
}