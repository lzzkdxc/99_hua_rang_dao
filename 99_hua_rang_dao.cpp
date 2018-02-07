#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#include<windows.h>
#include <conio.h>
void hidecursor()
{
	CONSOLE_CURSOR_INFO cursor_info={1,0};//第二个值为零表示光标隐藏
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info); 
}
/////////////////////////////////////////////////////////////////////////////////////
	char a[9]={' ','1','2','3','4','5','6','7','8'},input;
	int c1=0,c2=0,t,i,now,win=1;
void change(char*a,char*b)
{
	t=*a;
	*a=*b;
	*b=t;
}
void start()
{
	hidecursor();//隐藏光标 
	system("cls");
	printf("Click any key to start."); 
	input=getch();
	srand(time(NULL));
	for(i=1;i<=100;i++)
	{
		c1=rand()%10;
		c2=rand()%10;
		if(c1!=c2&&c1!=9&&c2!=9)
		{
			change(&a[c1],&a[c2]);
		}
	}
}
void in()
{
	input=getch();
	if(input=='w'&&now<6)
		change(&a[now],&a[now+3]);
	if(input=='s'&&now>2)
		change(&a[now],&a[now-3]);
	if(input=='a'&&now!=2&&now!=5&&now!=8)
		change(&a[now],&a[now+1]);
	if(input=='d'&&now!=0&&now!=3&&now!=6)
		change(&a[now],&a[now-1]);
	if(input=='b')
		start();
}
void out()
{
	system("cls");
	for(i=0;i<=8;i++)
	{
		if(i%3==0)
			puts("\n");
		
		printf("   %c",a[i]);
		
		if(a[i]==' ')
			now=i;
	}
	if(a[0]=='1'&&a[1]=='2'&&a[2]=='3'&&a[3]=='4'&&a[4]=='5'&&a[5]=='6'&&a[6]=='7'&&a[7]=='8'&&a[8]=='9')
	{
		win=0;
		printf("win!!");
	}
		
}
int main()
{
	start();
	while(win)
	{
		out();
		in();
	} 
	
}
