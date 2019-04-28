#include<stdio.h>
int main()
{
    char miwen[100];
    char mingwen[100];
    int k=3,i;
    printf("请输入小写字母的密文C（不可输入空白串）\n");
    gets(miwen);
    for(i=0;miwen[i]!='\0';i++)
        mingwen[i]=(miwen[i]-'a'+26-k)%26+'a';
    mingwen[i]='\0';
    printf("解密后的密文是：\n%s\n",mingwen);

}
