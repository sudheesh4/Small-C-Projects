#include <iostream>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;
int x[3][3],flag=1,yo,xo,pl=1,w=0;
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
void del();
int check(int px, int py)
{
	if(x[px][py]==0)
		return 1;
	return 0;
}
void draw()
{   int y;
	gotoxy(30,10);
	for(y=0;y<20;y++)
	{
	 cout<<"_";
	}
	gotoxy(30,15);
	for(y=0;y<20;y++)
	{
	 cout<<"_";
	}
for(y=8;y<18;y++)
	{gotoxy(35,y);
	cout<<"|"; 
	gotoxy(45,y);
	cout<<"|";
	}
}
void assgn(int px,int py)
{
	switch(px)
	{
		 case 0:
		 yo=9;
		 break;
		 case 1:
		 yo=13;
		 break;
		 case 2:
		 yo=16;
		 break;
	}
	switch(py)
	{
		 case 0:
		 xo=32;
		 break;
		 case 1:
		 xo=40;
		 break;
		 case 2:
		 xo=47;
		 break;
	}
}
void load()
{
gotoxy(30,5);
	cout<<"LOADING ........";
	gotoxy(25,7); printf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
	gotoxy(25,8); printf("º °°°°°°°°°°°°°°°°°°°°°°°°°°° º");
	gotoxy(25,9); printf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
	for(int a=27;a<=53;a++)
		{
		Sleep(300);
		gotoxy(a,8);printf("%c",219);
		}
        Sleep(600);
}
void bl_disp()
{
	string tmp = "";
	string err ="invalid!! try again!!";
	int i;
	for(i = 1; i < 80; i++)
		tmp += ' ';
		for(i = 0; i < 4; i++)
	{
		cout << err;
		Sleep( 500);	
		cout << '\r';	
		if(	i % 2 == 1	)	{	system("color ce");	}
		if(	i % 2 == 0	)	{	system("color 4e");	}
		cout << tmp;
		cout << '\r';
		Sleep( 500);
	}
system("color 0A");
}
int win()
{
	
	int k=(pl%2==0?2:1);
	pl++;
	int i=0,j=0;
	for(;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		 if(x[i][j]!=k)
		  break;
		}
	   if(j==3)
	   	{w=k;return 0;}
	   	for(j=0;j<3;j++)
		{
		 if(x[j][i]!=k)
		  break;
		}
	   if(j==3)
	   	{w=k;return 0;}
	}
 if((x[0][0]==x[1][1])&&(x[0][0]==x[2][2])&&(x[0][0]==k))
 	{w=k;return 0;}
 ;
  if((x[2][0]==x[1][1])&&(x[1][1]==x[0][2])&&(x[1][1]==k))
 	{w=k;return 0;}
 ;
 for(i=0;i<3;i++)
 {
 	 for(j=0;j<3;j++)
 	 {
 	 	if(!x[i][j])
 	 	{w=0;return 1;}
 	 }
 }
 w=0;
return 0;
}

void cut(int px, int py)
{   assgn(px,py);
	gotoxy(xo,yo);
	cout<<x[px][py];
}
int main(int argc, char const *argv[])
{system("color 0A");
	int i,j,xi,yi,f=0,l=0,p1,p2;
	p1=p2=0;
	string tmp ="";
	char ch='y';
	//string e="invalid!! try again!!";
	do
	{   
            load();
           system("cls");
		tmp ="";
		f=l=p1=p2=0;
		flag=1;pl=1;w=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			x[i][j]=0;
	}draw();
	do
	{     
	f=0;
	 while(!f)
		{     gotoxy(0,1);cout<<"              ";
			gotoxy(0,0);
			cout<<"Player 1:";
			gotoxy(0,1);cin>>xi>>yi;
		xi--;yi--;
		f=check(xi,yi);
		gotoxy(0,3);
		if((f==0)||(xi>2)||(yi>2))
			{bl_disp();f=0;}
         }
	x[xi][yi]=1;
	p1++;
	cut(xi,yi);
	flag=win();
	    l=0;
	if(flag)
	{
	 while(!l)
		{   gotoxy(0,1);cout<<"              ";
			gotoxy(0,0);
			cout<<"Player 2:";
			gotoxy(0,1);cin>>xi>>yi;
			xi--;yi--;
		l=check(xi,yi);
		gotoxy(0,3);
		if((l==0)||(xi>2)||(yi>2))
           {bl_disp();l=0;}
	    }  
 	x[xi][yi]=2;
 	p2++;
	cut(xi,yi);
	flag=win();
	} 

	}while(flag);
	gotoxy(19,4);
	if(w==0)
		tmp+="DRAW!!";
	else 
		{tmp+="PLAYER ";tmp+=(w==1?"1":"2");tmp+=" WINS!!";}
	gotoxy(20,4);
	cout<<tmp;
	gotoxy(30,20);
	cout<<"AGAin..Y/N.??";
	 ch=getch();
	 del();
	} while(ch=='y');
	return 0;
}
void del()
{  int i,j;
	for(i=21;i>=0;i--)
	{
		gotoxy(0,i);
		for(j=0;j<59;j++)
		cout<<' ';
	    Sleep(100);
	}
}