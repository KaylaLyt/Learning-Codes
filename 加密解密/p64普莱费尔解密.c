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

void Decrypt(char *input ,char *output)
{
    int length=strlen(input);
    int i=0;
    int j=-1;
    int find;
    int ax,ay,bx,by;
    int pair[2]={-1,-1};
    while(1)
    {
        char between[100]={0};
        int betweenlength=-1;
        find=0;
        for(i=pair[1]+1;i<length;i++)
        {
            pair[0]=i;
            pair[1]=i+1;
            find=1;
            break;
        }
        if(find==0)
        {
            break;
        }
        find=0;
        for(i=pair[1];i<length;i++)
        {
            pair[1]=i;
            find=1;
            break;
        }
        if(find==0)
        {
            input[length]='x';
            pair[1]=length;
            length++;
        }
        GetPosition(input[pair[0]],&ax,&ay);
        GetPosition(input[pair[1]],&bx,&by);
        if(ax==bx)
        {
            output[++j]=GetKey(ax,ay-1,input[pair[0]]);
            for(i=0;i<=betweenlength;i++)
            {
                output[++j]=between[i];
            }
            output[++j]=GetKey(bx,by-1,input[pair[1]]);
        }
        else if(ay==by)
        {
            output[++j]=GetKey(ax-1,ay,input[pair[0]]);
            for(i=0;i<=betweenlength;i++)
            {
                output[++j]=between[i];
            }
            output[++j]=GetKey(bx-1,by,input[pair[1]]);
        }
        else
        {
            output[++j]=GetKey(ax,by,input[pair[0]]);
            for(i=0;i<=betweenlength;i++)
            {
                output[++j]=between[i];
            }
            output[++j]=GetKey(bx,ay,input[pair[1]]);
        }
    }
    for(i=1;output[i]!='\0';i++)
    {
        if(output[i]=='x')
        {
            int m=0,s=-1,e=-1;
            for(m=i-1;m>=0;m--)
            {
                if(output[m]>='a'&&output[m]<='z')
                {
                    s=m;
                    break;
                }
            }
            for(m=i+1;output[m]!='\0';m++)
            {
                if(output[m]>='a'&&output[m]<='z')
                {
                    e=m;
                    break;
                }
            }
            if(s!=-1&&e!=-1&&(output[s]==output[e]||output[s]-output[e]=='A'-'a'||output[s]-output[e]=='a'-'A'))
            {
                for(m=i;output[m]!='\0';m++)
                {
                    output[m]=output[m+1];
                }
            }
        }
    }
    if(output[i-1]=='x')
    {
        output[i-1]='\0';
    }
}

int main()
{
    char key[26]={0},c;
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
    printf("请输入密文：");
    scanf("%s",inputstr);
    Decrypt(inputstr,outputstr);
    printf("明文：%s\n",outputstr);
    return 0;
}








