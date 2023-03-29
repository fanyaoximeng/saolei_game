
#include"main.h"
	//minefield(    a ,                  maze ,             sign_color);  //1  生成地图 信息 
void minefield( int (*mine1)[NN] ,  int (*mine2)[NN] ,int (*sign_color)[NN])
{
	int t=0;
	int i=0,j=0;
	int temp;//雷产生的临时参数 
	
	
	srand((unsigned int)time(NULL));    //产生雷区 
	for(i=0;i<NN;i++)
	{ 
		for(j=0;j<NN;j++)
		{
			if(i==0||i==NN-1||j==0||j==NN-1)  //外围墙 
			{
				*(*(mine1+i)+j ) =  -1;
				continue;
			}	
			temp=rand() % NUM;  //地图的NUM分之一为雷区 
			if(temp==1)	
				*(*(mine1+i)+j )=1;
			else
				*(*(mine1+i)+j )=0;     //随机产生雷 
		}
	}
	
	for(i=0;i<NN;i++)
	{ 
		for(j=0;j<NN;j++)
		{
			if(i==0||i==NN-1||j==0||j==NN-1)//边界设置为-1 
			{
				*(*(mine2+i)+j )=-1;
				continue;
			}	
			if( *(*(mine1+i)+j )==1	)       //雷区设置为9 
			{
				*(*(mine2+i)+j )=9;
				continue;		
			}	
			t=0;
			if(  *(*(mine1+i-1)+j-1 ) != -1 &&  *(*(mine1+i-1)+j-1 ) != 0  )		
				++t;
			if(  *(*(mine1+i-1)+j ) != -1   &&  *(*(mine1+i-1)+j ) != 0  )		
				++t;
			if(  *(*(mine1+i-1)+j+1 ) != -1 &&  *(*(mine1+i-1)+j+1 ) != 0  )		
				++t;
			/*-------------------------------------------*/
			if(  *(*(mine1+i)+j-1 ) != -1   &&  *(*(mine1+i)+j-1 ) != 0  )		
				++t;
			if(  *(*(mine1+i)+j+1 ) != -1   &&  *(*(mine1+i)+j+1 ) != 0  )		
				++t;
			/*-------------------------------------------*/
			if(  *(*(mine1+i+1)+j-1 ) != -1 &&  *(*(mine1+i+1)+j-1 ) != 0  )		
				++t;
			if(  *(*(mine1+i+1)+j) != -1    &&  *(*(mine1+i+1)+j ) != 0  )		
				++t;
			if(  *(*(mine1+i+1)+j+1 ) != -1 &&  *(*(mine1+i+1)+j+1 ) != 0  )		
				++t;
			*(*(mine2+i)+j )=t;	       //无雷区显示周围雷的个数 
		
			if(t==0||t==1||t==2)
				*(*(sign_color+i)+j )= 127;
			else if(t==3||t==4||t==5)
				*(*(sign_color+i)+j) = 120;
			else if(t==6||t==7||t==8)
				*(*(sign_color+i)+j )= 124;
			else if(t==9)
				*(*(sign_color+i)+j )= 64;
			
			
		}				
	}	
}

