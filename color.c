
#include"main.h"

void color(short x) //�Զ��庯���ݲ����ı���ɫ 
{
    if(x>=0 && x<=15)//������0-15�ķ�Χ��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);    //ֻ��һ���������ı�������ɫ 
    else//Ĭ�ϵ���ɫ��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

//    color(0);   printf("��ɫ\n");
//    color(1);   printf("��ɫ\n");
//    color(2);   printf("��ɫ\n"); 
//    color(3);   printf("����ɫ\n");
//    color(4);   printf("��ɫ\n");
//    color(5);   printf("��ɫ\n");
//    color(6);   printf("��ɫ\n"); 
//    color(7);   printf("��ɫ\n");
//    color(8);   printf("��ɫ\n");
//    color(9);   printf("����ɫ\n");
//    color(10);  printf("����ɫ\n");
//    color(11);  printf("��ǳ��ɫ\n"); 
//    color(12);  printf("����ɫ\n");
//    color(13);  printf("����ɫ\n");
//    color(14);  printf("����ɫ\n");
//    color(15);  printf("����ɫ\n");
//    color(16);    //��Ϊ�������15���ָ�Ĭ�ϵ���ɫ 
