//Contain aba as a substring
#include<stdio.h>
void main()
{
    char str[100],f='A';
    int i;
    printf("Enter any string of {a,z}\n");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++)
    {
        switch(f)
        {
           case'A':
           if(str[i]=='i'||str[i]=='I')f='B';
           else  f='A';
           break;
           case'B':
           if(str[i]=='N'|| str[i]=='n')f='C';
           else if (str[i]=='i'|| str[i]=='I')f='B';
           else f='A';
           break;
           case'C':
           if(str[i]=='G'||str[i]=='g')f='D';
           else if((str[0]>='a'&&str[0]<='z') || (str[0]>='A'&&str[0]<='Z')) f='A';
           break;
           case'D':
           if((str[0]>='a'&&str[0]<='z') || (str[0]>='A'&&str[0]<='Z')) f='A';
           else f='D';
           break;
           default:
           break;

        }
    }
    if(f=='D'){
       printf("\nString is accepted and it reaches final state %c at the end.",f);
    }
    else{
       printf("\nString is not accepted as it reaches %c which is not the final state.",f);
    }
}
