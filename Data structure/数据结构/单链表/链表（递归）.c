#include 
#include 

struct listNode{ 
int data; 
struct listNode *nextPtr; 
}; 

typedef struct listNode LISTNODE; 
typedef LISTNODE * LISTNODEPTR; 

LISTNODEPTR list(LISTNODEPTR , int); // 此处不同 
void printlist(LISTNODEPTR); 
void freelist(LISTNODEPTR); // 增加 

main() 
{ 
LISTNODEPTR newPtr=NULL; 

int i,a; 
for(i=0;i<3;i++){ 
printf("please enter a number\n"); 
scanf("%d,",&a); 
newPtr = list(newPtr,a); // 此处注意 
} 

printlist(newPtr); 

freelist(newPtr); // 此处 

return 0; 
} 

LISTNODEPTR list(LISTNODEPTR sPtr, int a) 
{ 
if ( sPtr != NULL ) 
sPtr->nextPtr = list( sPtr->nextPtr, a ); // 递归，向后面的节点上加 
数 
据。 
else 
{ 
sPtr =(LISTNODEPTR) malloc(sizeof(LISTNODE)); // 注意，是节点的 
尺寸, 
类型转换 
sPtr->nextPtr = NULL; 
sPtr->data = a; 
} 
return sPtr; 
} 

void freelist(LISTNODEPTR sPtr ) 
{ 
if ( sPtr != NULL ) 
{ 
freelist( sPtr->nextPtr ); // 递归， 先释放后面的节点 
free( sPtr ); // 再释放本节点 
} 
else // 
return ; // 此两行可不要 
} 



void printlist(LISTNODEPTR currentPtr) 
{ 
if(currentPtr==NULL) 
printf("The list is empty\n"); 
else 
{ 
printf("This list is :\n"); 

while(currentPtr!=NULL) 
{ 
printf("%d-->",currentPtr->data); 
currentPtr=currentPtr->nextPtr; // 这里不一样 
} 
printf("NULL\n\n"); 
} 
} 


你原程序错误如下：------------------------- 

> list1.c 
> 
>#include 
>#include 
> 
>struct listNode{ 
> int data; 
> struct listNode *nextPtr; 
>}; 
> 
>typedef struct listNode LISTNODE; 
>typedef LISTNODE * LISTNODEPTR; 
> 
>void list(LISTNODEPTR *, int); 
>void printlist(LISTNODEPTR); 
> 
>main() 
>{ 
> LISTNODEPTR newPtr=NULL; 
> 
> 
> int i,a; 
> for(i=0;i<3;i++){ 
> printf("please enter a number\n"); 
> scanf("%d,",&a); 
> list(&newPtr,a); 
// 此处给的是newPtr的地址， 注意！ 

> } 
> 
> printlist(newPtr); 
> 
> free(newPtr); 
// 链表的释放不能这样写，这样，只释放了newPtr指向的一个节点。 
// 可以先找到链表的尾，然后反向释放；或者，利用 printlist的顺序释放， 

// 改函数printlist，或在此函数里释放。 

> 
> return 0; 
>} 
> 
>void list(LISTNODEPTR *sPtr, int a) 
>{ 
> LISTNODEPTR newPtr,currentPtr; 
> 
> newPtr=malloc(sizeof(LISTNODEPTR)); 
// 此处错， LISTNODEPTR 是指针类型，不是结构类型， 
// malloc返回void指针，应该强制转换类型，此处会告警不报错，但应有良好 
的 
// 编程风格与习惯。 
> if(newPtr!=NULL){ 
> newPtr->data=a; 
> newPtr->nextPtr=NULL; 
> 
> currentPtr=*sPtr; 
> } 
> if(currentPtr==NULL){ 
// 此处条件不确切，因为currentPtr没有初始化， 
// 如newPtr一旦为NULL，此句及以下就有问题。 

> newPtr->nextPtr=*sPtr; 
> *sPtr=newPtr;} 
// 在第一个数来的时候，main里的newPtr通过sPtr被修改指向此节点。 
// 在第二个数来的时候，main里的newPtr通过sPtr被修改指向此节点。 
// 在第三个数来的时候，main里的newPtr通过sPtr被修改指向此节点。 
// 最后，main里的newPtr指向第三个数。 
>} 
> 
> 
> 
>void printlist(LISTNODEPTR currentPtr) 
>{ 
> if(currentPtr==NULL) 
> printf("The list is empty\n"); 
> else{ 
> printf("This list is :\n"); 
> 
> while(currentPtr!=NULL){ 
> printf("%d-->",currentPtr->data); 

// main里的newPtr指向第三个数。你先打印了最后一个数。RE第二个问题 

> currentPtr=currentPtr->nextPtr->data; 
// 此句非法， 类型不同， 有可能让你只循环一次，如data为0。RE第一个问 
题 

> } 
> printf("NULL\n\n"); 
> } 
>} 
// 对类似程序能运行，但结果似是而非的情况，应该多利用跟踪调试，看变量的 
变 
化。 





