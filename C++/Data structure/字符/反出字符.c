/*由Andy自行修改为支持大小写转换*/

#include <stdio.h> 
main() 
{ 
	int i=0,n=0; 
	char ascs[]={"abcdefghijklmnopqrstuvwxyz"};
	char ascb[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	
	char a,b[20];
	while ((a=getchar())!='\n') 
	{  
		if ( a>=97 && a<=122)
			b[ i ]=asc[97+25-(int)a]; 
		else if(a>=65 && a<=95)
			b[ i ]=asc[65+25-(int)a]; 
		i++;
		n++;
	} 
	for (i=0;i<n;i++) 
		printf("%c",b[ i ]); 
} 