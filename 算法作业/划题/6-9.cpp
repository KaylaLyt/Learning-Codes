#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 50;
int num[MAX];  //输入的数
int flag[MAX];  //是否已经用过
int oper[MAX];  //1--'+', 2--'-', 3--'*', 4--'/'
int n, m;
int p[MAX];  //临时数组
int bestp[MAX];  //最优数组
int bestop[MAX]; //最优操作符
char op[] = {' ', '+', '-', '*', '/'};
int k;  //搜索深度逐渐加深

bool found()
{
    int result = p[1];
    for(int i=1; i<=k; i++)  //计算式子的结果
    {
        switch(oper[i])
        {
        case 1:
            result += p[i+1];
            break;
        case 2:
            result -= p[i+1];
            break;
        case 3:
            result *= p[i+1];
            break;
        case 4:
            result /= p[i+1];
            break;
        }
    }

    return result == m;
}

bool backtrack(int dep)
{
    if(dep > k+1)  //深度逐渐加深
    {
        if(found())
        {
            copy(p, p+n+1, bestp);
            copy(oper, oper+n+1, bestop);
            return true;
        }
        else
            return false;
    }

    for(int j=1; j<=n; j++) //可选的数字
    {
        if(flag[j] > 0)
            continue;
        p[dep] = num[j];
        flag[j] = 1;
        for(int i=1; i<=4; i++) //可选的操作符
        {
            oper[dep] = i;
            if(backtrack(dep+1))
                return true;
            oper[dep] = 0;
        }
        flag[j] = 0;
        p[dep] = 0;
    }
    return false;
}

int main()
{
    ifstream fin("无优先级运算.txt");
    cout << "输入整数个数：";
    fin >> n;   cout << n << endl;
    cout << "输入目标数：";
    fin >> m;   cout << m << endl;
    cout << "输入各整数：\n";
    for(int i=1; i<=n; i++)
    {
        fin >> num[i];
        cout << num[i] << " ";
    }
    memset(flag, 0, sizeof(flag));
    memset(p, 0, sizeof(p));

    for(k=0; k<n; k++)
        if(backtrack(0))
        {
            cout << "\n最少无优先级运算次数为：" << k << endl;
            cout << "最优无优先级运算表达式为：" << endl;
            for(i=1; i<=k; i++)
                cout << bestp[i] << op[bestop[i]];
            cout << bestp[k+1];
            break;
        }
    cout << endl;
    cout << endl;
    fin.close();
    return 0;
}


