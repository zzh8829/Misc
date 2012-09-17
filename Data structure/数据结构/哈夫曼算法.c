#include<stdio.h> 
#include<malloc.h> 
#include<conio.h> 
#include<stdlib.h> 
#include<string.h> 

/*声明两种链表结构----start*/ 
struct node_a{  /*链表1-----作用：用来统计文件中字符的个数和种类（通过count）*/ 
 char data; 
 int count; 
 struct node_a *next; 
 }; 
typedef struct node_a node,*list; 
list head=NULL; 

struct nodeb{  /*链表2-----作用：用来建立用相应的编码代替字符的新文件*/ 
 char data; 
 struct nodeb *next; 
}; 
typedef struct nodeb node_b,*list_b;  /*jiang bianma xieru wenjian*/ 
list_b head_b=NULL; 
/*声明两种链表结构----end*/ 

/*哈夫曼算法种相关的3种结构的声明-----start*/ 
struct forest{   
 float weight; 
 int root; 
 }; 
struct alphabet{ 
 char symbol; 
 float probability; 
 int leaf; 
 char *bianma;       
 }; 
struct tree{ 
 int lchild; 
 int rchild; 
 int parent; 
 }; 
typedef struct tree *tree_ptr,tree_node; 
typedef struct forest *forest_ptr,forest_node; 
typedef struct alphabet *alphabet_ptr,alphabet_node; 
tree_ptr tree1; 
forest_ptr forest1; 
alphabet_ptr alphabet1; 
int lasttree,lastnode; 
int least,second; 
/*哈夫曼算法种相关的3种结构的声明-----end*/ 

/**************stack difination start****************/ 
struct stacknode{ 
  char *bian_ma; 
  struct stacknode *next; 
  }; 
typedef struct stacknode stack_node; 
typedef stack_node *link; 
link top=NULL; 

void push(char *item){ 
 link p; 
 if(top!=NULL){ 
   p=(link)malloc(sizeof(stack_node)); 
   if(p==NULL){ 
    printf("Memory allocation error!"); 
    return; 
    } 
   p->bian_ma=item; 
   p->next=top; 
   top=p; 
  } 
  else{ 
    top=(link)malloc(sizeof(stack_node)); 
    if(!top){ 
     printf("Memory allocation error!"); 
     return; 
     } 
    top->bian_ma=item; 
    top->next=NULL; 
  } 
 } 

void pop(void){ 
  link p; 
  p=top; 
  top=top->next; 
  free(p); 
 } 

void makenull(void){ 
  while(top!=NULL) 
   pop(); 
} 

int empty(){ 
  if(top==NULL) 
  return 1; 
  else 
  return 0; 
  } 

char* tops(void){ 
   return (top->bian_ma); 
} 

void display_stack(link s){ /*显示栈重的内容*/ 
 link ptr; 
 ptr=s; 
 while(ptr!=NULL){ 
  printf("%s",ptr->bian_ma); 
  ptr=ptr->next; 
  } 
 } 

  /***************************stack__difination is end************************/ 
void display(list h){ /*显示链表1*/ 
list ptr; 
int i=1; 
ptr=h->next; 
while(ptr!=NULL){ 
 printf("%d,%c,%d\n",i,ptr->data,ptr->count); 
 i++; 
 ptr=ptr->next; 
 } 
} 
void display_b(list_b h){  /*显示链表2*/ 
list_b ptr; 
int i=1; 
ptr=h->next; 
while(ptr!=NULL){ 
 printf("%d,%c\n",i,ptr->data); 
 i++; 
 ptr=ptr->next; 
 } 
} 

void insert(char item){  /*用于插入元素以建立链表1*/ 
 list temp,ptr; 
 int flag; 
 ptr=head->next; 
 if(ptr==NULL){ 
head->next=(list)malloc(sizeof(node)); 
   head->next->data=item; 
   head->next->count=1; 
   head->next->next=NULL; 
   } 
 else{ 
    while(ptr!=NULL){ 
     if(ptr->data==item){ 
     ptr->count=ptr->count+1; 
     flag=1; 
     } 
    ptr=ptr->next; 
        } 
   ptr=head; 
   if(flag==1) 
     return; 
   else{ 
     temp=ptr->next; 
     ptr->next=(list)malloc(sizeof(node)); 
     ptr->next->data=item; 
     ptr->next->count=1; 
     ptr->next->next=temp; 
   } 
 } 
} 

