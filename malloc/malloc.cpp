#include "malloc.h"

static unsigned char has_initialized;
static unsigned int managed_memory_start;
static unsigned int managed_memory_end;
static unsigned int managed_memory_size;

/* heap buffer size 堆缓冲区大小*/
#define HEAPSIZE	500

/* heap start addrress 堆起始地址*/
#define malloc_addr heap
/* heap size 堆内存*/
#define malloc_size HEAPSIZE

/* heap buffer 堆缓冲*/
unsigned char heap[HEAPSIZE];

/**
  * @brief Initializes malloc's gloabl varialbe and head of heap memory
  * @param None
  * @retval None
  */
void malloc_init(void)
{
	mem_control_block * mcb = NULL;

	/* confirm heap's start address
	确认堆的开始地址*/
	managed_memory_start = (unsigned int)malloc_addr;
	/* confirm heap's size
	确定堆的大小*/
	managed_memory_size = malloc_size;
	/*confirm heap's end address
	确认堆的结束地址*/
	managed_memory_end = managed_memory_start + managed_memory_size;

	/* make mcb point to heap's start address
	使mcb指向堆的开始地址*/
	mcb = (mem_control_block *)managed_memory_start;
	/*the first blcok is avaialbe
	第一个块可用*/
	mcb->is_available = 1;
	/*there is no block before the first block
	在第一个块之前没有块 */
	mcb->prior_blocksize = 0;
	/*the first block's block size is difference of between heap's size and control block
      第一个块的块大小是堆大小和控制块之间的差异*/
	mcb->current_blocksize = managed_memory_size - sizeof(mem_control_block);
	/* Initialize done */
	has_initialized = 1;
}

/**
  * @brief Dynamic distribute memory function
  * @param numbytes: what size you need
  * @retval a void pointer to the distribute first address
  */
void * malloc(unsigned int numbytes)
{
	unsigned int current_location,otherbck_location;
	/* This is the same as current_location, but cast to a memory_control_block
	这与current_location相同，但是强制转换为memory_control_block*/
	mem_control_block * current_location_mcb = NULL,* other_location_mcb = NULL;
	/* varialbe for saving return value and be set to 0 until we find something suitable
	用于保存返回值的变量，并设置为0，直到找到合适的值*/
	void * memory_location = NULL;
	/* current dividing block size
	分割块大小*/
	unsigned int process_blocksize;

	/* Initialize if we haven't already done so
	如果尚未初始化，则初始化*/
	if(! has_initialized) {
		malloc_init();
	}

	/* Begin searching at the start of managed memory
	在托管内存开始时开始搜索*/
	current_location = managed_memory_start;
	/* Keep going until we have searched all allocated space
    继续下去，直到我们搜索了所有分配的空间 */
	while(current_location != managed_memory_end){
		/* current_location and current_location_mcb point to the same address.  However,
		 * current_location_mcb is of the correct type, so we can use it as a struct. current_location
		 * is a void pointer so we can use it to calculate addresses.
		 current_location和current_location_mcb指向同一地址。
		 但是，current_location_mcb的类型正确，因此我们可以将它用作结构。
		 current_location是一个void指针，因此我们可以用它来计算地址。
		 */
		current_location_mcb = (mem_control_block *)current_location;
		/* judge whether current block is avaiable
		判断当前块是否可用*/
		if(current_location_mcb->is_available){
			/* judge whether current block size exactly fit for the need
			判断当前块大小是否完全符合需要*/
			if((current_location_mcb->current_blocksize == numbytes)){
				/* It is no longer available
				它不再可用了*/
				current_location_mcb->is_available = 0;
			    /* We own it
			    我们拥有它*/
				memory_location = (void *)(current_location + sizeof(mem_control_block));
				/* Leave the loop
				离开循环*/
				break;
			/* judge whether current block size is enough for dividing a new block
			判断当前块大小是否足以分割新块*/
			}else if(current_location_mcb->current_blocksize >= numbytes + sizeof(mem_control_block)){
				/* It is no longer available
				它已不再可用*/
				current_location_mcb->is_available = 0;
				/* because we will divide current blcok,before we changed current block size,we should
				 * save the integral size.
				 因为我们将划分当前块，在我们改变当前块大小之前，我们应该保存整数大小。*/
				process_blocksize = current_location_mcb->current_blocksize;
				/* Now blcok size could be changed
				现在可以更改块大小*/
				current_location_mcb->current_blocksize = numbytes;

				/* find the memory_control_block's head of remaining block and set parameter,block of no
				 * parameter can't be managed.
				 找到memory_control_block的剩余块头和设置参数，无法管理无参数块。*/
				other_location_mcb = (mem_control_block *)(current_location + numbytes \
												+ sizeof(mem_control_block));
				/* the remaining block is still avaiable
				剩余的块仍然可用*/
				other_location_mcb->is_available = 1;
				/* of course,its prior block size is numbytes
				当然，它的先前块大小是numbytes*/
				other_location_mcb->prior_blocksize = numbytes;
				/* its size should get small
				它的大小应该变小*/
				other_location_mcb->current_blocksize = process_blocksize - numbytes \
												- sizeof(mem_control_block);

				/* find the memory_control_block's head of block after current block and \
				 * set parameter--prior_blocksize.
				 在当前块和* set参数 - prior_blocksize之后找到memory_control_block的块头。*/
				otherbck_location = current_location + process_blocksize \
											+ sizeof(mem_control_block);
				/* We need check wehter this block is on the edge of managed memeory!
				我们需要检查这个块是否位于托管内存的边缘！*/
				if(otherbck_location != managed_memory_end){
					other_location_mcb = (mem_control_block *)(otherbck_location);
					/*  its prior block size has changed!
					它以前的块大小已经改变*/
					other_location_mcb->prior_blocksize = process_blocksize\
						- numbytes - sizeof(mem_control_block);
				}
				/*We own the occupied block ,not remaining block
				我们拥有被占用的块，而不是剩余块*/
				memory_location = (void *)(current_location + sizeof(mem_control_block));
				/* Leave the loop
				离开循环*/
				break;
			}
		}
		/* current block is unavaiable or block size is too small and move to next block
		当前块不可用或块大小太小并移动到下一个块*/
		current_location += current_location_mcb->current_blocksize \
									+ sizeof(mem_control_block);
	}
	/* if we still don't have a valid location,we'll have to return NULL
	如果我们仍然没有有效的位置，我们将不得不返回NULL*/
	if(memory_location == NULL)	{
		return NULL;
	}
	/* return the pointer
	返回指针*/
	return memory_location;
}

