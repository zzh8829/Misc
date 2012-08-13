#include <stdio.h>
#include <stdlib.h>

main()
{
    FILE *in,*out;
    char ch,infile[10],outfile[10];
    printf("Enter the infile nmae:\n");
    scanf("%s",infile);
    printf("Enter the outfile name:\n");
    scanf("%s",outfile);
    
    if( (in=fopen(infile,"r") )==NULL)
    {
    	printf("cannot open infile\n");
    	exit(0);
    }
    if( (out=fopen(outfile,"w") )==NULL)
    {
    	printf("cannot open outfile\n");
    	exit(0);
    }
    
    while( ! feof(in) )  fputc(fgetc(in),out);
    
    fclose(in);
    fclose(out);
}

    
}
