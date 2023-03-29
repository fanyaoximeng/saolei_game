
#include"main.h"

int main() 
{	
	int a[NN][NN]={0};    //定义地图 
	int maze[NN][NN]={0}; //地图信息存储 
	int sign_color[NN][NN]={1};//存储位置颜色 
	int sign_Mine[NN][NN]={0}; //存储位置是否内被点开 ，默认未被点开为 0 ，点开后才会出现数字和颜色 
	int i=0,j=0;
	int space1=0,space2=0;
	clock_t start;        //时间开始参数 
	float stop_temp = 0;  //避免过快的刷新造成闪烁，限定时间刷新间隔 。
	float *p_stop_temp = &stop_temp;  //指针操作 
	int location[2]={2,1};   //存放玩家位置 
	int *p=location;             //指针初始化 
	
	/*************************************************************/ 
	minefield( a , maze ,sign_color);  //1  生成地图 信息 
	
	for(i=1;i<NN-1;i++) 
	{
		for(j=1;j<NN-1;j++) 
		{
			if(maze[i][j]==0)
				space1++;	
			
		}
		
	}
	space2=space1;
	
	print_field( maze );    //2  显示地图 
	/*************************************************************/
	modeset(80,NN+1) ;
	start = clock();        //开始计时  
	gotoxy(3,2*(NN+4)-1);  
	color(16);  	
	printf("游戏计时：      ");//覆盖原来的计数
	
	gotoxy(5,2*(NN+4)-1);  
	color(16);  	
	printf("剩余安全区域：      ");//覆盖原来的计数
	
	print_player(location[0],location[1]);
	
	
	/*****************************************************************/
	
	gotoxy(18,2*(NN+4)-1);  
	color(16);  	
	printf("WASD及方向键控制方向 ");//覆盖原来的计数 
	gotoxy(19,2*(NN+4)-1);  
	color(16);  	
	printf("enter 确认  ");//覆盖原来的计数 
	gotoxy(20,2*(NN+4)-1);  
	color(16);  	
	printf("ESC   退出  ");//覆盖原来的计数  
	/****************************************************************/
	while (1)
    {
    	/***********游戏计时显示*********/ 	
    	print_time(start , p_stop_temp,space2);	//显示游戏时间 
		
    	//gotoxy(40,-1);     //避免光标影响    
		HideCursor(); 
			
		/**避免输入堵塞**/ 
		if( (GetKeyState(38 )<0) ||(GetKeyState('W')<0) ||(GetKeyState('w')<0))  //上 
		{ 
			print_time(start , p_stop_temp,space2);	//显示游戏时间 
			if(maze[location[0]-1][location[1]] != -1)  //不是墙才可以操作  
			{
				print_space(location[0],location[1],sign_Mine,sign_color,maze);		
				location[0]= location[0] - 1; 
				print_player(location[0],location[1]);	
				Sleep(200);			//防止键盘没有抬起时继续运行						
			}  
		}	
		 
		if( (GetKeyState(40 )<0) ||(GetKeyState('S')<0) ||(GetKeyState('s')<0)) //下 
		{ 
			print_time(start , p_stop_temp,space2);	//显示游戏时间 
		    if(maze[location[0]+1][location[1]] != -1)  
			{	
				print_space(location[0],location[1],sign_Mine,sign_color,maze);		
				location[0]= location[0] + 1; 
				print_player(location[0],location[1]);				
				Sleep(200);											
			} 
		} 
					
		if( (GetKeyState(37 )<0) ||(GetKeyState('A')<0) ||(GetKeyState('a')<0))	    //左 
		{ 
			if(maze[ location[0] ][ location[1] - 1] != -1)
			{										
				print_space(location[0],location[1],sign_Mine,sign_color,maze);		
				location[1]= location[1] - 1; 
				print_player(location[0],location[1]);				
				Sleep(200);																
			} 											
			  
		}		  
			
		if( (GetKeyState(39 )<0) ||(GetKeyState('D')<0) ||(GetKeyState('d')<0))   //右 
		{
		   	print_time(start , p_stop_temp,space2);	//显示游戏时间 			    	
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
			print_time(start , p_stop_temp,space2);	//显示游戏时间 
		    if(sign_Mine[location[0]][location[1]] == 0)            //未被开启的才能查看 //判断是否为雷  如果为雷 显示雷结束游戏														//如果不是，显示位置的数字，继续游戏 	
			{	
				if(a[location[0]][location[1]]==1  )//炸弹，结束游戏 
				{
					//sign_main=0; 
					//	print_mine();   //显示炸弹 
					//	break;
					sign_Mine[location[0]][location[1]]=1 ;  //将该位置开启标志赋 1 
					print_space(location[0],location[1],sign_Mine,sign_color,maze);	
					
					gotoxy(8,2*(NN+3)-1);  
					color(16);  	
					printf("游戏失败！请重新开始");//覆盖原来的计数
					while(1);
					
				}
				else
				{
					sign_Mine[location[0]][location[1]]=1 ;  //将该位置开启标志赋 1 	
					print_space(location[0],location[1],sign_Mine,sign_color,maze);	
					space2--;
					
					if(space2==0)
					{
						gotoxy(8,2*(NN+7)-1);  
						color(16);  	
						printf("游戏成功！");//覆盖原来的计数		
						return 0; 		
					}
						
						
				} 		
				Sleep(200);											
			} 	
			
		}
		if( (GetKeyState(27 )<0) )  //esc
		{ 
			print_time(start , p_stop_temp,space2);	//显示游戏时间 
			Sleep(200);			//防止键盘没有抬起时继续运行	
			return 0;					  
		}	 	
		print_time(start , p_stop_temp,space2);	//显示游戏时间 		             
    }
	
	return 0;
}

	
