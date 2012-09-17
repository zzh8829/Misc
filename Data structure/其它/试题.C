#define N sizeof tbl/sizeof tbl[0]  /*取得数组有多少个元素*/

int A,B,C,D,E,F;

struct ele
  {
   char vn;
   int *vp;
  }tbl[]={{'A',&A},{'B',&B},{'C',&C},
	  {'D',&D},{'E',&E},{'F',&F}},t;

main()
{
  int k,j,m;
  for(k=0;k<N;k++)
    {
      printf("Enter data for %c\n",tbl[k].vn);
      scanf("%d",tbl[k].vp);
    }
  m=N-1;
  while(m>0)
    {
      for(k=j=0;j<m;j++)
	if(*tbl[j].vp<*tbl[j+1].vp)
	  {
	    t=tbl[j];
	    tbl[j]=tbl[j+1];
	    tbl[j+1]=t;
	    k=j;
	  }
	m=k;
    }
  for(k=0;k<N;k++)
    printf("%c(%d)",tbl[k].vn,*tbl[k].vp);
  printf("\n");
  getch();
}
