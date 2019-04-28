//http://www.cnblogs.com/amanlikethis/p/3765908.html
#include "malloc.h"
#include <stdio.h>
#include <string.h>

#define HEAPSIZE	500
extern unsigned char heap[HEAPSIZE];

/**
  * @brief Test malloc function
  * @param None
  * @retval int
  */

/*
函数所在头文件：<stdlib.h>

函数原型是：void *malloc (size_t n)

函数功能：在内存的动态存储区中分配一个长度为size的连续空间。其参数是一个无符号整形数，返回值是一个指向所分配的连续存储域的起始地址的指针。
*/
/*
malloc函数使用注意事项

    申请了内存空间后，必须检查是否分配成功。
    当不需要再使用申请的内存时，记得释放；释放后应该把指向这块内存的指针指向NULL，防止程序后面不小心使用了它。
    malloc和free函数应该配对使用。如果申请后不释放，就是内存泄露；如果无故释放那就是什么也没有做。释放只能一次，如果释放两次及两次以上会出现错误。
    越界使用动态分配的存储块，尤其是越界赋值，可能引起非常严重的后果，通常会破坏程序的运行系统，可能造成本程序或者整个计算机系统垮台。

*/
int main(void)
{
	int * p1;
	int * p2;
	int * p3;
	int * p4;

	memset((void *)heap,0,HEAPSIZE);
	malloc_init();
	p1 = (int *)malloc(sizeof(int));
	if(p1 == NULL){
		printf("malloc failed!\n");
	}
	*p1 = 60;
	printf("p1 = %d\n",*p1);

	p2 = (int *)malloc(20);
	if(p2 == NULL){
		printf("malloc failed!\n");
	}
	*p2 = 70;
	printf("p2 = %d\n",*p2);

	p3 = (int *)malloc(sizeof(int));
	if(p3 == NULL){
		printf("malloc failed!\n");
	}
	*p3 = 80;
	printf("p3 = %d\n",*p3);

	free((void *)p2 );

	p4 = (int *)malloc(sizeof(int));
	if(p4 == NULL){
		printf("malloc failed!\n");
	}else{
		*p4 = 90;
		printf("p4 = %d\n",*p4);
	}

	free((void *)p1);
	free((void *)p3);
	free((void *)p4);

	while(1);
	return 0;
}
