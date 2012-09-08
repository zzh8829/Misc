#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void usage(char * prog)
{
	printf("Usage: %s text pattern\n", prog);
	exit(123);
}
/*Algorithm~*/
void rk_sm(char * patt, char * text, int patt_length, int text_length, int c, int q)
{
	int p = 0, t = 0;
	unsigned long h = 1;
	int      i, k, s;
	int flag;         
	for(i = 0; i <= patt_length -1; i ++)
	h *= c;         
	h = h % q;         
	for(i = 0; i < patt_length; i ++)
	{
		p = (c * p + patt[i])%q;            //得到匹配字符串的HASH值
		t = (c * t + text[i])%q;               //得到text字符串的前patt_length个字符串的HASH值
	}         
	for(s = 0; s < text_length - patt_length + 1; s ++)
	{
		if(p == t)
		{
			flag = 1;
			for(i = 0; i < patt_length; i ++)
			if(patt[i] != text[s+i])
			flag = 0; //set flag, not match...                         if(flag)
			{
				printf("position %d\n", s);
				printf("text: %s\n", text);
				printf("patn: ");
				for(k = 1; k <= s; k ++)
				printf(" ");
				printf("%s\n", patt);
				return;
			}
		}
		if(s < text_length - patt_length)
		t = (c * (t - text[s]* h) + text[s + patt_length])%q;
	}         
	printf("Not match!\n");
}
int main(int argc, char * argv[])
{
	char * text = NULL;
	char * pattern = NULL;         
	if(argc != 3)
	usage(argv[0]);
	else
	{
		text = argv[1];
		pattern = argv[2];
	}
	printf("text: %s\n", text);
	printf("patn: %s\n", pattern);         
	rk_sm(pattern, text, strlen(pattern), strlen(text), 26, 13);    
	//hash函数的素数值可以通过一定的方法进行改变
	return 1;
}