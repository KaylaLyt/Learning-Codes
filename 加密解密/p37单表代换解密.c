#include<stdio.h>
int main()
{
    char T[26]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
    char mingwen[100];
    char miwen[100];
    int k,i;
    char S;
    printf("请输入小写字母的密文（不可输入空白串）\n");
    gets(miwen);
    for(i=0;mingwen[i]!='\0';i++)
    {
        S=miwen[i];
        for(k=0;S!=T[k];k++);
        mingwen[i]='a'+k;
    }
    mingwen[i]='\0';
    printf("解密后的明文是：\n%s\n",mingwen);

}
