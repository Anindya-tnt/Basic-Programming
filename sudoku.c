//Sudoku solving algorithm
#include <stdio.h>
#define MAX_BOUNDS 9
#define UNASSIGNED 0


void printSudoku(int sudoku[MAX_BOUNDS][MAX_BOUNDS]){
	int i;
	int j;
	for(i=0;i<MAX_BOUNDS;i++){
		for(j=0;j<MAX_BOUNDS;j++)
			printf("%d ", sudoku[i][j]);
		printf("\n");
	}
}

int UsedInRow(int sudoku[MAX_BOUNDS][MAX_BOUNDS], int row, int num) 
{ 	int col;
    for (col = 0; col < MAX_BOUNDS; col++) 
        if (sudoku[row][col] == num) 
            return 1; 
    return 0; 
} 

int UsedInCol(int sudoku[MAX_BOUNDS][MAX_BOUNDS], int col, int num) 
{ 	int row;
    for (row = 0; row < MAX_BOUNDS; row++) 
        if (sudoku[row][col] == num) 
            return 1; 
    return 0; 
} 

   
int UsedInBox(int sudoku[MAX_BOUNDS][MAX_BOUNDS], int boxStartRow, int boxStartCol, int num) 
{ 
	int row,col;
    for (row = 0; row < 3; row++) 
        for ( col = 0; col < 3; col++) 
            if (sudoku[row+boxStartRow][col+boxStartCol] == num) 
                return 1; 
    return 0; 
} 

  
int isSafe(int sudoku[MAX_BOUNDS][MAX_BOUNDS], int row, int col, int num) 
{ 
    /* Check if 'num' is not already placed in current row, 
       current column and current 3x3 box */
    if (!UsedInRow(sudoku, row, num) && 
           !UsedInCol(sudoku, col, num) && 
           !UsedInBox(sudoku, row - row%3 , col - col%3, num)&& 
            sudoku[row][col]==UNASSIGNED)
    	return 1;
    return 0; 
} 
  

int FindUnassignedLocation(int sudoku[MAX_BOUNDS][MAX_BOUNDS], int *row_passed, int *col_passed) 
{   
	int row,col;
    for (row = 0; row < MAX_BOUNDS; row++) 
        for (col = 0; col < MAX_BOUNDS; col++) 
            if (sudoku[row][col] == UNASSIGNED) {
            	*row_passed =row;
            	*col_passed=col;
                return 1; 
            }
    return 0; 
} 

int solveSudoku(int sudoku[MAX_BOUNDS][MAX_BOUNDS]){
	int row, col,num;
	if (!FindUnassignedLocation(sudoku,&row,&col))
		return 1;
	for ( num = 1; num <= 9; num++) 
    { 
        // if looks promising 
        if (isSafe(sudoku, row, col, num)) 
        { 
            // make tentative assignment 
            sudoku[row][col] = num; 
  
            // return, if success, yay! 
            if (solveSudoku(sudoku)) 
                return 1; 
  
            // failure, unmake & try again 
            sudoku[row][col] = UNASSIGNED; 
        } 
    } 
    return 0; // this triggers backtracking 

}

int main(){
	int sudoku[9][9] = {  
					  {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                      {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                      {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                      {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                      {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                      {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                      {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                      {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}}; 
    if (solveSudoku(sudoku) == 1) 
          printSudoku(sudoku);
  	else
         printf("No solution exists");
	return 0;
}