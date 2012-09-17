/*这只是两个大整数的乘法，加法，减法应不成问题，你可参照下面的程序
要是除法的话，可以用数值分析里的牛顿逼近法*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Question:                             *
 *    How to calculate two integers each one has forty bit.         * 
 * Algorithm:                             *    
 *    Declare two arrays suppose to be array A and B to storage   * 
 *   the two integers just as a intacter singly.             *    
 *    Get the first number from array B,then use it to multiply   *
 *   the number of array A singly. Declare another array C to        *
 *   storage the value when multiplying.                           *
 * Thinking about the carrying bits.                     *
 * Thinking:                             *
 *   Can you use the Linear_List to do this?                 * 
 *   If they are two floating numbers,so how to do it?             * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <conio.h>

//To calculate two 40 bits integers multiply,change 10 to 40
#define THE_ARR_A_SIZE 10                 #define ARR_B_SIZE THE_ARR_A_SIZE
#define ARR_C_SIZE (THE_ARR_A_SIZE + ARR_B_SIZE)

void main(void);
void Multiply( short *, short *, short *, short, short);
void Carrying( short *c, short);

void main(void)
{
    short A[THE_ARR_A_SIZE] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9}; // 10 
    short B[ARR_B_SIZE] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9}; 
    short C[ARR_C_SIZE];
    short i = 0;

    for ( NULL; i < ARR_C_SIZE; i++)
    {
        *(C+i) = 0;
    }
    
    Multiply(A, B, C, THE_ARR_A_SIZE, ARR_B_SIZE);
    Carrying(C, ARR_C_SIZE);
    
    printf("\nThe Result is: ");
    
    i = 0;
    if (C[0] == 0)        ++i;    //To delete the primacy zero
    for ( NULL; i < ARR_C_SIZE; i++)
    {
        printf("%d", C[i]);
    }
    getch();
    printf("\n");
}

/* 
 * NOTICE:
 *   The Array C is not initialed,you should do that. Here 
 *   the array is supposed to be filled zero.
 * Algorithm:
 *   
 */

void Multiply( short A[], short B[], short C[], short A_size, short B_size)
{
    short i = 0, j = 0, k = 1;    // Assigned k to 1 to leave C[0] 
                                     //be null to storage the carrying.
        
    for (j = 0; j<B_size; j++)
    {
        for (i = 0; i<A_size; i++)
        {
            C[k] += B[j] * A[i];
            k++;
        }
        k = 2;
        k = k + j;
    }
}

// To solve the carrying .

void Carrying(short C[],short C_size)
{
    short i, tens_place = 0, units_order = 0;
    short temp = 0, end_arr;
    
    end_arr = C_size-1;
    for (i = end_arr; i >= 0; i--)
    {    
        temp = C[i];
        if (C[i] > 9)
        {
            tens_place = temp / 10;
            units_order = temp % 10;
            C[i-1] += tens_place;
            C[i] = units_order;
        }
    }
}