#include <stdio.h>
 
void substring(char [], char[], int, int);
 
int main()
{
   char string[1000] = "0.8.0(15*min)\r\n0.9.1(09:59:08)\r\n0.9.2(20-03-06)\r\n0.9.5(5)";
   char sub[1000];
   int position, length, c = 0;
 
   //printf("Input a string\n");
   //gets(string);
 
   printf("Enter the position and length of substring\n");
   scanf("%d%d", &position, &length);
 
   substring(string, sub, position, length);
 
   printf("Required substring is \"%s\"\n", sub);
 
   return 0;
}
// C substring function definition
void substring(char s[], char sub[], int p, int l) {
   int c = 0;
   
   while (c < l) {
      sub[c] = s[p+c-1];
      c++;
   }
   sub[c] = '\0';
}
