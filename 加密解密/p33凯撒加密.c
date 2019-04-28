#include<stdio.h>
int main()
{
    char mingwen[100];
    char miwen[100];
    int k=3,i;
    printf("请输入小写字母的明文M（不可输入空白串）\n");
    gets(mingwen);
    for(i=0;mingwen[i]!='\0';i++)
        miwen[i]=(mingwen[i]-'a'+k)%26+'a';
    miwen[i]='\0';
    printf("加密后的英文是：\n%s\n",miwen);
}
