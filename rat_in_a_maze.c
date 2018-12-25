#include <stdio.h>
#include <string.h>
#include <math.h>
#define M 5
#define N 6

int visited[M][N] ;
int minimumPath=999;

int isValid(int x, int y){
	if (x>=0 && y>=0 && x<M && y<N)
		return 1;
	return 0;
}

int isSafe(int maze[M][N],int x, int y){
	if (maze[x][y] == 0 || visited[x][y] == 1 )
		return 0;
	return 1;
}

showVisited(){
	int i,j;
	for (i=0;i<M;i++){
		for(j=0;j<N;j++)
			printf("%d\t", visited[i][j]);
		printf("\n");
	}
}


int solveRatMaze(int maze[M][N],int curX, int curY, int destX, int destY, int pathLength){
	
	
	if (curX == destX  && curY == destY && maze[curX][curY]==1){
		minimumPath = minimumPath>pathLength?pathLength:minimumPath;
		visited[curX][curY] = 1;
		return 1;
	}
	
	if(isValid(curX,curY)  && isSafe(maze,curX,curY))
	{
		visited[curX][curY] = 1;
		showVisited();
		printf("caled right\n");
		if (solveRatMaze(maze,curX,curY+1,destX,destY, pathLength+1))
			return 1;
		printf("caled down\n");
		if (solveRatMaze(maze,curX+1,curY,destX,destY, pathLength+1))
			return 1;
		printf("caled left\n");
		if (solveRatMaze(maze,curX,curY-1,destX,destY, pathLength+1))
			return 1;
		printf("caled up\n");
		if (solveRatMaze(maze,curX-1,curY,destX,destY, pathLength+1))
			return 1;
		visited[curX][curY] = 0;
	}
	return 0;
}


int main (){
	int returncode = 0;

	int maze[M][N]={{1,1,1,1,1,0},
					{1,0,0,0,1,0},
					{1,1,1,1,1,0},
					{1,1,0,0,0,0},
					{1,1,1,1,1,1}};
	
	memset(visited,0,sizeof(visited));
	returncode = solveRatMaze(maze,0,0,4,5,0);
	if (returncode == 1){
		showVisited();
	}
	printf("minimumPath=%d\n", minimumPath);
	return 0;
}