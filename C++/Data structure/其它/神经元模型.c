/*神经元模型*/
#include < math.h>
#include < stdio.h>
#include < time.h>
#include < stdlib.h>
#include < conio.h>
#define AND1 .571388
#define AND2 .560999
#define OR1 1.149045
#define OR2 1.131896
#define SITA 1
#define NIU .1
#define OMIGA 50

float w[2]; 
float terg[4][3]; 

main()
{int m_result = 1, s; 
 float w1[2]; 
 while(m_result != 5){
	m_result = menu(m_result); 
	date(); 
	switch(m_result){
		case(1):             /*    学习*/
		case(3):randomize();  /*重新学习*/
			w[0] = random(80)+10; w[0] = w[0]/100.0; 
			w[1] = random(80)+10; w[1] = w[1]/100.0; 
			study(); 
			break; 
		case(2):practic(w);   /*实践新模型*/
			break; 
		case(4):printf(" what do you want to see, OR or AND?(1/2) " ); 
			scanf(" %d" , & s); 
			if(s==1){w1[0] = OR1;  w1[1] = OR2;  }
			   else if(s==2){w1[0] = AND1; w1[1] = AND2; }
				else break; 
			practic(w1); 
			break;        /*演示已有模型*/
		default:{}
		}       /*End Switch*/
	}               /*End While */
 clrscr(); 
 printf(" Good Bye!" ); 
}
menu(int r)
{int r1; 
 clrscr(); 
 printf(" \n\n\n" ); 
 printf(" \t\t1\tStudy a Model\n" );     /*    学习    */
 printf(" \t\t2\tPratice the model\n" ); /*重新学习    */
 printf(" \t\t3\tDefail the MOdel\n" );  /*实践新模型  */
 printf(" \t\t4\tPrepared Model\n" );    /*演示已有模型*/
 printf(" \t\t5\tEnd\n" );               /*结束        */
 printf(" \n\n\t\tWhat do you want to choice?(%d)" , r); 
 r1 = getche(); 
 if (r1!=13) r = r1-48; 
 return(r); 
}

date()    /*显示模型*/
{int i, j; 
 clrscr(); 
 for(i = 0; i < 4; i++) 
	 for(j = 0; j< 3; j++){ 
		gotoxy(20+j*4, i+5);  
		printf("%.0f", terg[i][j]);  
		} 
printf("\n\n\tThe quarities:%f, %f \n", w[0], w[1]);  
} 

study() /*学习子函数*/ 
{float x, y, width;  
	int wrong = 1, i, total = 0; 
	input();  /*andinput(); */ /*orinput();  */ 
	while(wrong){ 
		wrong = 0;  
		for(i = 0; i< 4; i++){
			x = OMIGA*(w[0]*terg[i][0]+w[1]*terg[i][1]-SITA); 
			y = 1.0/(1.0+exp(-x)); 
			width = terg[i][2]-y;  /*误差 = "教师信号-Y" */ 
			if(fabs(width)>=.01){
			 wrong = 1; 
			 total++; 
			 w[0] = w[0]*(1+width*NIU);     /*改变权值0*/
			 w[1] = w[1]*(1+width*NIU);     /*改变权值1*/
			 if(total> =200)       /*防止程序进入死循环*/
				{error(); return 1; }
			 }
		 }
	 }/*若i的四次循环均满足" fabs(width)> =.01" 则wrong=0, 结束循环*/
}
practic(quarity) /*实践新模型或演示已有模型, 由quarity[]值决定*/
float quarity[2]; 
{int k, y; 
 float x, width, x1, x2; 
 for(k = 0; k < 4; k++){ 
	 gotoxy(0, 4+k*3);  
	 printf("\nPlease input :x1, x2 ");  
	 scanf("%f, %f", &x1, &x2);  
	 x = OMIGA*(quarity[0]*x1+quarity[1]*x2-SITA); 
	 y = 1.0/(1.0+exp(-x))+.01;  /*精度为0.01*/ 
	 printf("\t\t\ty = "%d" , y); 
	 getch();  
	 } 
} 

input() /*当选择"学习"功能时输入事件*/ 
{int i;  
	printf("Please input the 4 groups data:\n\n");  
	for(i = 0; i< 4; i++){
		printf("\tThe %d group x1, x2, teacher's point: ", i+1);  
		scanf("%f, %f, %f", &terg[i][0], &terg[i][1], &terg[i][2]);  
		} 
	clrscr();  
} 

andinput() 
{terg[0][0] = 1; terg[0][1] = 1; terg[0][2] = 1; 
	terg[1][0] = 1; 
	terg[1][1] = 0; 
	terg[1][2] = 0; 
	terg[2][0] = 0; 
	terg[2][1] = 1; 
	terg[2][2] = 0; 
	terg[3][0] = 0; 
	terg[3][1] = 0; 
	terg[3][2] = 0; 
} 

orinput() 
{terg[0][0] = 1; 
	terg[0][1] = 1; 
	terg[0][2] = 1; 
	terg[1][0] = 1; 
	terg[1][1] = 0; 
	terg[1][2] = 1; 
	terg[2][0] = 0; 
	terg[2][1] = 1; 
	terg[2][2] = 1; 
	terg[3][0] = 0; 
	terg[3][1] = 0; 
	terg[3][2] = 0; 
} 

error() /*初始权值选择不当或模型无法实现(如异或模型)时退出*/ 
{clrscr();  
	printf("\n\n\n\tBecause the firse QUARITIES's choise is unavailble, \n");  
	printf("\tIt can't get the right result, forveve!");  
} 
 