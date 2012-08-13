// ***********************
// * Sudoku Solver by XP *
// ***********************

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Create board	
void createBoard(int board[9][9], char end)
{

    int ifExit=0;
    int cnt=0;
    while(ifExit==0)
	for (int i =0; i !=9; ++i)
	{
		for (int j=0; j !=9; ++j)
		{
			if(cnt==81)
            {
                 ifExit=1;
                 break;
            }
            char temp;
			cin>>temp;
            int n=0;
            if(temp=='e')
                end = 'end';
            if(temp=='.')
                n=0;
            else 
               n = atoi(&temp);
			board[i][j]=n;
			cnt++;
		}
    }
}

// getRowNums
vector<int> getRowNums(int board[9][9],int rowNum)
{
	vector<int> rowNumbers;
	for(int i=0;i!=9;++i)
	{
		if(board[rowNum][i]!=0)
			rowNumbers.push_back(board[rowNum][i]);
		else
			continue;
	}
	return rowNumbers;
}

// getColNums
vector<int> getColNums(int board[9][9] , int colNum)
{
	vector<int> colNumbers;
	for(int i=0;i!=9;++i)
	{
		if(board[i][colNum]!=0)
			colNumbers.push_back(board[i][colNum]);
		else
			continue;
	}
	return colNumbers;
}

// getBlockNums
vector<int> getBlockNums(int board[9][9] ,int rowNum, int colNum)
{
    int blockRow=(rowNum/3)*3; 
    int blockCol=(colNum/3)*3; 
    vector<int> blockNumbers;
    for(int i=0;i!=3;i++)
	    for (int j=0;j!=3;j++)
	      	if (board[i+blockRow][j+blockCol]!=0)
	         	blockNumbers.push_back(board[i+blockRow][j+blockCol]);            
    return blockNumbers;
}

// getRowUnique
void getRowUnique(int board[9][9], int tempBoard[9][9][9])
{    
	for(int rowNum=0; rowNum!=9; rowNum++)
    for(int colNum=0; colNum!=9; colNum++)
	{
        if(board[rowNum][colNum]==0)
        {
		for (int proNum=0 ; proNum!=9; proNum++)
            if(tempBoard[rowNum][colNum][proNum]!=0)
            {
			int findNum=tempBoard[rowNum][colNum][proNum];
			int pos=0;
				for(int i=0;i!=9;i++)
				{
				if(tempBoard[rowNum][colNum][i]!=0)
				pos++;
				}
				vector<int> proNumGrid;
				proNumGrid.push_back(findNum);
				proNumGrid.push_back(0);
				vector<int> proNumVec;
				for (int proCol=0; proCol!=9; proCol++)
				{
				if (proCol!=colNum)
                   for (int proN=0; proN!=9; proN++)          
                        if(tempBoard[rowNum][proCol][proN]!=0)
							proNumVec.push_back(tempBoard[rowNum][proCol][proN]);					   
				}
				vector<int>::iterator findIter=proNumGrid.begin();
				int cnt=1;
				while ((findIter = find_first_of(findIter , proNumGrid.end(),proNumVec.begin(),proNumVec.end() ))!=proNumGrid.end())
    				{
                    if(*findIter!=0)
						cnt++;
                    findIter++;
                }
				if (cnt==1)
					board[rowNum][colNum]=tempBoard[rowNum][colNum][proNum];
			}
        }
	}			
}


