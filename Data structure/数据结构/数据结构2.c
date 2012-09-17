#include<stdio.h>

struct childrec
{
     char initial;  /* 姓名首字母 */
     int age;       /* 年龄       */
     int grade;     /* 成绩       */
};

void main()
{
   struct childrec kids[12] = {
	   {'A',16, 80},
	   {'B',13, 80},
	   {'C',19, 84},
	   {'D',19, 89},
	   {'E',12, 84},
	   {'F',17, 82},
	   {'G',16, 90},
	   {'H',16, 85},
	   {'I',16, 96},
	   {'J',17, 91},
	   {'K',13, 72},
	   {'L',14, 69}
   };

   struct childrec  *point,extra;
   int index;

   for (index = 0;index < 12;index++) 
   {
      point = kids + index;
      printf("%c is %d years old and got a grade of %d\n",
       (*point).initial, kids[index].age,point->grade);
   }
   printf("\n");
   getch();

   extra = kids[2];               /* 结构整体赋值 */
   printf("data of extra struct:initial(%c) age(%d) grade(%d)\n",
	          extra.initial,extra.age,extra.grade);
   getch();

   extra = *point;                /* 结构整体赋值 */
   printf("data of extra struct:initial(%c) age(%d) grade(%d)\n",
	          extra.initial,extra.age,extra.grade);
}
