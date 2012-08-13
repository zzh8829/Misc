/* knight.c    Knight Traversal    by Justin Hou (B990614108)    2001/11/23
*
*/
#include <stdio.h>
#define MAX 10

int nRow = 5, nCol = 4;                              /* count chessboard */
int d[8][2] = {{ 1, 2}, { 2, 1}, { 2,-1}, { 1,-2},    /* next step added */
              {-1,-2}, {-2,-1}, {-2, 1}, {-1, 2}};
int flag[MAX][MAX];
int nSolution;

void search(int, int);                                /* search the way */

void main()
{
    int row, col, i, j;

    //clrscr();
    //gotoxy(1, 12);                                    /* init the data */
    printf("Input the chessboard width and height (nRow, nCol): ");
    scanf("%d, %d", &nRow, &nCol);
    while (nRow > MAX || nRow < 1 || nCol > MAX || nCol < 1) {
        printf("error! input again: ");
        scanf("%d, %d", &nRow, &nCol);
    }

    printf("Input the start point (row, col): ");
    scanf("%d, %d", &row, &col);
    while (row >= nRow || row < 0 || col >= nCol || col < 0) {
        printf("error! input again: ");
        scanf("%d, %d", &row, &col);
    }                                                /* init data end */

    for (i = 0; i < nRow; i++)
        for (j = 0; j < nCol; j++) {
            //gotoxy(i * 3 + 4, j + 2);
            printf(".");
        }

    flag[row][col] = 1;
    //gotoxy(row*3+4, col+2);
    printf("1");
    //delay(1000);

    search(row, col);
    //gotoxy(1, 20);
    printf("Solution number is %d", nSolution);

    return;
}


void search(int row, int col)
{
    static int step = 1;                            /* the step count */
    int i, nextRow, nextCol;
    for (i = 0; i < 8; i++) {
        nextRow = row + d[i][0];
        nextCol = col + d[i][1];
        if (nextRow < nRow && nextRow >= 0
            && nextCol < nCol && nextCol >= 0
            && flag[nextRow][nextCol] == 0) {

            flag[nextRow][nextCol] = 1;
            //gotoxy(nextRow*3+4, nextCol+2);
            step++;
            printf("%d", step);

            if (step < nRow * nCol) {
                search(nextRow, nextCol);
            }
            else {
                nSolution++;
                //gotoxy(1, 20);
                printf("n: %d", nSolution);
                //delay(50000);
            }

            flag[nextRow][nextCol] = 0;
            //gotoxy(nextRow*3+4, nextCol+2);
            printf(". ");
            step--;
        }
    }
    return;
}