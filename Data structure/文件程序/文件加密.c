给文件加密的技术很多,其中又分为不同等级,以适合不同场合的需要.这里给出最简单的文件加密技术,即采用文件逐字节与密码异或方式对文件进行加密,当解密时,只需再运行一遍加密程序即可.

下面是一个实例程序,能对任意一个文件进行加密,密码要求用户输入,限8位以内(当然你可以再更改).程序有很好的容错设计,这是我们应该学习的.

/* Turbo 2.0 pass. give file a password! */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void dofile(char *in_fname,char *pwd,char *out_fname);/*对文件进行加密的具体函数*/

void main(int argc,char *argv[])/*定义main()函数的命令行参数*/
{
    char in_fname[30];/*用户输入的要加密的文件名*/
    char out_fname[30];
    char pwd[8];/*用来保存密码*/

    if(argc!=4){/*容错处理*/
    printf("\nIn-fname:\n");
    gets(in_fname);/*得到要加密的文件名*/

    printf("Password:\n");
    gets(pwd);/*得到密码*/

        printf("Out-file:\n");
        gets(out_fname);/*得到加密后你要的文件名*/
        

dofile(in_fname,pwd,out_fname);
      }
    else{/*如果命令行参数正确,便直接运行程序*/
        strcpy(in_fname,argv[1]);
        strcpy(pwd,argv[2]);
        strcpy(out_fname,argv[3]);
        dofile(in_fname,pwd,out_fname);
    }

}


/*加密子函数开始*/
void dofile(char *in_fname,char *pwd,char *out_file)
{
    FILE *fp1,*fp2;
    register char ch;
    int j=0;
    int j0=0;

    fp1=fopen(in_fname,"rb");
    if(fp1==NULL){
    printf("cannot open in-file.\n");
    exit(1);/*如果不能打开要加密的文件,便退出程序*/
    }
    fp2=fopen(out_file,"wb");
    if(fp2==NULL){
    printf("cannot open or create out-file.\n");
    exit(1);/*如果不能建立加密后的文件,便退出*/
    }
    while(pwd[++j0]);
    ch=fgetc(fp1);

/*加密算法开始*/
    while(!feof(fp1)){
    fputc(ch^pwd[j>=j0?j=0:j++],fp2);/*异或后写入fp2文件*/
    ch=fgetc(fp1);
    }
    fclose(fp1);/*关闭源文件*/
    fclose(fp2);/*关闭目标文件*/
}

/*程序结束*/
