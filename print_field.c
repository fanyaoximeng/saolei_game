

#include"main.h"

//打印迷宫
void print_field( int(*maze)[NN] )
{
	int i,j;
	
	
	printf("\n");
	for (i = 0; i < NN; i++)
	{
		printf("  ");
		for (j = 0; j < NN; j++)
		{
			
			if(*(*(maze + i) + j) == -1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 904);
				printf("墙");
				color(16); 	
			}
//			else if(*(*(maze + i) + j) == 9)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
//				printf("雷");
//					
//			}
			else 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 120);   //大量实验测试得到，光标针对 汉字和字母移动有区别，
				                                                                 //没有很好的适配，为了方便操作，对道路用全黑汉字， 
				printf("安");	
			}				
		}
		printf("\n");
	}
	color(16); 	 //恢复颜色 
	
}


