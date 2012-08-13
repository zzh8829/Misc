#include<stdlib.h>
#include<stdio.h>
struct roommate
{
char name;
long num;
int age;
char birthplace;
struct roommate *next;
};
struct roommate *head,*cthis,*cnew;

void ins_record(void)
{
int i,j=0;
char numstr,b;
cthis=head;
printf("\nInput a num :");
scanf("%d",&i);
while(j<i-2)
  {
  cthis=(struct roommate*)malloc(sizeof (struct roommate));
  cthis=cthis->next;
  ++j;

  }
  if(j>i-1)
  return;
  cnew=(struct roommate*)malloc(sizeof (struct roommate));
 
  printf("\nplease input the information:");
  printf("\nenter name:");
  scanf("%s", &cnew->name);
 
  printf("\nenter number:");
  scanf("%ld",&cnew->num);
  printf("\nenter age:");
  scanf("%d",&cnew->age);
  printf("\nenter birthplace:");
  scanf("%s",&cnew->birthplace);
  cnew->next=cthis;

}
main()
{
ins_record();
}