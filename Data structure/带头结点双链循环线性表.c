#define  null  0
  typedef char data;
  typedef  Struct  dulistnode{
  DataType  data;
  Struct  dulistnode  *prior, *next;
}dulistnode
typedef Dulistnode  *Dulinklist;
 Status  InitList_DuL( DuLinkList L ) {
	 If  (!(p = GetElemP_DuL (L ) ))
	   Return  ERROR;					     
	 p->prior = p->next ;
	 p->next = p->prior ;
	 return OK;
} //InitList_DuL
Status  DestroyList_DuL ( DuLinkList &L ) {
		 while  ( L.front ) {
	    L.rear = L.front->next;
		Free  ( L.front );
		L.front = L.rear ;
	 }
	 return OK;
} // DestroyList_DuL
Status  ClearList_DuL ( DuLinkList &L ) {
	 L=Null;
} // ClearList_DuL
Status  ListEmpty_DuL ( DuLinkList L ) {
		 if  ( L.front = = L.rear ) return TRUE;
	 p = L.front->next ;
	 if  (L.rear = = p ) L.rear = L.front ;
	 free  ( p );
	 return FALSE;
} // ListEmpty_DuL
Status  ListLength_DuL ( DuLinkList L ) {
		 int  DuLinkListLength ( sqDuLinkList L ) {
	 return  ( L.rear - L.front + MAXLSIZE )%MAXLSIZE;
	 }
} // ListLength_DuL

Status  GetElem_DuL ( DuLinkList &L, int i, ElemType &e ) {
if  ( ! ( p = GetElemP_DuL ( L, i ) ) )			
	 return  ERROR;						
	 e = p->data;
     return OK
} // GetElem_DuL

Status  LocateElem_DuL ( DuLinkList L, ElemType e, Position &q, int (* compare )  ( ) ) {
} // LocateElem_DuL

Status  PriorElem_DuL ( DuLinkList L, int i, int j, ElemType cur_e, ElemType &pre_e ) {
	 if  ( ! ( p = GetEleP_DuL (L, i ) , 1<i<=length) )		
       return  ERROR;                          
if  ( !(q = GetElemP_DuL (L, j ) ) )		    
	 cyr_e = p->data;
	 pre_e = q->data;
     p->prior = q;
	 q->next = p;
	 return OK;
} // PriorElem_DuL
Status  NextElem_DuL ( DuLinkList L, int i, int j ElemType cur_e, ElemType &next_e ) {
	 if  ( ! ( p = GetEleP_DuL (L, i ) , 1<i<=length) )		return  ERROR;                          
if  ( !(q = GetElemP_DuL (L, j ) ) )		    
	 cyr_e = p->data;
	 next_e = q->data;
     p->next = q;
	 q->prior = p;
	 return OK;

} // NextElem_DuL

Starus  ListInsert_DuL ( DuLinkList &L, int i,ElemType e ) {
if  ( !(p = GetElemP_DuL (L, i ) ) )		
	   return  ERROR;				
	 if  (!(s = ( DuLinkList ) malloc ( sizeof ( DuLNode ) ) ) ) return ERROR;
	 s->data = e;
	 s->prior = p->prior; p->prior->next = s;
	 s->next = p;		  p->prior = s;
	 return OK;
} //ListInsert.DuL

Status  ListDelete_DuL ( DuLinkList &L, int I, ElemType &e ) {
	 if  ( ! ( p = GetElemP_DuL ( L, i ) ) )
	   return  ERROR;			
	 e = p->data;
	 p->prior->next = p->next;
	 p->next->prior = p->prior;
	 free ( p ); return OK;
} //ListDelete_DuL

Status  ListTraverse_DuL ( DuLinkList L, int i, visit ( ) ) {
} // ListTraverse_DuL
main( )
{struct  Lnode  *head, *q;  char  e, y;  int  i, n;  int  select, x1, x2, x3, x4, m, g;
head=setnull(&head);
printf("请输入数据长度:  ");
scanf("%d",  &n);
for(i=1; i<n; I++)
{printf("将数据插入到单链表中:  ");
 scanf("%d",  &y);
 insert(&head,  y,  i);
}
display(&head);
printf("select  1 求长度  length()\n");
printf("select  2 取结点  get()\n");
printf("select  3 求值查找 locate()\n");
printf("select  4 删除结点 delete()\n");
printf("input  your  select :  ");
scanf("%d",  &select);
 switch(select)
  { case  1 :{x1=length(&head);
           printf("输出单链表的长度:  ",  x1);
           display(&head);
          }
   case  2 :{printf("请输入要取的结点:  ");
           scanf("%d,  &m");
           x2=get(&head,   m);
           printf(x2);
          display(&head);
         }
   case  3 :{printf("请输入要查找的数据:   ");
           scanf("%d",  &e);
           x3=locate(&head,  e);
           printf(x3);
           display(&head);
          }
   case  4 :{printf("请输入要删除的结点:  ");
           scanf(%d,  &m);
           x4=delete(&head,  m);
           printf(x4);
           display(&head);
          }
}