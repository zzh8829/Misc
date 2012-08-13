 # define maxsize 50

 struct sqlist
 { 
 	int sqlist[maxsize];
     	int key;
     	int size;
     	int data;
 };

 setnull(struct sqlist *p)  /*装入表*/
 {
 	p->size=0;
 }
 
 int length(struct sqlist *p)  /*表长度*/
 {
  	return(p->size);
 }
 
 get(struct sqlist *p,int i)  /*取得一个元素*/
 {
    	if (i<1 && i>p->size) 
    		printf("错误");
      	else 
      		printf("该序号对应的元素为：%d",p->sqlist[i]);
 }
 
 locate(struct sqlist *p,int x)  /*查找元素*/
 {  
 	int i=0;
    	while (i<p->size && p->sqlist[i]!=x) 
    		i++;
    		
      	if (i==p->size )
      		printf("错误");
	else printf("该元素第一次出现的位置：%d",i);
 }
 
 insert(struct sqlist *p,int i,int x)
 {
 	int j;
     	if (i<1 && i>p->size+1)
		printf("位置不正确不能行插入\n");
 	else
  	{
		p->size++;
		for (j=p->size-1;j>=i;j--)
			p->sqlist[j]=p->sqlist[j-1];
		p->sqlist[j]=x;
  	}
 	for(j=1;j<p->size;j++)
 		printf("线性表为:%d->",p->sqlist[j]);
 }
 
 void delete(struct sqlist *p,int i)
 {
 	int j;
 	if (i<1 || i>p->size)
		printf("错误");
 	else
	{
 		for (j=i;j<p->size;j++)
			p->sqlist[j]=p->sqlist[j+1];
		p->size--;
 	}
 	printf("此线性表为：");
   	for (i=1;i<=p->size;i++)
		printf("%d->",p->sqlist[i]);
 }

 insertsort(struct sqlist *p,int n)
 {
 	int i,j;
	for(i=2;i<=n;i++)
	{
		p->sqlist[0]=p->sqlist[i];
		j=i-1;
		while(j>0 && p->sqlist[0]<p->sqlist[j])
		{
			p->sqlist[j+1]=p->sqlist[j]; j--;}
 			p->sqlist[j+1]=p->sqlis	t[0];
		}
		printf("shen xu;\n");
		for (i=1;i<=n;i++)
			printf("%d",p->sqlist[i]);
		printf("\n");
		for(i=1;i<=n;i++)
			printf("%d",p->sqlist[i]);
		printf("\n");
	}
}

display(struct sqlist *p)
{
	int j;
	if (p->size==0)
		printf("此表为空无法显示！");
	else 
		printf("the list");
	if (p->size==1)
		printf("%d",p->sqlist[p->size]);
 	else
 	{
 		for(j=1;j<p->size;j++)
 			printf("%d->",p->sqlist[j]);
		printf("%d",p->sqlist[j]);

 	}
}

main()
{
	int i,select,a,j;int w;
	struct sqlist *p;
	struct sqlist l;
	setnull(&l);
	printf("请输入数据：\n");
 	p=&l ;
  	p->size=0;
  	for (i=1;i<5; i++)
     	{
     		scanf("%d",&l.sqlist[i]);
     		p->size++;
     	}
	printf("\n");
	printf("1:置空表！ \n");
  	printf("2:求长度！ \n");
  	printf("3:读取元素！ \n");
  	printf("4:定位查找！ \n");
  	printf("5:插入！ \n");
  	printf("6:删除！ \n");
  	printf("7:排序！ \n");
  	printf("8:显示！ \n");

  	printf("请选择（1----8） \n");
  	scanf("%d",&select);
  	switch(select)
	{
		case 1:
			setnull(&l);break;
		case 2:
			printf("chang du %d",length(&l));
			break;
		case 3:
			printf("输入序号:");
			scanf("%d",&i);
			get(&l,i);
			break;
		case 4:
			printf("输入元素:");
			scanf("%d",&i);
			locate (&l,i);
			break;
		case 5:
			printf("输入插入的元素及位置：");
			scanf("%d,%d",&i,&j);
     			insert(&l,i,j);
     			break;
		case 6:
			printf("输入所要删除数据的位置:");
       			scanf("%d",&w);
       			delete(&l,w);    
       			break;
		case 7:
			insertsort(&l,4);
			break;
		case 8:
			display(&l);  
			break;
  	}
}