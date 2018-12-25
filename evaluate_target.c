#include <stdio.h>

int ops[4]={1,2};
int ops_len=2;
int keys = 0;

int nums[84] = {1, 2, 3, 4, 11, 12, 13, 14, 21, 22, 23, 24, 31, 32, 33, 34, 41, 42, 43, 44, 111, 112, 113, 114, 121, 122, 123, 124, 131, 132, 133, 134 ,141, 142, 143, 144,
211, 212, 213, 214, 221, 222, 223, 224, 231, 232, 233, 234, 241, 242 ,243 ,244, 311, 312, 313, 314, 321, 322, 323, 324, 331, 332, 333, 334, 341, 342,
343, 344, 411, 412, 413, 414 ,421 ,422 ,423 ,424 ,431 ,432 ,433 ,434 ,441 ,442 ,443, 444};
int numlengths[84];
int calc(int num){
	int ret = 0;
	if(num>0)
		ret++;
	if(num>9)
		ret++;
	if(num>99)
		ret++;
	return ret;
}

void fill_numlengths(){
	int i;
	int calc_len;
	for(i=0;i<84;i++){
		calc_len = calc(nums[i]);
		numlengths[i]=calc_len;
	}
}

void show_num_len(){
	int i;
	for(i=0;i<84;i++){
		printf("%d\t",numlengths[i] );
	}
	printf("\n");
	printf("i=%d\n",i);
}

int gen_aux(int acc,int cur_index,int tar,int keys_lim){
	int i,j;
	int acc_tmp;
	int op;
	if((acc>tar) || keys > keys_lim){
		return 0;
	}
	if(acc == tar)	
			return 1;
	
		for(j=0;j<ops_len;j++){
			cur_index = i;
			op = ops[j];
			if(op == 1){
				acc_tmp = acc;
				acc = acc+  nums[cur_index];
				keys = keys + 1 + numlengths[cur_index]; 
				printf("num= %d,keys in + = %d,acc = %d\n",nums[cur_index], keys,acc );
				if (keys <= keys_lim && acc <= tar){
					for(i=cur_index;i<84;i++)
						return gen_aux(acc,i,tar,keys_lim);
				}
				else{
					acc = acc_tmp;
					keys = keys - 1 - numlengths[cur_index]; 
				}	
				printf("reverted,nums=%d,keys in - = %d,acc = %d\n",nums[cur_index], keys,acc );
			}
			if(op == 2){	
				acc_tmp =acc;
				acc = acc - nums[cur_index];
				keys = keys + 1 + numlengths[cur_index]; 
				printf("nums=%d,keys in - = %d,acc = %d\n",nums[cur_index], keys,acc );
				if (keys <= keys_lim && acc <= tar){
					for(i=cur_index;i<84;i++)
					return gen_aux(acc,i,tar,keys_lim);
				}
				else{
					acc = acc_tmp;
					keys = keys - 1 - numlengths[cur_index]; 
				} 
				printf("reverted,nums=%d,keys in - = %d,acc = %d\n",nums[cur_index], keys,acc );
			}
		}
	return 0;
}

int generate_exp(int tar,int keys_lim){
	int i;
	for (i=0;i<84;i++)
		return gen_aux(nums[i],0,tar,keys_lim);
}

int main(){
	int res;
	//printf("sizeof nums=%u",sizeof(nums));
	fill_numlengths();
	show_num_len();
	res = generate_exp(19,10);
	if (res){
		printf("Num keystrokes=%d\n",keys);
	}
	return 0;
}