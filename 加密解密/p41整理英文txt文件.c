#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp1,*fp2;
    char ch;
    fp1=fopen("mingwen1.txt","r");
    if(fp1==NULL)
    {
        printf("mingwen1.txt打开失败！\n");
        exit(0);
    }
    fp2=fopen("mingwen2.txt","w");
    if(fp2==NULL)
    {
        printf("mingwen2.txt打开失败！\n");
        exit(0);
    }
    ch=fgetc(fp1);
    printf("开始整理文件%c",ch);
    while(ch!=EOF)
    {
        if(ch>='A'&&ch<='Z')
        {
            ch=ch+32;
        }
        if(ch>='a'&&ch<='z')
        {
            fputc(ch,fp2);
        }
        ch=fgetc(fp1);
        printf("%c",ch);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;

}
