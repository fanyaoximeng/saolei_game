
#include"main.h"

int main() 
{	
	int a[NN][NN]={0};    //�����ͼ 
	int maze[NN][NN]={0}; //��ͼ��Ϣ�洢 
	int sign_color[NN][NN]={1};//�洢λ����ɫ 
	int sign_Mine[NN][NN]={0}; //�洢λ���Ƿ��ڱ��㿪 ��Ĭ��δ���㿪Ϊ 0 ���㿪��Ż�������ֺ���ɫ 
	int i=0,j=0;
	int space1=0,space2=0;
	clock_t start;        //ʱ�俪ʼ���� 
	float stop_temp = 0;  //��������ˢ�������˸���޶�ʱ��ˢ�¼�� ��
	float *p_stop_temp = &stop_temp;  //ָ����� 
	int location[2]={2,1};   //������λ�� 
	int *p=location;             //ָ���ʼ�� 
	
	/*************************************************************/ 
	minefield( a , maze ,sign_color);  //1  ���ɵ�ͼ ��Ϣ 
	
	for(i=1;i<NN-1;i++) 
	{
		for(j=1;j<NN-1;j++) 
		{
			if(maze[i][j]==0)
				space1++;	
			
		}
		
	}
	space2=space1;
	
	print_field( maze );    //2  ��ʾ��ͼ 
	/*************************************************************/
	modeset(80,NN+1) ;
	start = clock();        //��ʼ��ʱ  
	gotoxy(3,2*(NN+4)-1);  
	color(16);  	
	printf("��Ϸ��ʱ��      ");//����ԭ���ļ���
	
	gotoxy(5,2*(NN+4)-1);  
	color(16);  	
	printf("ʣ�లȫ����      ");//����ԭ���ļ���
	
	print_player(location[0],location[1]);
	
	
	/*****************************************************************/
	
	gotoxy(18,2*(NN+4)-1);  
	color(16);  	
	printf("WASD����������Ʒ��� ");//����ԭ���ļ��� 
	gotoxy(19,2*(NN+4)-1);  
	color(16);  	
	printf("enter ȷ��  ");//����ԭ���ļ��� 
	gotoxy(20,2*(NN+4)-1);  
	color(16);  	
	printf("ESC   �˳�  ");//����ԭ���ļ���  
	/****************************************************************/
	while (1)
    {
    	/***********��Ϸ��ʱ��ʾ*********/ 	
    	print_time(start , p_stop_temp,space2);	//��ʾ��Ϸʱ�� 
		
    	//gotoxy(40,-1);     //������Ӱ��    
		HideCursor(); 
			
		/**�����������**/ 
		if( (GetKeyState(38 )<0) ||(GetKeyState('W')<0) ||(GetKeyState('w')<0))  //�� 
		{ 
			print_time(start , p_stop_temp,space2);	//��ʾ��Ϸʱ�� 
			if(maze[location[0]-1][location[1]] != -1)  //����ǽ�ſ��Բ���  
			{
				print_space(location[0],location[1],sign_Mine,sign_color,maze);		
				location[0]= location[0] - 1; 
				print_player(location[0],location[1]);	
				Sleep(200);			//��ֹ����û��̧��ʱ��������						
			}  
		}	
		 
		if( (GetKeyState(40 )<0) ||(GetKeyState('S')<0) ||(GetKeyState('s')<0)) //�� 
		{ 
			print_time(start , p_stop_temp,space2);	//��ʾ��Ϸʱ�� 
		    if(maze[location[0]+1][location[1]] != -1)  
			{	
				print_space(location[0],location[1],sign_Mine,sign_color,maze);		
				location[0]= location[0] + 1; 
				print_player(location[0],location[1]);				
				Sleep(200);											
			} 
		} 
					
		if( (GetKeyState(37 )<0) ||(GetKeyState('A')<0) ||(GetKeyState('a')<0))	    //�� 
		{ 
			if(maze[ location[0] ][ location[1] - 1] != -1)
			{										
				print_space(location[0],location[1],sign_Mine,sign_color,maze);		
				location[1]= location[1] - 1; 
				print_player(location[0],location[1]);				
				Sleep(200);																
			} 											
			  
		}		  
			
		if( (GetKeyState(39 )<0) ||(GetKeyState('D')<0) ||(GetKeyState('d')<0))   //�� 
		{
		   	print_time(start , p_stop_temp,space2);	//��ʾ��Ϸʱ�� 			    	
			if(maze[ location[0] ][ location[1] + 1] != -1)
			{										
				print_space(location[0],location[1],sign_Mine,sign_color,maze);		
				location[1]= location[1] + 1; 
				print_player(location[0],location[1]);				
				Sleep(200);																
			} 	    
		}
		
		if( (GetKeyState(108 )<0) ||(GetKeyState(13)<0) )                          //enter 
		{ 
			print_time(start , p_stop_temp,space2);	//��ʾ��Ϸʱ�� 
		    if(sign_Mine[location[0]][location[1]] == 0)            //δ�������Ĳ��ܲ鿴 //�ж��Ƿ�Ϊ��  ���Ϊ�� ��ʾ�׽�����Ϸ														//������ǣ���ʾλ�õ����֣�������Ϸ 	
			{	
				if(a[location[0]][location[1]]==1  )//ը����������Ϸ 
				{
					//sign_main=0; 
					//	print_mine();   //��ʾը�� 
					//	break;
					sign_Mine[location[0]][location[1]]=1 ;  //����λ�ÿ�����־�� 1 
					print_space(location[0],location[1],sign_Mine,sign_color,maze);	
					
					gotoxy(8,2*(NN+3)-1);  
					color(16);  	
					printf("��Ϸʧ�ܣ������¿�ʼ");//����ԭ���ļ���
					while(1);
					
				}
				else
				{
					sign_Mine[location[0]][location[1]]=1 ;  //����λ�ÿ�����־�� 1 	
					print_space(location[0],location[1],sign_Mine,sign_color,maze);	
					space2--;
					
					if(space2==0)
					{
						gotoxy(8,2*(NN+7)-1);  
						color(16);  	
						printf("��Ϸ�ɹ���");//����ԭ���ļ���		
						return 0; 		
					}
						
						
				} 		
				Sleep(200);											
			} 	
			
		}
		if( (GetKeyState(27 )<0) )  //esc
		{ 
			print_time(start , p_stop_temp,space2);	//��ʾ��Ϸʱ�� 
			Sleep(200);			//��ֹ����û��̧��ʱ��������	
			return 0;					  
		}	 	
		print_time(start , p_stop_temp,space2);	//��ʾ��Ϸʱ�� 		             
    }
	
	return 0;
}

	
