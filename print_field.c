

#include"main.h"

//��ӡ�Թ�
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
				printf("ǽ");
				color(16); 	
			}
//			else if(*(*(maze + i) + j) == 9)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
//				printf("��");
//					
//			}
			else 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 120);   //����ʵ����Եõ��������� ���ֺ���ĸ�ƶ�������
				                                                                 //û�кܺõ����䣬Ϊ�˷���������Ե�·��ȫ�ں��֣� 
				printf("��");	
			}				
		}
		printf("\n");
	}
	color(16); 	 //�ָ���ɫ 
	
}


