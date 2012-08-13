/* C标志符命名源程序*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

char* IsLegal(char* CheckWord);

char* ErrorMessages[]={ /*错误信息列表*/
			"无错误！",
			"1  首字符只能是字母或下划线！",
			"2  常、变量只能由字母、下划线和数字构成！",
			"3  常、变量标识不能用Ｃ语言关键字！",
			"4  常、变量标识不能用Ｃ语言函数！",
			"内存不够！"
};


void main(void)
{
  char *Prompt="C语言标志符的命名要遵守以下原则:";
  char *TestWord;
  int   i;

  TestWord = (char *)malloc( sizeof(char)*32 ); /*TestWord存放用户输入*/
  if( !TestWord ) 
    return;

  /*显示部分提示信息*/
  puts(Prompt);
  for( i=1 ;i<=4;i++){
    puts( ErrorMessages[i] );
  }
  puts("");

  while(1){
    printf("\n\n请输入一个标志符(大写的Q退出) :");/*提示*/
    scanf("%s",TestWord);                   /*得到用户输入*/
    if( (toupper)(TestWord[0])=='Q' )
      break;/*循环出口*/
    printf("\n%s   %s",TestWord,IsLegal(TestWord)); /*判定标志符的合法性*/
  }

  free( TestWord );
}


/*此函数检验标志符命名的合法性*/
char* IsLegal(char* CheckWord)
{
  char* KeyWords[]={"auto","break","case","char","continue","const","default",
		   "do","double","else","enum","extern","float","for","goto",
		   "if","int","long","noalias","register","return","short",
		   "signed","sizeof","static","struct","switch","typedef",
		   "union","unsigned","void","volatile","while","defined",
		   "define","undef","include","ifdef","ifndef","endif","line",
		   "error","elif","pragma"};/*C关键字列表*/
  char* Functions[]={"close","creat","eof","fclose","fcloseall","feof","fopen",
			"ferror","fgetchar","fgets","fprintf","fputc","fputchar",
			"fseek","get","putch","putc","printf","open","putchar",
			"puts","read","scanf","abs","acos","asin","math","atan",
			"atan2","atof","atoi","atol","ceil","dos","cosh","ecvt",
			"exp","fabs","floor","fmod","frexp","itoa","labs","ldexp",
			"log","log10","modf","pow","rand","sin","sqrt","srand",
			"strtod","strlol","tan","tanh","ultoa","memset","strcpy",
			"struct","strchr","strcmp","calloc","isalnum","isalpha",
			"toascii","tolower","tollpper","exit"};/*C主要函数列表*/

  char* Others="_";/*'_'也可以用于关键字,但我们不推荐您使用!*/
  int WordLength,i;
  char* WordTemp;

  WordTemp = (char*)malloc( 32 *sizeof(char ) );
  if( !WordTemp ) return ErrorMessages[5];

  WordLength=strlen(CheckWord);

  /*检查标志符命名原则1*/
  if((isalpha(CheckWord[0])==0)&&(CheckWord[0]!=Others[0]))
	return ErrorMessages[1];
  /*检查标志符命名原则2*/
  for(i=0;i<WordLength;i++) 
    if((isalnum(CheckWord[i])==0)&&(CheckWord[i]!=Others[0]))
      return ErrorMessages[2];
  /*检查标志符命名原则3*/
  for(i=0;i<44;i++)
  {
    if(!strcmp(CheckWord,KeyWords[i]))
      return ErrorMessages[3];
  }
  i=0;
  for(i=0;i<69;i++) /*检查标志符命名原则4*/
  {
    if(!strcmp(CheckWord,Functions[i]))
      return ErrorMessages[4];
  }

  free(WordTemp);
  return ErrorMessages[0];
}