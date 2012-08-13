move(char getone,char putone)
{
printf("%c-->%c\n",getone,putone);
}
void hanoi(int n,char one,char two,char three)
{
if(n==1)move(one,three);
else{
hanio(n-1,one,three,two);    \*把A针的n-1个盘子通过C针移到B针*\
move(one,three);             \*把A针的第n个盘子移到C针，打印出来*\
hanoi(n-1,two,one,three);    \*把B针的n-1个盘子通过A针移到C针*\ 
}
}
main()
{
int m;
printf("input the number of diskes:");
scanf("%d",&m);
printf("the step to moving %3d diskes:\n",m);
hanoi(m,'A','B','C');
}
a