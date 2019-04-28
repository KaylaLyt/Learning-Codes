#include <iostream>

using namespace std;

int countAll = 0;

// 字符串匹配
bool Findsame(char list[], int k, int m){

    // list[m]是否有在list[k, m-1]出现过
    for (int i = k; i < m; i++) {
        if (list[m] == list[i]) {
            // 出现了
            return true;
        }
    }

    return false;
}


// 全排列，递归
void Perm(char list[], int k, int m){
    if (k == m) {
        // 输出排列
        for (int i = 0; i <= m; i++) {
            cout << list[i];
        }
        countAll++;// 排列数+1
        cout << endl;
    }else{

        for (int i = k; i <= m; i++) {
            if (Findsame(list, k, i)) {
                continue;//去除已出现过的排列
            }

            swap(list[k], list[i]);
            Perm(list, k + 1, m);// 递归
            swap(list[k], list[i]);
        }
    }
}


int main()
{
    int n;
    char list[20];

    cin >> n;
    cin >> list;

    Perm(list, 0, n - 1);
    cout << countAll;


    cout << endl;
    return 0;
}
