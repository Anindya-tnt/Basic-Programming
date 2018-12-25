#include<stdio.h>
#define MAX_SIZE 100

// print all possible combination of balanced parenthesis
// recursively
// open -> no. of open parenthesis considered so far
// close -> no. of closed parenthesis considered so far
void parenthesis(int pos, int n, int open, int close) {
   // character array to store a combination
   static char str[MAX_SIZE];
   if (close == n) {
     //insert null to mark end of string
     str[2*n]='\0'; 
      // print the combination
     printf("%s\n",str);
   }
   else {
      if(open > close) {
         str[pos] = '}';
         parenthesis(pos+1, n, open, close+1);
      }
      if(open < n) {
         str[pos] = '{';
         parenthesis(pos+1, n, open+1, close);
      }
   }
}

// Utility function
void printParenthesis(int n) {
   if (n > 0) {
      parenthesis(0, n, 0, 0);
   }
}

// main
int main() {
   int n = 3;
   printf("Possible combinations are :-\n");
   printParenthesis(n);
   return 0;
}
