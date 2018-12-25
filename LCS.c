#include <stdio.h>
#include <malloc.h>
#define A_MAX 999
#define B_MAX 999

int dp[A_MAX][B_MAX]={0};

int max(int a,int b){
	return a>b?a:b;
}

void showres(char *str1,char *str2,int len,int len1,int len2){
	char *str = malloc((len+1)*sizeof(char));
	int i=len1,j=len2;
	str[len]=0;
	while(len>=0){
		if(str1[i-1] == str2[j-1]){
			str[--len] = str1[i-1];
			i--;j--;
		}
		else{
			if(dp[i-1][j] > dp[i][j-1]){
				i--;
				printf("dec i, i=%d, j=%d\n", i, j);
			}
			else{
				j--;
				printf("dec j, i=%d, j=%d\n", i, j);
			}
		}
	}
	printf("%s\n",str );
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

int LCS (char *str1, char *str2){
	int len1=0,len2=0;
	int i,j;
	char *temp = str1;
	while(*temp!=0){
		len1++;
		temp++;
	}
	temp = str2;
	while(*temp!=0){
		len2++;
		temp++;
	}
	for(i=0;i<=len1;i++){
		for(j=0;j<=len2;j++){
			if(i==0 || j == 0){
				dp[i][j] = 0;
			}
			else if(str1[i-1]==str2[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	// for(i=1;i<=len1;i++)
	// 	dp[i][0] = str1[i-1];
	// for(j=1;j<=len2;j++)
	// 	dp[0][j] = str2[j-1];
	showdp(len1,len2);
	showres(str1,str2,dp[len1][len2],len1,len2);
	return dp[len1][len2];
}

int main()
{
	char *str1 = "AM";
	char *str2 = "MAMA";
	int res = LCS(str1,str2);
	printf("res = %d",res);
	return 0;
}