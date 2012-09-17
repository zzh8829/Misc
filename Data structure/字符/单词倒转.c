/*如何实现这个算法 
This is a good day today -> sihT si a doog yad yadot */

#include "stdafx.h" 
#include "string.h" 
#include "malloc.h" 

char *fun(char *a);

int main(int argc, char* argv[]) 
{ 
   char *string = "This is a good day today"; 
   char *ll=fun(string); 
   printf("%s",ll); 
   return 0; 
} 
 
char *fun(char *a) 
{ 
   char *ptt = (char *)malloc(strlen(a)); 
   ptt = a; 
   char *ftt = (char *)malloc(strlen(a)); 
   *ftt = '\0'; 
   char step[] = " "; 
   char *token; 
   token = strtok( strdup(a),step); 
/*strtok()检索字符串s1,该字符串s1是由字符串s2中定义的定界符所分隔*/
/*strdup()将字符串s复制到最近建立的单元*/
   while(token != NULL) 
   { 
      strcat(ftt,strrev(token)); /*strrev()将字符串s复制到最近建立的单元*/
      strcat(ftt," "); 
      token = strtok( NULL,step); 
   } 
   *(ftt + strlen(a)-1) = '\0'; 
   return  ftt; 
} 