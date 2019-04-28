#ifndef __MALLOC_H
#define __MALLOC_H

//#define malloc_addr 0x20000000
//#define malloc_size 0x100000
#define NULL 0

//每申请一个内存空间，无论大小（char、short、long）都将其命名为"Block"。通过Block的头部控制块将堆区连成一个链表，通过这个链表可以遍历整个堆区的每一个块。
//　is_avilable标记内存块是否被分配，是否可用。prior_blocksize保存了前一个块的大小，current_blocksize保存了当前块的实际有效数据空间大小。
//有了current_blocksize，我们可以从前向后遍历整个堆区；而有了prior_blocksize，我们可以从后向前遍历整个堆区。
//这个控制块头部使我们为堆区建立了一个双向链表，以便于管理。
typedef struct{
unsigned char is_available;			/* whether blcok is avaiable */
unsigned int prior_blocksize;       /* size of prior block */
unsigned int current_blocksize;     /* block size */
}mem_control_block;

//#define malloc_init()	Rewrite_malloc_init()
//#define malloc(x)		Rewrite_malloc(x)
//#define free(x)			Rewrite_free(x)



void malloc_init(void);
/*
初始化函数，主要是确定堆区的起始位置、大小和结束地址，也就是确定堆区的边界。我们申请的内存块必须在堆区内，不得超出边界，否则会修改其他的数据。

　　另外，还需要对堆区进行初始化，建立第一个内存块（初始化头部控制结构体）。
    显然，这个块是一个完整的块，也是一次能分配最大内存空间的块。之所以进行初始化，原因还是没有头部控制结构体的块无法进行管理。
*/

void * malloc(unsigned int numbytes);
/*
调用malloc函数时，它沿连接表从前向后，寻找一个没有被占用的，而且大到足以满足用户请求所需要的内存块。在寻找过程中，分三种情况。

　　第一种情况，倘若可用而且大小刚好合适，那么直接将此块返回就完成了分配。

　　第二种情况，倘若可用而且超过了所需要的内存块并且还能容纳一个新块的控制头部，这个时候就将此块一分为二。
    将分配给用户的那块内存的is_available置0（不再可用），然后将此块的有效数据区首地址作为函数值返回。
    而新块的控制头部要进行赋值（只有含有头部的块才能称的上一个块），没有控制头部的块不能进行管理。

  　第三种情况，倘若可用内存块的空间小于需要的空间，或者虽然超过了但是不能腾出一个控制头部，最终的处理都是跳过改块，移动到链表的下一块进行新一轮的比较。
  */

void free(void *firstbyte);
/*
free函数用于内存块的回收，当不用的内存块调用此函数释放空间的时候，将is_available置1（可以重新分配）。
接下来要做的就是整合内存碎片。由于可能多次malloc函数，产生了很多的内存碎片，在释放一个块的时候，不仅要标记此块为“可用”。
另外，还需要试着将此块前后的块进行合并，这样才能为将来申请更大的空间做好准备。
*/


#endif
