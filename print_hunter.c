#include"guangbiao.h" 
#include"modeset.h"


void print_hunter(int x,int y)
{
	y=y-1; 
		
	gotoxy(x,2*y);   //�������y������ƶ��ǰ���char 1�ֽ� �ƶ� ���Ը�������������ܸ�����Ӧ������ 
	HideCursor();
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 25);
	printf("");
	
	gotoxy(x,2*y+1);   //�������y������ƶ��ǰ���char 1�ֽ� �ƶ� ���Ը�������������ܸ�����Ӧ������ 
	HideCursor();
	printf("��");      
	
	

	//color(16); 
		
}
