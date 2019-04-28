#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp3,*fp2;
    char ch,s;
    char T[27]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','\0'};
    int K,i;
    fp2=fopen("mingwen2.txt","r");
    if(fp2==NULL)
    {
        printf("mingwen2.txt打开失败\n");
        //exit(0);
    }
    fp3=fopen("miwen3.txt","w");
    if(fp3==NULL)
    {
        printf("miwen3.txt打开失败！\n");
    }
    ch=fgetc(fp2);
    printf("开始加密mingwen2.txt文件中字符%c",ch);
    do
    {
        K=ch-'a';
        s=T[K];
        fputc(s,fp3);
        ch=fgetc(fp2);
        printf("%c",ch);
    }while(ch!=EOF);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
