
#include"guangbiao.h" 

void gotoxy(int y,int x)  //�ƶ���굽��Ӧ��λ�� 
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos1;
	COORD pos2;
    pos1.X = x;
    pos1.Y = y;
    pos2.X = x+1;
    pos2.Y = y;
    
    SetConsoleCursorPosition(handle,pos1);
    SetConsoleCursorPosition(handle,pos2);
}
