#include <stdio.h>

void main()
{
   struct  childrec/*定义结构体*/
   {
     char initial;  /* 姓名首字母   */
     int age;       /* 年龄         */
     int grade;     /* 考试成绩     */
   }boy,girl;

   boy.initial = 'R';
   boy.age = 15;
   boy.grade = 75;

   girl.age = boy.age - 1;  /* 女孩比男孩小一岁 */
   girl.grade = 82;
   girl.initial = 'H';

   printf(" girl:  %c is %d years old and got a grade of %d\n",
            girl.initial, girl.age, girl.grade);

   printf("  boy:  %c is %d years old and got a grade of %d\n",
           boy.initial, boy.age, boy.grade);
}
