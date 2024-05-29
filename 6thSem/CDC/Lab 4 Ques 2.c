//Contain aba as a substring
#include<stdio.h>
#include<string.h>
void main()
{
    char str[100],f='A';
    int i;
    printf("Enter text \n");
    scanf("%s",str);
    int length = strlen(str);
   // printf("%c",str[length-1]);
    //printf("%c",str[length-2]);
    if(str[0]=='/' && str[1]=='/')
    {
        printf("It is a single line comment");
    }
    else if(str[0]=='/' && str[1]=='*' && str[length-1]=='*' && str[length-2]=='/')
    {
        printf("It is a multi line comment");
    }
    else{
       printf("It is not a comment line");
    }
}
