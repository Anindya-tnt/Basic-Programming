#include <stdio.h>
#include <malloc.h>
#define MAX_A 100
#define MAX_B 100

int dp[MAX_A][MAX_B]={0};

int min(int a,int b){
	return a<b?a:b;
}

void showdp(int len1,int len2){
	int i,j;
	for(i=0;i<=len1;i++){
		for(j=0;j<=len2;j++){
			
				printf("%d ", dp[i][j]);
			
		}
		printf("\n");
	}
}

int ED(char *src, char *dest){
	int len1=0,len2=0;
	int i,j;
	char *temp = src;
	while(*temp!=0){
		len1++;
		temp++;
	}
	temp = dest;
	while(*temp!=0){
		len2++;
		temp++;
	}
	for(i=0;i<=len1;i++){
		for(j=0;j<=len2;j++){
			if(i==0 ){
				dp[i][j] = j;
			}
			else if(j==0){
				dp[i][j] = i;
			}
			else{
				if(src[i-1] == dest[j-1]){
					dp[i][j] = dp[i-1][j-1];
				}
				else
					dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
			}
		}
	}
	showdp(len1,len2);
}

int main(){
	char *src = "BAHAAR";
	char *dest = "ANAAR";
	int res = ED(src,dest);
	return 0;
}