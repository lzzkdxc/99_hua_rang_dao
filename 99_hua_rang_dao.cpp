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
	int a[20]={1,2,3,4,5,6,7,8},input;
	int b[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int c1=0,c2=0,t,i,now,win=1,ok=0;
void change(int*a,int*b)
{
	t=*a;
	*a=*b;
	*b=t;
}
void start16()
{
	hidecursor();//隐藏光标 
	system("cls");
	srand(time(NULL));
	for(i=1;i<=2;i++)
	{
		c1=rand()%15;
		c2=rand()%15;
		if(c1!=c2)
		{
			change(&b[c1],&b[c2]);
		}
	}
}
void in16()
{
	input=getch();
	if(input=='w'&&now<12)
		change(&b[now],&b[now+4]);
	if(input=='s'&&now>3)
		change(&b[now],&b[now-4]);
	if(input=='a'&&now!=3&&now!=7&&now!=11&&now!=15)
		change(&b[now],&b[now+1]);
	if(input=='d'&&now!=0&&now!=4&&now!=8&&now!=12)
		change(&b[now],&b[now-1]);
	if(input=='b')
		change(&b[15],&b[14]);
}
void out16()
{
	system("cls");
	for(i=0;i<=15;i++)
	{
		if(i%4==0)
			puts("\n");
		if(b[i]!=0)
			printf("%4d",b[i]);
		else if(b[i]==0)
		{
			printf("    ");
			now=i;
		}
			
	}
	for(i=0;i<=15;i++)
		if(b[i]==i+1)
			ok++;
	if(ok>=15)
	{
		win=0;
		printf("   win!!");
	}	
	ok=0;
}
///////////////////////////////////////////////////////////////////////////////////////////////

void start9()
{
	hidecursor();//隐藏光标 
	system("cls");
	srand(time(NULL));
	for(i=1;i<=100;i++)
	{
		c1=rand()%8;
		c2=rand()%8;
		if(c1!=c2)
		{
			change(&a[c1],&a[c2]);
		}
	}
}
void in9()
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
		change(&a[7],&a[8]);
}
void out9()
{
	system("cls");
	for(i=0;i<=8;i++)
	{
		if(i%3==0)
			puts("\n");
		
		if(a[i]!=0)
			printf("%4d",a[i]);
		else
		{
			printf("    ");
			now=i;
		}
	}

	for(i=0;i<=8;i++)
		if(a[i]==i+1)
			ok++;
	if(ok>=8)
	{
		win=0;
		printf("   win!!");
	}	
	ok=0;
}
int main()
{
	printf("Click q or w to choose 9 or 16."); 
	input=getch();
	if(input=='q')
	{
		start9();
		while(win)
		{
			out9();
			in9();
		} 
	}
	else if(input=='w')
	{
		start16();
		while(win)
		{
			out16();
			in16();
		} 
	}
}
