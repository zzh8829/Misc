#include "stdio.h"
void main()
{
   FILE *funny,*printer,*fp;
   char c;

   funny = fopen("TENLINES.TXT","r"); /*打开文本文件 */
   printer = fopen("PRN","w");        /*开启打印机*/
   fp = fopen("weew.TXT","w");
   do{
     c = getc(funny);    /* 从文件中得到一个字符 */
     if(c != EOF)
     {
       putchar(c);      //屏幕上显示字符
       putc(c,printer); // 打印机上打印字符
     
     }
   }while (c != EOF);    /*重复直到 EOF (end of file)  */
   fprintf(fp,"%s",*funny);
   fclose(funny);
   fclose(printer);
   fclose(fp);//关闭打印机
}
