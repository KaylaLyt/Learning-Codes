#include <iostream>
#include<math.h>
using namespace std;

void sortChildList(int* childList1,int* childList2)
{


}
int* sortIntList(int* silceIntList,int listLength)
{
//cout << listLength << endl;
    if (listLength == 2)
    {
        if (silceIntList[0] > silceIntList[1])
        {
            int temp = silceIntList[0];
            silceIntList[0] = silceIntList[1];
            silceIntList[1] = temp;
        }
        return silceIntList;
    }
    else if (listLength == 1)
    {
        return silceIntList;
    }
    else if (listLength == 3)
    {
        int temp;
        if (silceIntList[0] > silceIntList[1])
        {
            temp = silceIntList[0];
            silceIntList[0] = silceIntList[1];
            silceIntList[1] = temp;
        }
        if (silceIntList[0] > silceIntList[2])
        {
            temp = silceIntList[0];
            silceIntList[0] = silceIntList[2];
            silceIntList[2] = temp;
        }
        if (silceIntList[1] > silceIntList[2])
        {
            temp = silceIntList[1];
            silceIntList[1] = silceIntList[2];
            silceIntList[2] = temp;
        }
        return silceIntList;
    }
    else
    {
        int silceNum =(int)sqrt(listLength);
        int silceLength = listLength / silceNum;
        int addListNum = listLength - silceLength*silceNum;//需要补给最后一列的数量

        for (int i = 0; i < silceNum-1; i++)
        {
            int* temp = new int[silceLength];
            for (int j = 0; j < silceLength; j++)
            {
                temp[j] = silceIntList[i*silceLength + j];
            }
            sortIntList(temp,silceLength);
            for (int j = 0; j < silceLength; j++)
            {
                silceIntList[i*silceLength + j] = temp[j];
            }
            delete[] temp;
        }
//开始处理最后一组
        int lastLength = silceLength + addListNum;
        int* temp = new int[lastLength];
        for (int i = 0; i < lastLength; i++)
        {
            temp[i] = silceIntList[silceLength*(silceNum - 1) + i];
        }
        sortIntList(temp,lastLength);
        for (int i = 0; i < lastLength; i++)
        {
            silceIntList[silceLength*(silceNum - 1) + i] = temp[i];
        }
        delete[] temp;


        int* numList = new int[silceNum];
        for (int i = 0; i < silceNum; i++)
        {
            numList[i] = silceLength;
        }
        numList[silceNum - 1] = lastLength;
        int* indexList = new int[silceNum];
        for (int i = 0; i < silceNum; i++)
        {
            indexList[i] = 0;
        }
        int* tempList = new int[listLength];

        for (int i = 0; i < listLength; i++)
        {
            int min =100;
            int index = 0;
            for (int j = 0; j < silceNum; j++)
            {
                if (indexList[j] < numList[j])
                {
                    if (silceIntList[silceLength*j + indexList[j]] < min)
                    {
                        min = silceIntList[silceLength*j + indexList[j]];
                        index = j;
                    }
                }
            }
            tempList[i] = min;
            indexList[index]++;
        }


        for (int k = 0; k < listLength; k++)
        {
            silceIntList[k] = tempList[k];
        }
        delete[] indexList;
        delete[] numList;
        delete[] tempList;
        return silceIntList;
    }
}


int main()
{
    int testList[10] = { 1, 3, 5, 2, 0, 6, 4, 9, 7, 8 };
    sortIntList(testList,10);
    for (int i = 0; i < 10; i++)
    {
        cout << testList[i] << " ";
    }
    return 0;
}
