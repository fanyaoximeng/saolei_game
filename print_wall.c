#include"main.h"

void print_wall(int x,int y) //��Ϊ·�� 
{	
	y=y-1;
	gotoxy(x,2*y);   //�������y������ƶ��ǰ���char 1�ֽ� �ƶ� ���Ը�������������ܸ�����Ӧ������ 	
	printf("");
	
	gotoxy(x,2*y+1);   //�������y������ƶ��ǰ���char 1�ֽ� �ƶ� ���Ը�������������ܸ�����Ӧ������ 	
	HideCursor(); 	
				                                         //û�кܺõ����䣬Ϊ�˷���������Ե�·��ȫ�ں��֣� 			 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 127);
	printf("ǽ");
					
}
