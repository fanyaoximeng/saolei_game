
#include"main.h"

void print_time(clock_t start,float *p_stop_temp,int space2) //��ʾʱ�亯�����������0.1�Ż�ˢ�£�������˸ 
{
	float duration;
	float t;
	clock_t stop = clock();  //Ŀǰʱ��	
	
	t =	((float)stop)/CLK_TCK;
		
	if( t - *p_stop_temp > 0.1  )
	{
		duration = ((float)(stop-start))/CLK_TCK;
		gotoxy(3,2*(NN+10));  
		color(16);  	
		printf("        ");//����ԭ���ļ���
		HideCursor();
		
		gotoxy(3,2*(NN+10)+1);   //�������y������ƶ��ǰ���char 1�ֽ� �ƶ� ���Ը�������������ܸ�����Ӧ������ 			
		printf("%.1lf",duration); 
		HideCursor();
		*p_stop_temp=t;   
		
		
		//��ʾʣ�లȫ�� ���� 
		gotoxy(5,2*(NN+10));  
		color(16);  	
		printf("        ");//����ԭ���ļ���
		HideCursor();
		gotoxy(5,2*(NN+10)+1);   //�������y������ƶ��ǰ���char 1�ֽ� �ƶ� ���Ը�������������ܸ�����Ӧ������ 			
		printf("%d",space2); 
		HideCursor();
		
		 
	}
	//������Ͳ��ı�	
}

