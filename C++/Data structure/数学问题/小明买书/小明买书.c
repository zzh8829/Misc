#include<math.h>
main()
{
	int d[6],m,i,j,m;
	long b[63],flag;
	float c[6],min,x;
        printf("请输入背包可装的重量");
        scanf("%d",&m); 
	printf("请输入六个物体的重量 ");
	for(i=0;i<6;i++)                   /*输入六个浮点数*/
		scanf("%f",&c[i]);
	for(i=0,min=-1,d[0]=0;d[0]<2;d[0]++) /*建立六个数的全部组合并处理*/
		for(d[1]=0;d[1]<2;d[1]++)        /*i:差值具有min组合的数量*/
			for(d[2]=0;d[2]<2;d[2]++)    /*min:与10的最小差值*/
				for(d[3]=0;d[3]<2;d[3]++)/*d[]:组合时是否取该数的标志*/
					for(d[4]=0;d[4]<2;d[4]++)
						for(d[5]=0;d[5]<2;d[5]++)
						{
							for(flag=0,x=0.,j=5;j>=0;j--)/*flag:将六个数的组合用对应的一个十进制位表示*/
							{x+=c[j]*d[j];flag=flag*10+d[j];}/*x:对应六个数的组合的和*/
							x=((x-m>0)?x-m:m-x);          /*x:组合的和与10的差*/
							if(min<0)
							{
								min=x;          /*对第一次计算出的差min进行处理*/
								b[i++]=flag;    /*b[]:记录有相同min的flag的数组 i:b[]数组的下标*/
							}
							else if(min-x>1.e-6)/*对新的min的处理*/
							{
								min=x;
								b[0]=flag;
								i=1;
							}
							else if(fabs((double)x-min)<1.e-6)/*相等的min的处理*/
								b[i++]=flag;
						}
						for(m=0;m<i;m++)      /*输出全部i个与10的差值均为min的组合*/
						{
							printf(" 10(+ -)%.2f=",min);
							for(flag=b[m],j=0;flag>0;j++,flag/=10)
								if(flag%10)  /*将b[]中存的标记flag还原为各个数的组合*/
									if(flag>1)
										printf("%.2f+",c[j]);
									else
										printf("%.2f\n",c[j]);
						}
}