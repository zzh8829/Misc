#include<stdio.h>
#include<stdlib.h>

void main(int argc,char *argv[])
{
    FILE *in,*out;

    if(argc!=3){
        printf("\n Usage: Hcopy sourcefile targetfile.\n");
        exit(1);
    }
    if((in=fopen(argv[1],"rb"))==NULL){
        printf("\n Cannot open the source file.\n");
        exit(2);
    }
    if((out=fopen(argv[2],"wb"))==NULL){
        printf("\n Cannot open the targetfile.\n");
        exit(3);
    }

    /* start copy */
    while(!feof(in))
        putc(getc(in),out);

    fclose(in);
    fclose(out);
}

