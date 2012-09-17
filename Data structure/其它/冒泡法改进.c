/*   冒泡法是数据排序的一种基本算法,它的基本方法是:相邻两元素进行比较,如有需要则进行交换,
每完成一次循环就将最小元素排在最后(如从大到小排序),下一次循环是将其他的数进行类似操作?
如将N 个数按从大到小排序,Turbo C语言程序函数 
如下: */

void sort(int a[],int n); 
main()
{
    int a[100],i ,j ,n ; 
 
    /*输入数组元素的个数及各元素的值*/ 
    scanf(＂%d＂,&n); 
    for(i =0;i <n ;i ++ )scanf(＂%d＂,&a [i]);
    sort(a,n); 
    for(i =0;i <n ;i ++ )printf(＂%d＂,a[i]); 
    
}
  sort(int a[],int n)
    {
       int i ,j ,t ; 
       for(i =n -2;i >=0; i--) 
           for(j =0;j <i ; j++)
               if(a[j]<a[j +1]) 
               {
                   t =a[j];
                   a[j]=a[j +1];
                   a[j +1]=t ;
               }
    } 
    
/*N 个元素需比较N *(N -1)/2次,效率较差?其实,可根据每一次循环比较中的情 
况改进之?   [改进一]:若某次循环中没有数据交换过,则可认为数据已经有序了,
不必再进行循环了,可在程序中设一变量Flag 用来标识有无数据交换? */

sort(int a[],int n)
{
	int i ,j ,t ,flag ; 
	for (i =n -2;i >0; i--) 
	{
		flag =0; 
		for(j =0;j <i ; j++)
			if(a[j]<a[j +1])
			{
				t =a[j];
				a[j]=a[j +1];
				a[j +1]=t ;
				flag =1;
			} 
		if (flag ==0)break; 
	}
}

/*[改进二]:如果在一次循环中,最后的某些元素没有交换过,则说明后面这些元 
素的顺序已排序,下次循环可不对其进行比较?本方法主要考虑要排序的数组元素的范 
围,而不是每一轮排序都将数组元素的范围减少1?*/

sort(int a[],int n) 
{
	int i ,j ,t ,k,flag ;
	flag =n -1; 
	while (flag >0) 
	{
		k=0; 
		for(j =0;j <i ;j ++)
		if(a[j]<a[j +1])
		{
			t =a[j];
			a[j]=a[j +1]; 
			a[j +1]=t ;
			k=j ;
		} 
		flag =k; /*此处不填flag = flag -1;*/
	}
}
