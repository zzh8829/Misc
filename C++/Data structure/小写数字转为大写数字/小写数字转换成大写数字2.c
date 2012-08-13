/***  程序: 123.45    则输出“壹佰贰拾叁点肆伍” ***/


#include <stdio.h>  /*标准输入输出函数*/
#include <string.h>  /*字符串函数*/
#include <stdlib.h>  

void ConvertN(int n,char* &p,bool IsSequece=true);  /*声明函数ConvertN*/
bool ConvertSegment(int number,int n,char* &p,bool IsLastZiero); /*声明函数ConvertSegment*/
bool ChangeNumber(double dbNumber,char* lpszvalues);  /*声明函数ChangeNumber*/

void main() 
{ 
 double db=-1200008.9876; 
 printf("%lf\n",db); 
 char buf[100]; 
 if(ChangeNumber(db,buf)) 
   printf("%s\n",buf); 

 db=1000000.98; 
 printf("%lf\n",db); 
 if(ChangeNumber(db,buf)) 
   printf("%s\n",buf); 

 db=10000008.0987; 
 printf("%lf\n",db); 
 if(ChangeNumber(db,buf)) 
   printf("%s\n",buf); 

 db=10200408.09007; 
 printf("%lf\n",db); 
 if(ChangeNumber(db,buf)) 
   printf("%s\n",buf); 

 db=10020400.007; 
 printf("%lf\n",db); 
 if(ChangeNumber(db,buf)) 
   printf("%s\n",buf); 
} 

void ConvertN(int n,char* &p,bool IsSequece/*=true*/) 
/*定义函数ConvertN
 "小数位转换" 将数字n(0<=n<=9)转换成中文后存入p,IsSequece控制存放顺序 */
{ 
 if(n<0 || n>9)   
 { 
   printf("Error:数组超界!\n");   /*如果超过界限就输出错误*/
   exit(0);    /*跳出函数*/
 } 

 char num[]="零壹贰叁肆伍陆柒捌玖"; 
 if(IsSequece)                         /*如果IsSequece为真就顺序存放*/
 { 
   *p++=num[2*n]; 			/*因为汉字是双字节的所以，在把阿拉伯数字转化时比如0对应的零是双字节，占数组的0和1的位置，其他的以此类推*/
   *p++=num[2*n+1]; 
 } 
 else                                  /*如果IsSequece为非即反序存放*/
 { 
   *p++=num[2*n+1]; 
   *p++=num[2*n]; 
 } 
} 

bool ConvertSegment(int number,int n,char* &p,bool IsLastZiero) 
/*定义函数 ConvertSegment
 "整数位转换" 将number转换成中文后反序存入字符指针p 
number为某数整数部分的第n节(由低位到高位从个位开始每4位为一节,n从0开始) */
{ 
 char num1[]="  拾佰仟"; 
 char num2[]="点万亿兆"; 

 if(number==0) 
 { 
   if(n==0) 
   { 
     *p++=num2[2*n+1]; 
     *p++=num2[2*n]; 
   } 
   return IsLastZiero; 
 } 

 if(IsLastZiero) 
 { 
   ConvertN(0,p,false); 
 } 

 *p++=num2[2*n+1]; 
 *p++=num2[2*n]; 

 bool flag=true;                      /* 前面是否有零 */
 for(int i=0;number!=0 && i<4;i++) 
 { 
   int m; 
   m=number%10; 
   if(m==0 && !flag) 
   { 
     flag=true; 
     ConvertN(0,p,false); 
   } 
   else if(m!=0) 
   { 
     flag=false; 
     if(i==0) 
     { 
       ConvertN(m,p,false); 
     } 
     else 
     { 
       *p++=num1[2*i+1]; 
       *p++=num1[2*i]; 
       ConvertN(m,p,false); 
     } 
   } 
   number/=10; 
 } 

 if(i>=4) 
   return false; 
 else 
   return true; 

} 

bool ChangeNumber(double dbNumber,char* lpszvalues)  
{ 
 /*定义函数 ChangeNumber	
   整数部分最多8位，小数部分最多6位 */
 if(dbNumber<0.0000001 && -dbNumber<0.0000001)                    //数位太小 
 { 
   strcmp(lpszvalues,"零"); 
   return true; 
 } 
 if(dbNumber>100000000L || -dbNumber>100000000L)                  //数位太大 
   return false; 

 /* 开始处理 */
 char buf1[50],buf2[50],*p1=buf1,*p2=buf2; /* 结果的整数部分和小数部分缓冲区 */
 /* p1是整数指针 p2是小数指针 */
 double c=dbNumber; 
 c=c>0?c:-c; 
 /*取得大实数的整数部分和小数部分并非易事,long的长度直接限制了整数部分的长度, 
   除非构造出更大的整数或直接利用实数计算,否则难以办到! 
   此外受实数精度的影响,有时会导致小数部分的畸形! 
   精请高手指点!!! 
 */ 
 unsigned long a=(unsigned long)c;         /*整数部分*/
 double b=c-a;                             /*小数部分*/
 /*printf("%lu\n",a); 
   printf("%lf\n",b); 
   printf("%lf\n",c);*/
  
 /* 处理小数部分 */
 for(int i=0;i<6;i++) 
 { 
   b*=10;  		/*将小数最高位向前进一位取得整数*/
   int n=int(b); 	
   ConvertN(n,p2);    /*转换成字符数值*/
   b-=n;      /*减去整数部分的数取得下一位小数,将其成为整数*/
 } 
 *p2='\0';

 /* 处理整数部分 */
 int count=0; 
 bool flag=false; 
 while(a!=0) 
 { 
   int buf=a%10000; 
   flag=ConvertSegment(buf,count++,p1,flag); 
   a/=10000; 
 } 

 /*是否有负号 */
 char *p=lpszvalues; 
 if(dbNumber<0) 
 { 
   strcpy(p,"负"); 
   p+=2; 
 } 

 /* 连接整数部分和小数部分 */
 p1--; 
 while(p1>=buf1) 
   *p++=*p1--; 
 *p='\0'; 
 strcat(lpszvalues,buf2); 

 return true; 
} 
