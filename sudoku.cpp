#include <iostream>
#include <conio.h>
#include <map>
#include <string>
#include <sstream>
using namespace std;
#define max 9
#define n 3
string intToString(int  x)
{
       string r;
       stringstream s;
       s << x;
       r = s.str();
       return r;
}
bool checkcolumn(int j,char k,string tempb[max])
{
	for(int i=0;i<max;i++)
	{
		if(tempb[i][j]==k)
		{
			
			return false;

		}
	}
	return true;
}
bool isthere(char k,string t)
{
	for(int i=0;i<max;i++)
	{
		if(t[i]==k)
			return true;
	}
	return false;
}
bool checkblock(int i,int j,char k,string tempb[max])
{
	int x=n*((int)(i/n));
	int y=n*((int)(j/n));
	string temp="";
	;
	for(int ti=0;ti<n;ti++)
	{
		for(int tj=0;tj<n;tj++)
			temp=temp+tempb[x+ti][y+tj];

	}

	if(isthere(k,temp))
		return false;

	return true;

}
bool nextempty(int &i,int &j,string tempb[max])
{

	int ti,tj;
	for(ti=i;ti<max;ti++)
	{
		for(tj=j;tj<max;tj++)
		{
			if(tempb[ti][tj]=='0')
			{
				i=ti;
				j=tj;

				return true;
			}
		}
		j=0;
	}
	return false;
}
bool sudoku(int i,int j,string board[max])
{
	string temp[max];
	for(int ty=0;ty<max;ty++)
		temp[ty]=board[ty];

	if(!nextempty(i,j,temp))
		return true;

	int k=1;
	char kk;
    string tr;
	while(k<10)
	{
        tr=intToString(k);
        kk=tr[0];

		if(isthere(kk,temp[i]))
		{
			k++;
		//	cout<<"her\n";
			continue;
		}
		else if(checkcolumn(j,kk,temp)&&checkblock(i,j,kk,temp))
          {
          	temp[i].at(j)=kk;
        
          	if(sudoku(i,j,temp))
          	{

          		for(int ty=0;ty<max;ty++)
		         board[ty]=temp[ty];
		        return true;

          	}
            
          }   
          k++;
	}
	return false;
}
void input(string board[max])
{   
	cout<<"Enter board (for blank type 0)\n";
		for (int i = 0; i < max; ++i)
	{
		cin>>board[i];
	}
   // board[0]="045803710";
   // board[1]="810000024";
   // board[2]="709000508";
   // board[3]="000907000";
   // board[4]="000060000";
   // board[5]="000402000";
   // board[6]="604000305";
   // board[7]="320000087";
   // board[8]="057308260";
}
int main(int argc, char const *argv[])
{
	string board[max];

    input(board);cout<<"Solving please wait...\n";
    bool res=sudoku(0,0,board);
    if(res)
    {
	cout<<"\nRes-\n\n";
	for(int j=0;j<max;j++)
		cout<<board[j]<<"\n";
    }
    else cout<<"Sorry could not solve!:/";
	getch();
	return 0;
}