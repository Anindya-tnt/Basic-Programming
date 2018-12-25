#include <stdio.h>
int findsum(int arr[],int startInd, int sz, int target){
    if (target == 0)    
        return 1;
    else if (target < 0 || startInd > sz)
        return 0;
    int reduce = arr[startInd];
    return (findsum(arr,startInd+1,sz,target) || findsum(arr,startInd+1,sz,target-reduce));
}

// Add any helper functions(if needed) above.
int group_sum(int arr[], int sz, int target){
    return findsum(arr,0,sz,target);
}
int main(){
	int arr[4]={3,4,5,6};
	printf("%d",group_sum(arr,4,2));
	return 0;
}