#include<stdlib.h>
#include<stdio.h>
struct roommate
{
  char name[20];
  long num;
  int age;
  char birthplace[20];
  struct roommate *next;
};
struct roommate *head,*cthis,*cnew;

void new_record(void)
{
  char ch;
  char numstr[20];
do
{
  cnew=(struct roommate*)malloc(sizeof(struct roommate));
  if(head==NULL)
    head=cnew;
  else
  {
    cthis=head;
    while(cthis->next!=NULL)
      cthis=cthis->next;
    cthis->next=cnew;
  }
cthis=cnew;

printf("\nenter name:");
gets(cthis->name);
printf("\nenter number:");
gets(numstr);
cthis->num=atol(numstr);
printf("\nenter age:");
gets(numstr);
cthis->age=atoi(numstr);
printf("\nenter birthplace:");
gets(cthis->birthplace);
cthis->next=NULL;
printf("\nprint 'e' to add record:");
ch=getchar();getchar();
}while(ch=='e');

cthis->next=head;

}
void listall(void)
{int i=0;
  cthis=head;
  do{
  printf("\nrecord number %d\n",i);
  printf("name:%s\n",cthis->name);
          printf("num:%ld\n",cthis->num);
  printf("age:%d\n",cthis->age);
  printf("birthplace:%s\n",cthis->birthplace);
  cthis=cthis->next;
  }while(cthis!=head);
}

void main()
{
char ch;
int flag=1;
head=NULL;

while(flag)
{
        
printf("\ntype 'e' to enter new record,");
printf("type 'l' to list all records,");
printf("type 'i' to insert  a  record:");
        ch=getchar();getchar();
        switch(ch)
{

case'e':new_record();break;
case'l':listall();break;
        default:flag=0;
}
}
}