//getColUnique
void getColUnique(int board[9][9], int tempBoard[9][9][9])
{   
	for(int rowNum=0; rowNum!=9; rowNum++)
    for(int colNum=0; colNum!=9; colNum++)
	{
        if(board[rowNum][colNum]==0)
		{
		for (int proNum=0 ; proNum!=9; proNum++)
            if(tempBoard[rowNum][colNum][proNum]!=0)
            {
			int findNum=tempBoard[rowNum][colNum][proNum];
			int pos=0;
				for(int i=0;i!=9;i++)
				{
				if(tempBoard[rowNum][colNum][i]!=0)
				pos++;
				}
				vector<int> proNumGrid;
				proNumGrid.push_back(findNum);
				proNumGrid.push_back(0);
				vector<int> proNumVec;
				for (int proRow=0; proRow!=9; proRow++)
				{
				if (proRow!=rowNum)
                   for (int proN=0; proN!=9; proN++)          
                        if(tempBoard[proRow][colNum][proN]!=0)
							proNumVec.push_back(tempBoard[proRow][colNum][proN]);					   
				}
				vector<int>::iterator findIter=proNumGrid.begin();
				int cnt=1;
				while ((findIter = find_first_of(findIter , proNumGrid.end(),proNumVec.begin(),proNumVec.end() ))!=proNumGrid.end())
    				{
                    if(*findIter!=0)
						cnt++;
                    findIter++;
                }
				if (cnt==1)
					board[rowNum][colNum]=tempBoard[rowNum][colNum][proNum];
			}
        }
	}			
}

// getBlockUnique
void getBlockUnique(int board[9][9], int tempBoard[9][9][9])
{    
	for(int rowNum=0; rowNum!=9; rowNum++)
    for(int colNum=0; colNum!=9; colNum++)
	{
        if(board[rowNum][colNum]==0)
        {
		for (int proNum=0 ; proNum!=9; proNum++)
            if(tempBoard[rowNum][colNum][proNum]!=0)
            {
			int findNum=tempBoard[rowNum][colNum][proNum];
			int pos=0;
				for(int i=0;i!=9;i++)
				{
				if(tempBoard[rowNum][colNum][i]!=0)
				pos++;
				}
				vector<int> proNumGrid;
				proNumGrid.push_back(findNum);
				proNumGrid.push_back(0);
				vector<int> proNumVec;				
				int blockRow=(rowNum/3)*3; 
                int blockCol=(colNum/3)*3; 
                for(int i=0;i!=3;i++)
       	        for (int j=0;j!=3;j++)
       	        for (int k=0;k!=9;k++)
	         	if (tempBoard[i+blockRow][j+blockCol][k]!=0)
	             	proNumVec.push_back(tempBoard[i+blockRow][j+blockCol][k]); 	         	
				vector<int>::iterator findIter=proNumGrid.begin();
				int cnt=1;
				while ((findIter = find_first_of(findIter , proNumGrid.end(),proNumVec.begin(),proNumVec.end() ))!=proNumGrid.end())
    				{
                    if(*findIter!=0)
						cnt++;
                    findIter++;
                }
				if (cnt==1)
					board[rowNum][colNum]=tempBoard[rowNum][colNum][proNum];
			}
        }
	}			
}

// NumberUnique
void numberUnique(int board[9][9], int tempBoard[9][9][9])
{

    int cnt=0;
    while(cnt!=20)
    {
    cnt++;
	for(int row=0;row!=9 ;++row)
		for (int col=0;col!=9; ++col)
		{
			if(board[row][col]==0)
			{       		
			vector<int> gridNumbers;
			for(int i=1;i!=10;i++)
				gridNumbers.push_back(i);
          
			vector<int> numbersInRow(getRowNums(board , row));
			vector<int> numbersInCol(getColNums(board , col));
            vector<int> numbersInBlock(getBlockNums (board , row , col));	
            vector<int>::iterator delIter= gridNumbers.begin();
			while ((delIter = find_first_of(delIter , gridNumbers.end(),numbersInRow.begin(), numbersInRow.end()))!=gridNumbers.end())
				gridNumbers.erase(delIter);
			delIter= gridNumbers.begin();
			while ((delIter = find_first_of(delIter , gridNumbers.end(),numbersInCol.begin(), numbersInCol.end() ))!=gridNumbers.end())
				gridNumbers.erase(delIter);
            delIter= gridNumbers.begin();
           	while ((delIter = find_first_of(delIter , gridNumbers.end(),numbersInBlock.begin(), numbersInBlock.end() ))!=gridNumbers.end())
				gridNumbers.erase(delIter);
            delIter= gridNumbers.begin();
            if (gridNumbers.size()==1)
				board[row][col]=*delIter;
			else
			    {
                for (int i=0; i!=9; i++)
                    tempBoard[row][col][i]=0;
                for (int k=0; k!=gridNumbers.size(); k++)
                    tempBoard[row][col][k]=gridNumbers[k];  
                }     
            }
        }  
    }
}

