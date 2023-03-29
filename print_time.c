
#include"main.h"

void print_time(clock_t start,float *p_stop_temp,int space2) //显示时间函数，间隔超过0.1才会刷新，避免闪烁 
{
	float duration;
	float t;
	clock_t stop = clock();  //目前时间	
	
	t =	((float)stop)/CLK_TCK;
		
	if( t - *p_stop_temp > 0.1  )
	{
		duration = ((float)(stop-start))/CLK_TCK;
		gotoxy(3,2*(NN+10));  
		color(16);  	
		printf("        ");//覆盖原来的计数
		HideCursor();
		
		gotoxy(3,2*(NN+10)+1);   //光标数组y坐标的移动是按照char 1字节 移动 所以覆盖两个坐标才能覆盖相应的文字 			
		printf("%.1lf",duration); 
		HideCursor();
		*p_stop_temp=t;   
		
		
		//显示剩余安全区 个数 
		gotoxy(5,2*(NN+10));  
		color(16);  	
		printf("        ");//覆盖原来的计数
		HideCursor();
		gotoxy(5,2*(NN+10)+1);   //光标数组y坐标的移动是按照char 1字节 移动 所以覆盖两个坐标才能覆盖相应的文字 			
		printf("%d",space2); 
		HideCursor();
		
		 
	}
	//不满足就不改变	
}

