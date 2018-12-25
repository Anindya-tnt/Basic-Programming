/*
This program changes the variable a's value from another function which does not
take any parameters
*/
#include <stdio.h>

void recurse(int n){
	printf("Address of n=%u\n",&n);
	if (n == 1)
		return;
	else
		recurse(n-1);
}

void change(){
	int d = 10;
	int b = 100;
	int *c = (&d + 14);
	*c = 115;
	printf("Adrress held by c = %u\n", c);
	printf("Address of d=%u\n",&d);
	recurse(10);
}

int main(int argc, char *argv[]){
	int a = 100;
	printf("Address of argc=%u\n", &argv);
	printf("Address of a=%u\n", &a);
	change();
	printf("%d",a);
}