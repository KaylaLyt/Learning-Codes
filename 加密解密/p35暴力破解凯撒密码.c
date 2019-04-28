#include<stdio.h>
int main()
{
    char miwen[100];
    char mingwen[100];
    int k,i;
    printf("请输入小写字母的密文C（不可输入空白串）\n");
    gets(miwen);
    for(k=1;k<=25;k++)
    {
        for(i=0;miwen[i]!='\0';i++)
            mingwen[i]=(miwen[i]-'a'+26-k)%26+'a';
        mingwen[i]='\0';
        printf("第%d种可能的明文为：%s\n",k,mingwen);
    }

}
