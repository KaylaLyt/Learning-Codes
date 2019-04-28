#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char playfair_table[5][5];
void CreateTable(char *in_key)
{
    int i=0,j;
    int hash[26]={0};
    char key[26]={0};
    int key_len;
    strcpy(key,in_key);
    key_len=strlen(key);

    while(i<key_len)
    {
        if(!(key[i]<='z'&&key[i]>='a'))
        {
            for(j=i;j<key_len-1;++j)
            {
                key[j]=key[j+1];
            }
            key_len--;
            continue;
        }
        if(hash[key[i]-'a']==0)
        {
            hash[key[i]-'a']=1;
        }
        else
        {
            for(j=i;j<key_len-1;++j)
            {
                key[j]=key[j+1];
            }
            key_len--;
            continue;
        }
        i++;
    }

    for(i=0;i<26;i++)
    {
        if(i+'a'=='z')
        {
            continue;
        }
        if(hash[i]==0)
        {
            hash[i]=1;
            key[key_len]=i+'a';
            key_len++;
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            playfair_table[i][j]=key[5*i+j];
        }
    }
}

void GetPosition(char c,int *x,int *y)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;++j)
        {
            if(playfair_table[i][j]==c)
            {
                *x=i;
                *y=j;
                return;
            }
        }
    }
}

char GetKey(int x,int y,char ch)
{
    return playfair_table[x%5][y%5];
}

void Encrypt(char *input ,char *output)
{
    int length=strlen(input);
    int i=0;
    int j=-1;
    int flag;
    int ax,ay,bx,by;
    int pair[2]={-1,-1};
    while(1)
    {
        char dis[100]={0};
        int dislength=-1;
        flag=0;
        for(i=pair[1]+1;i<length;i++)
        {
            pair[0]=i;
            pair[1]=i+1;
            flag=1;
            break;
        }
        if(flag==0)
        {
            break;
        }
        flag=0;
        for(i=pair[1];i<length;i++)
        {
            pair[1]=i;
            flag=1;
            break;
        }
        if(flag==0)
        {
            input[length]='x';
            pair[1]=length;
            length++;
        }
        if(input[pair[1]]==input[pair[0]])
        {
            if(input[pair[0]]!='x')
            {
                for(i=length;i>=pair[1];i--)
                {
                    input[i+1]=input[i];
                }
                length++;
                input[pair[1]]='x';
            }
        }
        printf("%c,%c\n",input[pair[0]],input[pair[1]]);
        GetPosition(input[pair[0]],&ax,&ay);
        GetPosition(input[pair[1]],&bx,&by);
        if(ax==bx)
        {
            output[++j]=GetKey(ax,ay+1,input[pair[0]]);
            for(i=0;i<=dislength;i++)
            {
                output[++j]=dis[i];
            }
            output[++j]=GetKey(bx,by+1,input[pair[1]]);
        }
        else if(ay==by)
        {
            output[++j]=GetKey(ax+1,ay,input[pair[0]]);
            for(i=0;i<=dislength;i++)
            {
                output[++j]=dis[i];
            }
            output[++j]=GetKey(bx+1,by,input[pair[1]]);
        }
        else
        {
            output[++j]=GetKey(ax,by,input[pair[0]]);
            for(i=0;i<=dislength;i++)
            {
                output[++j]=dis[i];
            }
            output[++j]=GetKey(bx,ay,input[pair[1]]);
        }
    }
}

int main()
{
    char key[26]={0};
    char inputstr[100],outputstr[100];
    memset(outputstr,0,sizeof(outputstr));
    memset(inputstr,0,sizeof(inputstr));
    printf("输入密钥");
    scanf("%s",key);
    CreateTable(key);
    int m,n;
    printf("密码表\n");
    for(m=0;m<5;++m)
    {
        printf("\t");
        for(n=0;n<5;++n)
        {
            printf("%c",playfair_table[m][n]);
        }
        printf("\n");
    }
    printf("请输入明文：");
    scanf("%s",inputstr);
    Encrypt(inputstr,outputstr);
    printf("密文：%s\n",outputstr);
    return 0;
}








