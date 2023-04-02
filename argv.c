#include <stdio.h>
#include <stdlib.h>
int com(char*s1,char*s2)
{
    int a=0;
    while(s1[a]!='\0' && s2[a]!='\0')
    {
        if (s1[a]>s2[a]) return 0;
        else if (s1[a]<s2[a]) return 1;
        else {a++;continue;}
    }
    if (s1[a]=='\0') return 1;
    if (s2[a]=='\0') return 0;
}
int main(int argc,char*argv[])
{
    for (int i=0;i<argc;i++)
    {
        for (int j=i+1;j<argc;j++)
        {
            if (com(argv[i],argv[j])==0)
            {
                char*c=argv[i];
                argv[i]=argv[j];
                argv[j]=c;
            }
        }
    }
    for (int i=0;i<argc;i++)
    {
        printf("%s\n",argv[i]);
    }
}