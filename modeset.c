
#include"main.h"

void modeset(int w,int h)                         //�����С ,����������̫��
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��׼����ľ���������еĳ������ַ��������Ļ�ϡ�
    COORD size = {w, h};                  //���ô��ڵĴ�С��
    SetConsoleScreenBufferSize(hOut,size);//�������û�������С��
    SMALL_RECT rc = {0,0, w, h};          //���ô���λ�úʹ�С��
    SetConsoleWindowInfo(hOut ,1 ,&rc);   //���ô��ڴ�С
    
    return;
}




