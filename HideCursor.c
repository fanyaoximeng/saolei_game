 
#include"main.h"
void HideCursor() //���ع�� 
{
	CONSOLE_CURSOR_INFO curInfo; //��������Ϣ�Ľṹ�����
	curInfo.dwSize = 1;          //���û��ֵ�Ļ������ع����Ч
	curInfo.bVisible = FALSE;    //���������Ϊ���ɼ�
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
	SetConsoleCursorInfo(handle, &curInfo);          //���ù����Ϣ
}

