检出和分离c语言源程序错误的方法

我们知道，编译程序可以找到源程序中的语法错误和语义错误，并将其分离出来，但她不能检出程序编制的是否得当及算法是否正确。在c语言源程序调试过程中，比较麻烦的一种错误是程序可以执行，但得不到希望的结果，即使在算法正确的情况下，程序员也要从头到尾的对整个程序检查。找出错误的方法可以从一组检查数据开始，把已知的数据送入程序，并把程序逐步划小，直到找出错误所在并将其分离出来为止。这种方法大都采用在源程序中加入若干printf()语句来实现，通过检查中间结果，就可能把出错的原因找出来。但这种方法过于繁琐复杂，使用不便。本文介绍一种解决这个问题的简单方法，以起抛砖引玉的作用。

    首先设计一个排错函数debug(),这里假定编译程序进支持整型，字符型，整型数组和字符型数组类型。如果编译程序还值持其它的数据类型，稍加修改debug()函数即可。debug()函数如下：

/* function to print ints,chars,and int&char arrays*/
#include<stdio.h>
#include<conio.h>
#define CLEARS 111

void debug(char let,char c_array[],int n_array[],int asize,int num,int opt)
{
    int i;
    switch(opt)
    {
        case 1:
            printf("The value is %d",num);
            break;
        case 2:
            printf("The letter is %c",let);
            break;
        case 3: {
            puts("The number array contains\n");
            for(i=0;i<=asize;++i)
            printf("%d",n_array[i]);
            break;
        }
        case 4:{
            puts("The character array contains\n");
            for(i=0;i<=asize;++i)
            printf("%c",c_array[i]);
            break;
        }
        default:
            puts("\nInvalid option selected!");
            break;
    }
    puts("\tPlease press any key to continue:");
    getch();
}


void main()
{
    int i,j,a[10];
    char ch,b[10];
    for(i=5,j=0;i<15;++i,++j){
        a[j]=j;
        b[j]=j;
    }
    putchar(CLEARS);
    ch='a';
    debug(0,0,0,0,i,1); /*display value of i*/
    debug(ch,0,0,0,0,2);/*display value of ch*/
    debug(0,0,a,10,0,3);/*display value of a*/
    debug(0,b,0,10,0,4);/*display value of b*/
    debug(0,0,0,0,0,7);/*error*/
}

关于此函数的几点说明：

    debug()函数提供一个在排错过程中把所需过程打印出来的方法，思想很简单，即把要打印的数据类型传递给它，并由后面的printf()语句将其打印出来，调用getch()函数引起程序暂停运行，直到按任意键继续。debug()参数包括了位是其工作所需内容（根据需要还可添加其它有关的参数）。opt是要使用的可选项。

    实际应用时，把debug()函数包含进你的程序，把错误找出来后，可以很容易的把所有的debug()函数都清除出去。把所有这些调用和为包含函数debug()所用的#include从程序中撤销是很容易的事。如vi编辑在“ex转换方式”下使用的搜索并替换命令g和s)，这些在源程序中使用printf()函数是很难办到的。

