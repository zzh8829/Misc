/****************fcat.c***************/

#include<stdio.h>
#include<stdlib.h>
#define BUFSIZE 256

void main(int argc,char *argv[])
{
    int i;
    char buff[BUFSIZE];
    FILE *fp1,*fp2;

    if(argc==1){
        printf("Rsage: fcat filename linke_fname[link_fname...].");
        printf("\n");
        exit(1);
    }
    if((fp1=fopen (argv[1],"a"))==NULL){
        printf("file %s cannot opened.\n",argv[1]);
        exit(1);
    }
    for(i=2;i<argc;i++){
        if((fp2=fopen(argv[i],"r"))==NULL){
            printf("file %s cannot opened.\n");
            exit(1);
        }
        while(fgets(buff,BUFSIZE,fp2)!=NULL)
            fputs(buff,fp1);
        fclose(fp2);
    }
    fclose(fp1);
}
