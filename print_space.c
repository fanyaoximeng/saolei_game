
#include"main.h"
void print_space(int x,int y, int (*sign_Mine)[NN], int (*sign_color)[NN],int (*maze)[NN]) //��Ϊ·�� 
{	

	int t=0; 
//	y=y-1; 
	if(  *(*(sign_Mine+x)+y ) ==0 ) //��δ�� 
	{
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 120);   
		gotoxy(x,2*y);   //�������y������ƶ��ǰ���char 1�ֽ� �ƶ� ���Ը�������������ܸ�����Ӧ������ 	
		printf("");
		gotoxy(x,2*y+1);   //�������y������ƶ��ǰ���char 1�ֽ� �ƶ� ���Ը�������������ܸ�����Ӧ������ 	
		HideCursor(); 	
		printf("��");	
	} 
	else if( *(*(sign_Mine+x)+y ) ==1)  //������������� 
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
			
		gotoxy(x,2*y);   //�������y������ƶ��ǰ���char 1�ֽ� �ƶ� ���Ը�������������ܸ�����Ӧ������ 	
		printf("");
		gotoxy(x,2*y+1);   //�������y������ƶ��ǰ���char 1�ֽ� �ƶ� ���Ը�������������ܸ�����Ӧ������ 	
		HideCursor();
		if(t<9)
		{	
			printf(" %d",t);			
		}
		else
		{	
			printf("��");		
		}
				
	}			                                     			 
}
