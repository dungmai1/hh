#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void gotoxy(int x, int y)
{
  static HANDLE h=NULL;
  if(!h)
    h=GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c={x,y};
  SetConsoleCursorPosition(h,c);
}
void viet(int x, int y, int z)
{
	gotoxy(x,y);
	printf("%c",z);
}
void vietchuoi(int x, int y, char s[], int mau)
{
	gotoxy(x,y);
	textcolor(mau);
	puts(s);
}
int batphim()
{
	int c=getch();
	if(c==8) //phim Backspace
		return 1;
	else if(c==9) //phim Tab
		return 2;
	else if(c==13) //phim Enter
		return 3;
	else if(c==27) //phim Esc
		return 4;
	else if(c==224)
	{
		c=getch();
		if(c==72) //Keyup
			return 5;
		else if(c==80) //KeyDown
			return 6;
		else if(c==75) //KeyLeft
			return 7;
		else if(c==77) //KeyRight
			return 8;
		else if(c==83) //Delete
			return 9;
	}
	else if(c==0)
	{
		c=getch();
		if(c==60) //F2
			return 12;
		if(c==62) //F4
			return 13;
	}
}
int bangmenu(int x, int y, int m, int n, int mau)
{
	int i, j;
	textcolor(mau);
	for(i=x;i<=x+m;i++)
		for(j=y;j<=y+n;j++)
		{
			if(i==x || i==x+m)
			{
				if(j==y && i!=x+m)
					viet(i,j,218);
				else if(j==y && i!=x)
					viet(i,j,191);
				else if(j==y+n && i!=x+m)
					viet(i,j,192);
				else if(j==y+n && i!=x)
					viet(i,j,217);
				else viet(i,j,179);
			}
			else if(j==y || j==y+n)
					viet(i,j,196);
		}
}
int menu()
{
	int x, y;
	bangmenu(x+2,y+2,26,2,11);	vietchuoi(x+5,y+3,"1>  San pham",15);
	vietchuoi(x+5,y+6,"2>  Khach hang",6);
	vietchuoi(x+5,y+9,"3>  Thong tin",6);
	vietchuoi(x+5,y+12,"4>  Thong ke",6);
	vietchuoi(x+5,y+15,"5>  Thoat",6);
	int kt=1;
	for(;;)
	{
		int h=batphim();
		if(h==6) // phim xuong
		{
			if(kt==1)
			{
				kt=2;
				bangmenu(x+2,y+2,26,2,0);	vietchuoi(x+5,y+3,"1>  San pham",6);
				bangmenu(x+2,y+5,26,2,11);	vietchuoi(x+5,y+6,"2>  Khach hang",15);
				bangmenu(x+2,y+8,26,2,0);	vietchuoi(x+5,y+9,"3>  Thong tin",6);
				bangmenu(x+2,y+11,26,2,0);	vietchuoi(x+5,y+12,"4>  Thong ke",6);
				bangmenu(x+2,y+14,26,2,0);	vietchuoi(x+5,y+15,"5>  Thoat",6);
			}
			else if(kt==2)
			{
				kt=3;
				bangmenu(x+2,y+2,26,2,0);	vietchuoi(x+5,y+3,"1>  San pham",6);
				bangmenu(x+2,y+5,26,2,0);	vietchuoi(x+5,y+6,"2>  Khach hang",6);
				bangmenu(x+2,y+8,26,2,11);	vietchuoi(x+5,y+9,"3>  Thong tin",15);
				bangmenu(x+2,y+11,26,2,0);	vietchuoi(x+5,y+12,"4>  Thong ke",6);
				bangmenu(x+2,y+14,26,2,0);	vietchuoi(x+5,y+15,"5>  Thoat",6);
			}
			else if(kt==3)
			{
				kt=4;
				bangmenu(x+2,y+2,26,2,0);	vietchuoi(x+5,y+3,"1>  San pham",6);
				bangmenu(x+2,y+5,26,2,0);	vietchuoi(x+5,y+6,"2>  Khach hang",6);
				bangmenu(x+2,y+8,26,2,0);	vietchuoi(x+5,y+9,"3>  Thong tin",6);
				bangmenu(x+2,y+11,26,2,11);	vietchuoi(x+5,y+12,"4>  Thong ke",15);
				bangmenu(x+2,y+14,26,2,0);	vietchuoi(x+5,y+15,"5>  Thoat",6);
			}
			else if(kt==4)
			{
				kt=5;
				bangmenu(x+2,y+2,26,2,0);	vietchuoi(x+5,y+3,"1>  San pham",6);
				bangmenu(x+2,y+5,26,2,0);	vietchuoi(x+5,y+6,"2>  Khach hang",6);
				bangmenu(x+2,y+8,26,2,0);	vietchuoi(x+5,y+9,"3>  Thong tin",6);
				bangmenu(x+2,y+11,26,2,0);	vietchuoi(x+5,y+12,"4>  Thong ke",6);
				bangmenu(x+2,y+14,26,2,11);	vietchuoi(x+5,y+15,"5>  Thoat",15);
			}
			else if(kt==5)
			{
				kt=1;
				bangmenu(x+2,y+2,26,2,11);	vietchuoi(x+5,y+3,"1>  San pham",15);
				bangmenu(x+2,y+5,26,2,0);	vietchuoi(x+5,y+6,"2>  Khach hang",6);
				bangmenu(x+2,y+8,26,2,0);	vietchuoi(x+5,y+9,"3>  Thong tin",6);
				bangmenu(x+2,y+11,26,2,0);	vietchuoi(x+5,y+12,"4>  Thong ke",6);
				bangmenu(x+2,y+14,26,2,0);	vietchuoi(x+5,y+15,"5>  Thoat",6);
			}
		}
		else if(h==5) // phim len
		{
			if(kt==1)
			{
				kt=5;
				bangmenu(x+2,y+2,26,2,0);	vietchuoi(x+5,y+3,"1>  San pham",6);
				bangmenu(x+2,y+5,26,2,0);	vietchuoi(x+5,y+6,"2>  Khach hang",6);
				bangmenu(x+2,y+8,26,2,0);	vietchuoi(x+5,y+9,"3>  Thong tin",6);
				bangmenu(x+2,y+11,26,2,0);	vietchuoi(x+5,y+12,"4>  Thong ke",6);
				bangmenu(x+2,y+14,26,2,11);	vietchuoi(x+5,y+15,"5>  Thoat",15);
			}
			else if(kt==5)
			{
				kt=4;
				bangmenu(x+2,y+2,26,2,0);	vietchuoi(x+5,y+3,"1>  San pham",6);
				bangmenu(x+2,y+5,26,2,0);	vietchuoi(x+5,y+6,"2>  Khach hang",6);
				bangmenu(x+2,y+8,26,2,0);	vietchuoi(x+5,y+9,"3>  Thong tin",6);
				bangmenu(x+2,y+11,26,2,11);	vietchuoi(x+5,y+12,"4>  Thong ke",15);
				bangmenu(x+2,y+14,26,2,0);	vietchuoi(x+5,y+15,"5>  Thoat",6);
			}
			else if(kt==4)
			{
				kt=3;
				bangmenu(x+2,y+2,26,2,0);	vietchuoi(x+5,y+3,"1>  San pham",6);
				bangmenu(x+2,y+5,26,2,0);	vietchuoi(x+5,y+6,"2>  Khach hang",6);
				bangmenu(x+2,y+8,26,2,11);	vietchuoi(x+5,y+9,"3>  Thong tin",15);
				bangmenu(x+2,y+11,26,2,0);	vietchuoi(x+5,y+12,"4>  Thong ke",6);
				bangmenu(x+2,y+14,26,2,0);	vietchuoi(x+5,y+15,"5>  Thoat",6);
			}
			else if(kt==3)
			{
				kt=2;
				bangmenu(x+2,y+2,26,2,0);	vietchuoi(x+5,y+3,"1>  San pham",6);
				bangmenu(x+2,y+5,26,2,11);	vietchuoi(x+5,y+6,"2>  Khach hang",15);
				bangmenu(x+2,y+8,26,2,0);	vietchuoi(x+5,y+9,"3>  Thong tin",6);
				bangmenu(x+2,y+11,26,2,0);	vietchuoi(x+5,y+12,"4>  Thong ke",6);
				bangmenu(x+2,y+14,26,2,0);	vietchuoi(x+5,y+15,"5>  Thoat",6);
			}
			else if(kt==2)
			{
				kt=1;
				bangmenu(x+2,y+2,26,2,11);	vietchuoi(x+5,y+3,"1>  San pham",15);
				bangmenu(x+2,y+5,26,2,0);	vietchuoi(x+5,y+6,"2>  Khach hang",6);
				bangmenu(x+2,y+8,26,2,0);	vietchuoi(x+5,y+9,"3>  Thong tin",6);
				bangmenu(x+2,y+11,26,2,0);	vietchuoi(x+5,y+12,"4>  Thong ke",6);
				bangmenu(x+2,y+14,26,2,0);	vietchuoi(x+5,y+15,"5>  Thoat",6);
			}
		}
}
}
int main()
{
	menu();
	return 0;
}