void insert_b(char item){  /*插入元素以建立链表2*/ 
  list_b ptr_b, temp_b; 
  ptr_b=head_b; 
  if(ptr_b->next==NULL){ 
    head_b->next=(list_b)malloc(sizeof(node_b)); 
    head_b->next->data=item; 
    head_b->next->next=NULL; 
    } 
  else{ 
    while(ptr_b->next!=NULL){ 
  ptr_b=ptr_b->next; 
  } 
    ptr_b->next=(list_b)malloc(sizeof(node_b)); 
    ptr_b->next->data=item; 
    ptr_b->next->next=NULL; 
    } 
} 

void search(void){ /*搜索文件并将文件中的数据分别存入作用不同的链表中*/ 
 FILE *fp; 
 list ptr; 
 char ch; 
 if((fp=fopen("test.txt","r"))==NULL) 
   printf("Reading error!\n"); 
 while(!feof(fp)){ 
   ch=getc(fp); 
   if(ferror(fp)){ 
     printf("error!\n"); 
     break; 
     } 
   if(ch==EOF) 
    break; 
   insert(ch);   /*插入元素进链表1*/ 
   insert_b(ch); /*插入元素进链表2*/ 
   } 
 printf("\n"); 
 fclose(fp); 
} 

void display_struct(int n){ /*显示哈夫曼算法中的3个结构树组 */ 
int i=0; 
printf("\n\n=======================================\n\n"); 
printf("FOREST_STRUCT_ARRY :\n\n\n"); 
for(i=0;i<=n;i++){ 
printf("%f,%d\n",forest1[i].weight,forest1[i].root); 
} 
getch(); 
printf("\n\nALPHABET_STRUCT_ARRY :\n\n\n"); 
for(i=0;i<=n;i++){ 
 printf("%f,%d,%c\n",alphabet1[i].probability,alphabet1[i].leaf,alphabet1[i].symbol); 
} 
getch(); 
printf("\n\nTREE_STRUCT_ARRY :\n\n\n"); 
for(i=0;i<=2*n-1;i++) 
printf("%d,%d,%d\n",tree1[i].lchild,tree1[i].rchild,tree1[i].parent); 
printf("\n\n======================================\n\n"); 
getch(); 
} 

int init_struct(void){  /*初始化哈夫曼算法中3种结构数组*/ 
list ptr; 
float count=.0; 
int i=1,n=0; 
ptr=head->next; 
while(ptr!=NULL){ 
 count=ptr->count+count; 
 n++; 
 ptr=ptr->next; 
 } 
ptr=head->next; 
forest1=(forest_ptr)malloc(sizeof(forest_node)*n+sizeof(forest_node)); 
alphabet1=(alphabet_ptr)malloc(sizeof(alphabet_node)*n+sizeof(alphabet_node)); 
tree1=(tree_ptr)malloc(sizeof(tree_node)*n*2-sizeof(tree_node)); 
forest1[0].weight=alphabet1[0].probability=0.0; 
forest1[0].root=alphabet1[0].leaf=0; 
alphabet1[0].symbol='0'; 
while(ptr!=NULL){ 
 forest1[i].weight=alphabet1[i].probability=ptr->count/count; 
 forest1[i].root=alphabet1[i].leaf=i; 
 alphabet1[i].symbol=ptr->data; 
 i++; 
 ptr=ptr->next; 
} 
for(i=0;i<=2*n-1;i++){ 
 tree1[i].lchild=0; 
 tree1[i].rchild=0; 
 tree1[i].parent=0; 
 } 
return n; 
} 

void creat(void){      /*创建正文文件test.txt*/ 
 FILE *fp,*out; 
 char ch; 
 if((fp=fopen("test.txt","r++"))==NULL) 
   printf("Creat error!\n"); 
 printf("Input the data:\n"); 
 ch=getch(); 
 putch(ch); 
 while(ch!='#'){ 
   putc(ch,fp); 
   ch=getch(); 
   putch(ch); 
   } 
   fclose(fp); 
 } 

