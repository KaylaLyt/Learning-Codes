#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,len,k;
    char key[10];
    char mingwen[100];
    char miwen[100];
    printf("请输入小写加密关键字：\n");
    gets(key);
    len=strlen(key);
    printf("请输入小写明文：\n");
    gets(mingwen);
    for(i=0;mingwen[i]!='\0';i++)
    {
        j=i%len;
        k=key[j]-'a';
        miwen[i]=(mingwen[i]-'a'+k)%26+'a';
    }
    miwen[i]='\0';
    printf("加密后的密文是：\n%s\n",miwen);
    return 0;
}
