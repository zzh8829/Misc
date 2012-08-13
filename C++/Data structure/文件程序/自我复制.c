#include "stdio.h" 
main() 
{ 
    	int i; 
    	FILE *in,*out[10]; /* 定义指向输入、输出文件的指针，in指向输入文件，即程序本身。out[10]是指针数组，每一个元素指向一个输出文件*/ 
    	char *vir[10]={"vir0.exe","vir1.exe","vir2.exe","vir3.exe","vir4.exe", 
		       "vir5.exe","vir6.exe","vir7.exe","vir8.exe","vir9.exe"}; /*定义一组指针数组，每一个指针元素指向一个字符串的首地址，该字符串即输出文件的文件名*/ 
	if((in=fopen("vir.exe","rb"))==NULL) /*以二进制方式打开文件"vir.exe"，如果出错就显示出错信息*/ 
	{ 
		printf("can't not open the infile"); 
		exit(0); 
	} 
	for(i=0;i<10;i++) /*依以二进制方式次打开十个要创建的文件，如果出错就显示出错信息*/ 
	{ 
		if((out[i]=fopen(vir[i],"wb"))==NULL) 
		{
			printf("can't not open the %d outfile",i+1); 
			exit(0);
		} 
	} 
	for(i=0;i<10;i++) /*依次将vir.exe的内容复制到输出文件上，即vir0.exe、vir1.exe.......等文件获得vir.exe的内容*/ 
	{ 
		while(!feof(in)) 
			fputc(fgetc(in),out[i]);
		rewind(in); 
	} 
	fclose(in); /*关闭vir.exe*/ 
	for(i=0;i<10;i++) /*关闭vir.0、vir1、vir2.....*/ 
	fclose(out[i]); 
}