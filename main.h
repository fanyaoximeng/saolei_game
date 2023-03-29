#include<stdio.h>
#include<string.h>                     
#include <stdlib.h>   //大家自己试试吧,我也忘记了，不好意思
#include <conio.h>
#include <windows.h>
#include <time.h>



#define	NN 25   //雷盘大小为（ NN-2 ）*（ NN-2 ） 两个数为边界 

#define	NUM 4  //产生雷的几率   3就是三分之一 

void minefield( int (*mine1)[NN] ,  int (*mine2)[NN] ,int (*sign_color)[NN] );

void print_field( int(*maze)[NN] );

void print_time(clock_t start,float *p,int space2); 


void color(short x); //自定义函根据参数改变颜色 


void gotoxy(int y,int x); 
void HideCursor();
void print_player(int x,int y); 
void print_space(int x,int y, int (*sign_Mine)[NN], int (*sign_color)[NN],int (*maze)[NN]) ;//变为路线 
void print_hunter(int ,int );
void print_wall(int x,int y);//变为路
void print_player(int x,int y); 


void modeset(int w,int h) ;//界面大小 ,给的数不用太大





