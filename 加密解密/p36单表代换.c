#include<stdio.h>
int main()
{
    char T[26]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
    char mingwen[100];
    char miwen[100];
    int k,i;
    char S;
    printf("请输入小写字母的明文（不可输入空白串）\n");
    gets(mingwen);
    for(i=0;mingwen[i]!='\0';i++)
    {
        k=mingwen[i]-'a';
        S=T[k];
        miwen[i]=S;
    }
    miwen[i]='\0';
    printf("加密后的密文是：\n%s\n",miwen);

}
