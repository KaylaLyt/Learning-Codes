#include <stdio.h>
#include <string.h>

//思路：暴力枚举法
char flag[10];    //用于标记"#123456789"是否已经被选
char backup[10];  //用于临时保存数据

//检查"#123456789"每个数据是否只有一个
int check(int n)
{
	do
  	{
  		++flag[n%10];  //统计数字：如n = 123;则++flag[3],++flag[2],++flag[1]
  	}while(n /= 10);
  	if(flag[0] != 0) //如果存在0
    	return 1;      //返回冲突
  	for(int i = 1; i < 10; i++)
    	if(flag[i] > 1)//如果存在某个数据不只有1个
      		return 1;    //返回冲突
  	return 0;        //返回正确
}

//检查是否每个数据都已经存在
int checkAll(void)
{
	for(int i = 1; i < 10; i++)
    	if(flag[i] != 1)
      		return 1;//不全部包括
  	return 0;    //全部包括
}

int main(void)
{
	int i = 0;
    int num = 0;        //输入数据
    int count = 0;      //统计个数
    scanf("%d", &num);
    int left = 0, up = 0, down = 0;   //带分数
    for(left = 1; left < num; ++left) //先从带分数的左边开始增加
    {
  		for (i = 0; i < 10; ++i)        //将标记数组全部初始化为0
	  	flag[i] = 0;
    	if(check(left))                 //检查左边数据合理性
      		continue;//不合理
		for (i = 0; i < 10; ++i)        //缓存flag数据，用于下面for循环重置
			backup[i] = flag[i];
   		for(down = 1; down < 100000; ++down) //再增加带分数底数
		{
      		for (i = 0; i < 10; ++i)      //重置flag
				flag[i] = backup[i];
      		up = (num - left) * down;     //计算出up值
      		if(check(down) || check(up))  //检查数据合理性
        		continue;//不合理
      		if(!checkAll())
	  		{
        	//	printf("%d = %d + %d / %d\n", num, left, up, down);
        		++count; //计数+1
      		}
    	}
  	}
  	printf("%d\n", count);//打印总共个数
        return 0;
}