/**
  * @brief  free your unused block
  * @param  firstbyte: a pointer to first address of your unused block
  * @retval None
  */
//释放一个已分配的数据块，只是对此数据块以及其前后数据块的控制块头部进行调整，并没有对实际有效数据区域（用户可见的区域）进行初始化操作，也就是说数据区域中的数据保持不变。
void free(void *firstbyte)
{
	unsigned int current_location,otherbck_location;
	mem_control_block * current_mcb = NULL,* next_mcb = NULL,* prior_mcb \
								= NULL,* other_mcb = NULL;
	/* Backup from the given pointer to find the current block
	从给定指针备份以查找当前块*/
	current_location = (unsigned int)firstbyte - sizeof(mem_control_block);
	current_mcb = (mem_control_block *)current_location;
	/* Mark the block as being avaiable
	将块标记为可用*/
	current_mcb->is_available = 1;

	/* find next block location
	找到下一个块位置*/
	otherbck_location = current_location + sizeof(mem_control_block) \
									+ current_mcb->current_blocksize;
	/* We need check wehter this block is on the edge of managed memeory!
	我们需要检查这个块是否位于托管内存的边缘！*/
	if(otherbck_location != managed_memory_end){
		/* point to next block
		指向下一个块*/
		next_mcb = (mem_control_block *)otherbck_location;
		/* We need check whether its next block is avaiable
		我们需要检查它的下一个块是否可用*/
		if(next_mcb->is_available){
			/* Because its next block is also avaiable,we should merge blocks
			因为它的下一个块也是可用的，我们应该合并块*/
			current_mcb->current_blocksize = current_mcb->current_blocksize \
				+ sizeof(mem_control_block) + next_mcb->current_blocksize;

			/* We have merge two blocks,so we need change prior_blocksize of
			 * block after the two blocks,just find next block location.
			 我们合并了两个块，所以我们需要在两个块之后更改块的previous_blocksize，只需找到下一个块位置。*/
			otherbck_location = current_location + sizeof(mem_control_block) \
									+ current_mcb->current_blocksize;
			/* We need check wehter this block is on the edge of managed memeory!
			我们需要检查这个块是否位于托管内存的边缘！*/
			if(otherbck_location != managed_memory_end){
				other_mcb = (mem_control_block *)otherbck_location;
				/*  its prior block size has changed!
				它之前的块大小已经改变了！*/
				other_mcb->prior_blocksize = current_mcb->current_blocksize;
			}
		}
	}

	/* We need check wehter this block is on the edge of managed memeory!
	我们需要检查这个块是否位于托管内存的边缘！*/
	if(current_location != managed_memory_start){
		/* point to prior block
		指向前一个块*/
		prior_mcb = (mem_control_block *)(current_location - sizeof(mem_control_block)\
											- current_mcb->prior_blocksize);
		/* We need check whether its prior block is avaiable
		我们需要检查它的先前块是否可用*/
		if(prior_mcb->is_available){
			/* Because its prior block is also avaiable,we should merge blocks
			因为它的先前块也是可用的，所以我们应该合并块*/
			prior_mcb->current_blocksize = prior_mcb->current_blocksize \
				+ sizeof(mem_control_block) + current_mcb->current_blocksize;

			/* We have merge two blocks,so we need change prior_blocksize of
			 * block after the two blocks,just find next block location.
			 我们合并了两个块，所以我们需要在两个块之后更改块的previous_blocksize，只需找到下一个块位置。*/
			otherbck_location = current_location + sizeof(mem_control_block) \
									+ current_mcb->current_blocksize;
			/* We need check wehter this block is on the edge of managed memeory!
			我们需要检查这个块是否位于托管内存的边缘！*/
			if(otherbck_location != managed_memory_end){
				other_mcb = (mem_control_block *)otherbck_location;
				/*  its prior block size has changed!
				它之前的块大小已经改变了！*/
				other_mcb->prior_blocksize = prior_mcb->current_blocksize;
			}
		}
	}
}
