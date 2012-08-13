#define NULL 0
struct sstring{
  char *ch;
  int length;
  }




strassign(struct sstring *T,char *chars)
  {int nlenth;
  nlenth=strlen(chars);
  T->length=nlenth;
  T->ch=(char *)malloc(nlenth*sizeof(char)+1);
  if(!T->ch){
      T->length=0;
      return ;
      }
    else{
	 strcpy(T->ch,chars);
	 return ;
	 }
  }




  int strlength(struct sstring *T)
  {  int *S;
     return (S->length);
   }






int strcompare(struct sstring *S,struct sstring *T)
 {if (strcmp(S->ch,T->ch)==0) return 0;
 else if(strcmp(S->ch,T->ch)>0) return 1;
 else  return -1;
 }




 int clearstring(struct sstring *S)
 {
   if (S->ch){
	  free (S->ch);
	  S->ch=NULL;
	  S->length=0;
	  }
	  return 0;
   }




   int concat(struct sstring *T,struct sstring *s1,struct sstring *s2)
  {
     if(T->ch) free(T->ch);
     if(!(T->ch=(char*)malloc((s1->length+s2->length)*sizeof(char))));
     return;
     T->length=s1->length+s2->length;
     strcpy(T->ch,s1->ch);
     strcpy(T->ch,s2->ch);
     return 0;
     }




 int substring(struct sstring *sub,struct sstring *S,int pos,int len)
 {
    char *p;int i;
    if(pos<1 || pos>S->length || len<0 || len>S->length-pos+1)
    return -1;
    if(!len){
    sub->ch=NULL;
    sub->length=0;
    }
    else{
	sub->ch=(char*) malloc(len *sizeof(char)+1);
	p=S->ch;
	for(i=0;i<=pos-1;i++)
	p++;
	}
     strcpy(sub->ch,p);
     return 0;
  }



  main( )
  {
    char inp;
    char *T,*S,*res;
    struct sstring *s1,*s2;
    int pos,len;
    printf("1-------strassing\n");
    printf("2-------strlength\n");
    printf("3-------strcompare\n");
    printf("4-------clearstring\n");
    printf("5-------concat\n");
    printf("6-------substring\n");
    printf("*-------exit");
    printf("please in put 1--6 or *\n\n");
 while(1){
      scanf("%c",&inp);
      switch(inp){
	      case 1:{
		    scanf("%s",&S);
		    res->ch=strassign(s1,S);
		    if(res->ch==0)
			printf("the string is%s",s1->ch);
		    else
		       printf("error"); }
	      case 2: {
		    scanf("%s",&S);
		    s1->length=strlen(S);
		    strcpy(s1->ch,S);
		    res->ch=strlength(S);
		    printf("the length is%d\n",s1->length);}
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
	     case 5:
		   { scanf("%s",&S);
		    scanf("%s",&T);
		    strcat(&s1,S,T);
		    if(res==0)
		      printf("the string is:%s",s1->ch);
		    }
	     case 6: {
		    scanf("%s_%d_%d",S,&pos,&len);
		    s2->length=strlen(S);
		    strcpy(s2->ch,S);
		    res->ch==substring(&s1,&s2,pos,len);
		    if(res==0)
			printf("the string is:%s",s1->ch);
		    else printf("error");}
	     case *:
		    exit;
       }
      }
    }










