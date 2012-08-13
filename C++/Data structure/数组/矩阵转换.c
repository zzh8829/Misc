void trans(int *p,int n)
{
	int i,j,temp;
	int *pi,*pj;
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=i;j++)
    		{
			pi =p +i*n;  /*pÊ×µØÖ· */
			pj =p +j*n;
			temp=pi[j];
			pi[j]=pj[i];
			pj[i]=temp;
    		}

	}
	return;
}

main()
{
	int a[4][4]={ 1, 2, 3, 4,
		      5, 6, 7, 8,
		      9, 10,11,12,
		      13,14,15,16};
	int i,j;
    	printf("before transform:\n");
    	for(i=0;i<=3;i++)
    	{
    		for(j=0;j<=3;j++)
    			printf("  %d",a[i][j]);
 		printf("\n");
      	}
    	trans((int*)a,4);
    	
    	printf("after transform:\n");
    	for(i=0;i<=3;i++)
      	{
      		for(j=0;j<=3;j++)
      			printf("  %d",a[i][j]);
  		printf("\n");
      	}
    	return;
}