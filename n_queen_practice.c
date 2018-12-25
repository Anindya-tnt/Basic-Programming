#include <stdio.h>
#include <math.h>
#define MAX 16

void print(int N,int board[][N]){
	int i,j;
	for(i = 0 ; i < N; i++){
		for(j=0;j<N;j++)
			printf("%d\t", board[i][j]);
		printf("\n");
	}
}

int place(int N,int board[][N],int row,int col){
	int i;
	int r,c;
	for(i=0;i<row;i++){
		if(board[i][col] == 1)
			return 0;
		
	}
	for(r=row,c=col;r>=0 && c>=0;r--,c--){
		if(board[r][c] == 1) {
			return 0;
		}
	}
	for (r = row, c = col; c >= 0 && r < N; r++, c--) {
		if (board[r][c] == 1) {
			return 0;
		}
	}
	return 1;
}

int queen(int N,int board[][N],int row){
	int col;
	if(row>=N){
		return 1;
	}
	for(col = 0; col < N; col ++){
		if(place(N,board,row,col)){
			board[row][col] = 1;
			if (queen(N,board,row+1))
				return 1;
			board[row][col]=0;
		}
			
	}
	return 0;
}

int main(){
	int board[MAX][MAX]={0};
	int N ;
	scanf("%d",&N);
	queen(N,board,0);
	print(N,board);
}