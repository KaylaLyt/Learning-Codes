#include<stdio.h>
int main()
{
    unsigned char str[]="我是中国人\0";
    int i;
    for(i=0;i<sizeof(str);i++)
        printf("%03u  ",str[i]);
    return 0;
}
