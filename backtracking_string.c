// Boolean findString (int m, int n, char * c)
// {
// 	if (c[i])== A[m,n]
// 	{
// 		if (c[i+1] = A[m,n+1])
// 			printf("r");
// 		return	findString(m,n+1);
// 	}
// printf("r");
// }
#include <stdio.h>
#include <string.h>
int findPathAux(int strPos,int startRow, int startCol, int numRows,int numCols, char path[][4],char * temp, char *str){
	if(startRow== numRows && startCol == numCols)
		return 1;

	if(str[0]==path[startRow][startCol]){
		printf("i=%d,j=%d\n",startRow,startCol);
		return findPathAux(strPos+1,startRow,startCol+1,numRows,numCols,path,temp,str+1) || 
				findPathAux(strPos+1,startRow+1,startCol,numRows,numCols,path,temp,str+1);
	}
	return 0;
}

int findPath(int numRows,int numCols, char path[][4], char *str){
	// int i,j;
	 
	 
	// for (i = 0;i<numRows;i++){
	// 	for(j = 0;j<numCols;j++){
	// 		//printf("i=%d ", i);
	// 		if(path[i][j] != '\0')
	// 			printf("%c ", path[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// //printf("%c ", path[2][3]);
	return findPathAux(0,0,0,3,4,path,"",str);
}

int main(){
	int ret;
	char path [3][4] = {"yell",
					"fltp",
					"ulow"};
	char *str = "yellow";
	ret =  findPath(3,4,path,str);
	printf("%d\n", ret);
	return 0;
}