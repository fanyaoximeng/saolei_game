#include<stdio.h>
#include<string.h>                     
#include <stdlib.h>   //����Լ����԰�,��Ҳ�����ˣ�������˼
#include <conio.h>
#include <windows.h>
#include <time.h>



#define	NN 25   //���̴�СΪ�� NN-2 ��*�� NN-2 �� ������Ϊ�߽� 

#define	NUM 4  //�����׵ļ���   3��������֮һ 

void minefield( int (*mine1)[NN] ,  int (*mine2)[NN] ,int (*sign_color)[NN] );

void print_field( int(*maze)[NN] );

void print_time(clock_t start,float *p,int space2); 


void color(short x); //�Զ��庯���ݲ����ı���ɫ 


void gotoxy(int y,int x); 
void HideCursor();
void print_player(int x,int y); 
void print_space(int x,int y, int (*sign_Mine)[NN], int (*sign_color)[NN],int (*maze)[NN]) ;//��Ϊ·�� 
void print_hunter(int ,int );
void print_wall(int x,int y);//��Ϊ·
void print_player(int x,int y); 


void modeset(int w,int h) ;//�����С ,����������̫��





