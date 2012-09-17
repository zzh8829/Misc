# include "stdio.h" 
# define M  3 


void main (  ) 

 { 
  float MAT[M][2*M]; 
  float MAT1[M][M]; 
  float t; 
  int i,j,k,l; 

/***********************************************/ 

   /*对矩阵进行初始化*/ 
  for(i=0;i<M;i++) 
    for(j=0;j<2*M;j++) 
      MAT1[i][j]='\0'; 
  
  for(i=0;i<M;i++) 
     for(j=0;j<2*M;j++) 
     MAT[i][j]='\0'; 

    /*对MAT1矩阵赋初值  */ 
  for(i=0;i<M;i++) 
    for (j=0;j<M;j++) 
      scanf("%f",&MAT1[i][j]); 


  /*打印目标矩阵?*/ 
  printf("原矩阵为：\n"); 
  for (i=0;i<M;i++) 
    { 
     for (j=0;j<M;j++)   
printf("%5.2f",MAT1[i][j]); 
     printf("\n"); 
     } 

/********************************************/ 

    /*对MAT1矩阵进行扩展,MAT1矩阵添加单位阵，由M*M变成2M*2M矩阵  */ 
  for(i=0;i<M;i++) 
    for(j=0;j<2*M;j++) 
      if (j<M)  MAT[i][j]=MAT1[i][j]; 
     else if (j==M+i)  MAT[i][j]=1; 
   else MAT[i][j]=0; 


    /*对M矩阵进行变换，使得前半部分矩阵成为单位阵，则  */ 
    /*后半部分矩阵即为所求矩阵逆阵  */ 
  for(i=0;i<M;i++) 
   { 
    /*对第i行进行归一化    */ 
     for (j=0;j<2*M;j++) 
     for(k=i+1;k<M;k++) 
MAT[i][j]=MAT[i][j]+MAT[k][j]; 
     t=MAT[i][i]; 
     for(j=i;j<2*M;j++) 
MAT[i][j]=MAT[i][j]/t; 

     /*对矩阵进行行变换，使得第i 列只有一个元素不为零，且为1*/ 
     for(k=0;k<M;k++) 
if(k!=i) 
  { 
   t=MAT[i][k]; 
   for (l=i;l<2*M;l++) 
   MAT[k][l]=MAT[k][l]-MAT[i][l]*t; 
  } 
     } 


 /*将后半部分矩阵即所求矩阵逆阵存入MAT2矩阵。*/ 
  for(i=0;i<M;i++) 
   { 
  
    for(j=0;j<M;j++) 
      MAT1[i][j]=MAT[i][j+M]; 
    printf("\n"); 
      
   } 


/*********************************************/ 

   /*输出所求的逆阵*/ 
   printf("逆阵为：\n"); 
   for(i=0;i<M;i++) 
   { 
    
     for(j=0;j<M;j++) 
     printf("%5.2f",MAT1[i][j]); 
     printf("\n"); 
   } 

} 