#define MAXSTRLEN 255  
typedef unsigned char sstring[MAXSTRLEN+1] 

struct sstring
{
	char *ch;
  	int length;
}

strassign(struct sstring *T,char *chars) 
{
	int nlenth;
  	nlenth=strlen(chars);
  	T->length=nlenth;
  	T->ch=(char *)malloc(nlenth*sizeof(char)+1);
  	if(!T->ch)
  	{
      		T->length=0;
      		exit(overflow);
      	}
    	else
    	{
		strcpy(T->ch,chars);
	 	return 0;	
	}
}//strassign


  int strlength(struct sstring *S)   
  {  
     S->length=strlen(S);
     return S->ch;
     }//strlength






int strcompare(struct sstring *S,struct sstring *T)   
 {
   if S>MAXSTRLEN && T>MAXSTRLEN  exit(overflow);
   if (strcmp(S->ch,T->ch)==0) return 0;
   else if(strcmp(S->ch,T->ch)>0) return 1;
   else return -1;
 }//strcompare




 int clearstring(struct sstring *S)   
 {
   if (S->ch){
	  free (S->ch);
	  S->ch=NULL;
	  S->length=0;
	  }
	  return 0;
   }//clearstring




   int concat(struct sstring *T,struct sstring *s1,struct sstring *s2) 
  {   
        if(s1[0]+s2[0]<=MAXSTRLEN)
      {                         
        strcpy(T->ch,s1->ch);
        strcpy(T->ch,s2->ch);
        T[0]=S1[0]+S2[0];
        uncat=TRUE;
       }
        else if (s1[0]<MAXSTRLEN)
       {                      
         strcpy(T->ch,s1->ch);
         strcpy(T->ch,s2->ch);
         T[0]=MAXSTRLEN;
         uncat=FALSE;
       }
        else{
         T->ch=s1->length     
         uncat=FALSE;
             }
         return uncat;
     }//concat




 int substring(struct sstring *sub,struct sstring *S,int pos,int len)
   {                              
    char *p;int i;
    if(pos<1 || pos>S[0] || len<0 || len>S[0]-pos+1)
       return -1;
    else{
	sub->ch=(char*) malloc(len *sizeof(char)+1);
	p=S->ch;
	for(i=0;i<=pos-1;i++)
	p++;
	}
     strcpy(sub->ch,p);

     return 0;
  }//substring




  main( )
  {
    char inp;
    char *T[255];
    char *S[255];
    struct sstring *s1,*s2,*res;
    int pos,len;
    printf("1-------strassing\n");
    printf("2-------strlength\n");
    printf("3-------strcompare\n");
    printf("4-------clearstring\n");
    printf("5-------concat\n");
    printf("6-------substring\n");
    printf("*-------exit!");
    printf("please in put1--6 or *\n\n")
 while(1){
      scanf("%c",&inp);
      switch(inp){
	      case 1:{
		    scanf("%s",&S);
		    res->ch=strassign(s1,S);
		    if(res->ch==0)
			printf("the string is:%s",s1->ch);
		    else
		       printf("error"); }
	      case 2: {
		    scanf("%s",&S);
		    s1->length=strlen(S);
		    strcpy(s1->ch,S);
		    res->ch=strlength(S);
		    printf("the string is:%d\n",s1->length);}
	      case 3:{
		    scanf("%s",&S);
		    scanf("%s",&T);
		    s1->length=strlen(S);
		    strcpy(s1->ch,S);
		    s2->length=strlen(T);
		    strcpy(s2->ch,T);
		    res->ch=strcompare(S,T);
		    switch(res){
		       case 0:
			    printf("two strings are equle");
		       case 1:
			    printf("the first string > the second string");
		       case -1:
			    printf("the first string < the second string");}
                       }
	     case 4:{
		    res->ch=clearstring(s1);
		    res->ch=clearstring(s2);
		    printf("the string is NULL");}
	     case 5:{
		    scanf("%s",&S);
		    scanf("%s",&T);
		    strcat(&s1,S,T);
		    if(res==0)
		      printf("the string is:%s",s1->ch);
		    }
	     case 6: {
		    scanf("%s_%d_%d",S,&pos,&len);
		    s2->length=strlen(S);
		    strcpy(s2->ch,S);
		    res->ch=substring(s1,s2,pos,len);
		    if(res==0)
			printf("the string is:%s",s1->ch);
		    else printf("error");}
	     case *:
		    exit;
       }
      }
    }










