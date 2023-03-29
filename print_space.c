
#include"main.h"
void print_space(int x,int y, int (*sign_Mine)[NN], int (*sign_color)[NN],int (*maze)[NN]) //变为路线 
{	

	int t=0; 
//	y=y-1; 
	if(  *(*(sign_Mine+x)+y ) ==0 ) //还未打开 
	{
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 120);   
		gotoxy(x,2*y);   //光标数组y坐标的移动是按照char 1字节 移动 所以覆盖两个坐标才能覆盖相应的文字 	
		printf("");
		gotoxy(x,2*y+1);   //光标数组y坐标的移动是按照char 1字节 移动 所以覆盖两个坐标才能覆盖相应的文字 	
		HideCursor(); 	
		printf("安");	
	} 
	else if( *(*(sign_Mine+x)+y ) ==1)  //当点击看该坐标 
	{	
		t=*(*(maze+x)+y );	      
		if(t==0||t==1||t==2)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 127); 
		else if(t==3||t==4||t==5)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 103); 
		else if(t==6||t==7||t==8)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),199); 
		else if(t==9)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64); 
			
		gotoxy(x,2*y);   //光标数组y坐标的移动是按照char 1字节 移动 所以覆盖两个坐标才能覆盖相应的文字 	
		printf("");
		gotoxy(x,2*y+1);   //光标数组y坐标的移动是按照char 1字节 移动 所以覆盖两个坐标才能覆盖相应的文字 	
		HideCursor();
		if(t<9)
		{	
			printf(" %d",t);			
		}
		else
		{	
			printf("雷");		
		}
				
	}			                                     			 
}
