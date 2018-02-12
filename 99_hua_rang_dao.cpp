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
/////////////////////////////////////////////////////////////////////////////////////以下全局 
	int a[20]={1,2,3,4,5,6,7,8},input;
	int b[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int c1=0,c2=0;
	int t,now;//交换中的代替值，现在空项所在位置 
	int i,win=1,ok=0;//判断完全复原，判断当前已复原个数 
	int nowtime,starttime; 
void change(int*a,int*b)//交换两个数值 
{
	t=*a;
	*a=*b;
	*b=t;
}
void allstart()//总起点 
{
	printf("Click q or w to choose 9 or 16."); 
	input=getch();
	nowtime=starttime=time(NULL);
}
///////////////////////////////////////////////////////////////////////////////////////以下4*4
void start16()
{
	hidecursor();//隐藏光标 
	system("cls");//清屏 
	srand(time(NULL));
	for(i=1;i<=100;i++)//反复交换打乱
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
	if(input=='b')//保证有解 
		change(&b[15],&b[14]);
}
void out16()
{
	system("cls");
	nowtime=time(NULL);
	for(i=0;i<=15;i++)
	{
		if(i%4==0)
			puts("\n");
		if(b[i]!=0)
			printf("%4d",b[i]);
		else if(b[i]==0)//空项独立输出 
		{
			printf("    ");
			now=i;
		}			
	}
	printf("\n%d",nowtime-starttime);
	for(i=0;i<=15;i++)//判断复原个数 
		if(b[i]==i+1)
			ok++;
	if(ok>=15)
	{
		win=0;
		printf("   win!!\n");
	}	
	ok=0;
}
///////////////////////////////////////////////////////////////////////////////////////////////以下3*3 

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
	nowtime=time(NULL);
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
	printf("\n%d",nowtime-starttime);
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
///////////////////////////////////////////////////////////////////
void finish()
{
	printf("time==%d\n",nowtime-starttime);
	win=1;
}
int main()
{
	while(1)//无限反复 
	{
		allstart();
		if(input=='q')//3*3
		{
			start9();
			while(win)
			{
				out9();
				in9();
			} 
		}
		else if(input=='w')//4*4
		{
			start16();
			while(win)
			{
				out16();
				in16();
			} 
		}
		finish();
	}
}