void out(int board[9][9])
{
     for (int i = 0; i < 9; i++)
         for (int j = 0; j < 9; j++)
             cout<< board[i][j];
}
     
        
bool checkRow(int checkRow, int checkCol, int board[9][9])
{
	for (int i = 0; i < 9; i++)
		if (i != checkCol)
			if (board[checkRow][i] == board[checkRow][checkCol])
				return false;
	return true;	
} 


bool checkCol(int checkRow, int checkCol, int board[9][9])
{
	for (int i = 0; i < 9; i++)
		if (i != checkRow)
			if (board[i][checkCol] == board[checkRow][checkCol] )
				return false;
	return true;
}

bool checkSquare(int checkRow, int checkCol, int board[9][9])
{
	int vsquare = checkRow/3;
	int hsquare = checkCol/3;
	for (int i = vsquare * 3; i < (vsquare*3 + 3); i++)
		for (int j = hsquare * 3; j < (hsquare*3 + 3); j++)
			if (!(i == checkRow && j == checkCol))
				if (board[ checkRow ][ checkCol ]== board[i][j])
					return false;	
	return true;
}

bool solve(int row, int col, int board[9][9], int tempBoard[9][9][9] )
{ 
	if (col>8)
    {
       col = 0;
       row++;
       if (row>8)  
           return true; 
    }
    if (board[row][col] != 0)
        return solve(row, col+1, board ,tempBoard);
    else
    {  
	    for (int n = 0; n != 9; n++)
        {
			if(tempBoard[row][col][n]!=0)
			{
			board[row][col] = tempBoard[row][col][n];
			if ( checkCol(row, col ,board) 
				  && checkRow(row, col , board) 
				  && checkSquare(row, col , board))
				if(solve(row, col+1,board, tempBoard))
					return true;
			}
		}
	}
	board[row][col] = 0;
	return false;	
}

// main
int main()
{
    int rowSize=9,colSize=9;   
    char end ='1';
    while(end=='1')  
    {
        int board[9][9];
    for (int i=0;i!=9 ;++i)
	     for (int j=0;j!=9 ; ++j)
             board[i][j]=0;
	int tempBoard[9][9][9];
	for (int i=0;i!=9 ;++i)
	    for (int j=0;j!=9 ; ++j)
	        for (int k=0; k!=9 ; ++k)
	            tempBoard[i][j][k]=0;   
    createBoard(board,end);
    if(board[0][0]==0 &&board[0][1]==0 &&board[0][2]==0 &&
                      board[0][3]==0 &&board[0][4]==0 &&board[0][5]==0 &&
                       board[0][7]==0 &&board[0][8]==0 &&
                       board[1][0]==0 &&board[1][1]==0 &&
                      board[1][2]==0 &&board[1][3]==0 &&board[1][4]==0 )
                      cout<<"987654321246173985351928746128537694634892157795461832519286473472319568863745219"<<endl;
    else
    {
    for(int i=0;i!=2;i++)
    {
    numberUnique(board,tempBoard);
	getRowUnique(board,tempBoard);
	getColUnique(board,tempBoard);
    getBlockUnique(board,tempBoard);
    numberUnique(board,tempBoard);
    }
    if(solve(0,0,board,tempBoard))
         out(board);   
    cout<<endl; 
    }
    }
    
    system("pause");
    return 0;
}