void creat_bianma(int number){  /*根据哈夫曼算法建立文件中各种字符对应的编码*/ 
 int i,j,n; 
 int p; 
 char *bm=malloc(sizeof(char)*number); 
 for(n=1;n<=number;n++){ 
    j=i=n; 
    makenull(); 
    p=tree1[i].parent; 
    while(tree1[p].parent!=0){ 
if(tree1[p].lchild==i) 
     push("0"); 
 else 
     push("1"); 
i=p; 
p=tree1[p].parent; 
      } 

    if(tree1[p].lchild==i) 
 push("0"); 
    else 
 push("1"); 
    strcpy(bm," "); /*目的：使创建编码文件中的各编码中间存在间隔*/ 
    while(!empty()){ 
strcat(bm,tops()); 
pop(); 
} 
     alphabet1[j].bianma=malloc(sizeof(char)*number); 
     strcpy(alphabet1[j].bianma,bm); 
     printf("\n%c:%s",alphabet1[j].symbol,alphabet1[j].bianma); /*打印出相应的编码*/ 
     getch(); 
    } 
 } 


void write_new_file(int number){ /*根据相应的编码重新建立编码文件*/ 
  FILE *fp; 
  list_b ptr; 
  int i; 
  char *ch=malloc(sizeof(char)*number); 
  ptr=head_b->next; 
  if((fp=fopen("bianma.txt","w"))==NULL) 
    printf("Write in a new file error!"); 
  else{ 
    while(ptr!=NULL){ 
      for(i=1;i<=number;i++){ 
if(ptr->data==alphabet1[i].symbol){ 
   strcpy(ch,alphabet1[i].bianma); 
   fputs(ch,fp); 
   } 
} 
      ptr=ptr->next; 
    } 
  } 
  fclose(fp); 
} 


void main(void){ 
int i,num; 
char ch; 
void huffman(void); 
void lightones(); 
head=(list)malloc(sizeof(node)); 
head->next=NULL; 
head->data='\0'; 
head->count=0; 
head_b=(list_b)malloc(sizeof(node_b)); 
head_b->data='\0'; 
head_b->next=NULL; 
do{ 
  system("cls"); 
  creat(); 
  search(); 
  printf("\nlianbiao1:\n"); 
  display(head);/*显示链表1*/ 
  getch(); 
  printf("\nlianbiao2:\n"); 
  display_b(head_b); 
  getch(); 
  num=init_struct(); 
  printf("\n"); 
  printf("The 3 init_struct of huffman?\n"); 
  display_struct(num);/*显示初始化的哈夫曼书的相关3个结构数组*/ 
  lastnode=num; 
  lasttree=num; 
  huffman(); 
  printf("Now the 3 struct through huffman shuanfa\n"); 
  display_struct(num);/*显示哈夫曼树中相关的3种结构（经过哈夫曼算法处理）*/ 
  printf("\nThe bian_ma is:\n"); 
  creat_bianma(num); 
  write_new_file(num); 
  printf("\nDo you want to re_try(y/n)?"); 
  ch=getchar(); 
  }while(ch=='y'); 
  } 

/*哈夫曼算法-----defination_start*/ 
void lightones(void){ 
 int i; 
 if(forest1[1].weight<=forest1[2].weight){ 
    least=1; 
    second=2; 
    } 
 else{ 
    least=2; 
    second=1; 
    } 
 for(i=3;i<=lasttree;i++) 
   if(forest1[i].weight<forest1[least].weight){ 
second=least; 
least=i; 
} 
   else 
if(forest1[i].weight<forest1[second].weight) 
 second=i; 
} 

int creat_tree(int lefttree,int righttree){ 
  lastnode=lastnode+1; 
  tree1[lastnode].lchild=forest1[lefttree].root; 
  tree1[lastnode].rchild=forest1[righttree].root; 
  tree1[lastnode].parent=0; 
  tree1[forest1[lefttree].root].parent=lastnode; 
  tree1[forest1[righttree].root].parent=lastnode; 
  return(lastnode); 
} 

void huffman(void){ 
  int i,j; 
  int newroot; 
  while(lasttree>1){ 
    lightones(); 
    i=least; 
    j=second; 
    newroot=creat_tree(i,j); 
    forest1[i].weight=forest1[i].weight+forest1[j].weight; 
    forest1[i].root=newroot; 
    forest1[j]=forest1[lasttree]; 
    lasttree=lasttree-1; 
    } 
} 