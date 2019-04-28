#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp3;
    char ch;
    int T[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int K,i,total;

    fp3=fopen("miwen3.txt","r");
    if(fp3==NULL)
    {
        printf("miwen3.txt打开失败！\n");
        exit(0);
    }
    ch=fgetc(fp3);
    printf("开始加密miwen3.txt文件中字符%c",ch);
    do
    {
        K=ch-'a';
        T[K]++;
        ch=fgetc(fp3);
        printf("%c",ch);
    }while(ch!=EOF);
    fclose(fp3);
    total=0;
    for(i=0;i<26;i++)
    {
        total=total+T[i];
    }
    for(i=0;i<26;i++)
    {
        ch='a'+i;
        printf("%c字符频率：%7.4f\n",ch,((float)T[i]/total)*100);
    }
    return 0;
}
