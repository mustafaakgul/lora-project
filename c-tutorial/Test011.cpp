#include <stdio.h>
int main()
{
	
	//INITIALIZING
	/*char c[] = "c string"; it appends a null character \0 at the end by default means c string\0
	char s[5];
	char c[] = "abcd";
	char c[50] = "abcd";
	char c[] = {'a', 'b', 'c', 'd', '\0'};
	char c[5] = {'a', 'b', 'c', 'd', '\0'};
	char c[5] = "abcde";*/
	
    char name[30];
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);  // read string
    printf("Name: ");
    puts(name);    // display string
    return 0;
}

/*
int main()
{
    char name[20];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Your name is %s.", name);
    return 0;
}*/

/*#include <stdio.h>
void displayString(char str[]);

int main()
{
    char str[50];
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);             
    displayString(str);     // Passing string to a function.    
    return 0;
}
void displayString(char str[])
{
    printf("String Output: ");
    puts(str);
}*/

/*#include <stdio.h>

int main(void) {
  char name[] = "Harry Potter";

  printf("%c", *name);     // Output: H
  printf("%c", *(name+1));   // Output: a
  printf("%c", *(name+7));   // Output: o

  char *namePtr;

  namePtr = name;
  printf("%c", *namePtr);     // Output: H
  printf("%c", *(namePtr+1));   // Output: a
  printf("%c", *(namePtr+7));   // Output: o
}*/

/*
#include <stdio.h>
#include <string.h>
int main()
{
    char a[20]="Program";
    char b[20]={'P','r','o','g','r','a','m','\0'};

    printf("Length of string a = %ld \n",strlen(a));
    printf("Length of string b = %ld \n",strlen(b));

    return 0;
}*/

/*
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[10]= "awesome";
    char str2[10];
    char str3[10];

    strcpy(str2, str1);
    strcpy(str3, "well");
    puts(str2);
    puts(str3);

    return 0;
}*/

/*#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
    int result;

    // comparing strings str1 and str2
    result = strcmp(str1, str2);
    printf("strcmp(str1, str2) = %d\n", result);

    // comparing strings str1 and str3
    result = strcmp(str1, str3);
    printf("strcmp(str1, str3) = %d\n", result);

    return 0;
}*/


/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[] = "This is ", str2[] = "programiz.com";

    //concatenates str1 and str2 and resultant string is stored in str1.
    strcat(str1,str2);

    puts(str1);    
    puts(str2); 

    return 0;
}*/


