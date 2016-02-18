// WARNING: Requires C99 compatible compiler

//#include <unistd.h>
#include <stdlib.h>

#include "heap.h"
#include <os_mem.c>
#define CMP(a, b) ((a) <= (b))

static const unsigned int base_size = 12;

// Prepares the heap for use
void heap_init(struct heap *h)
{

	*h = (struct heap){
		.size = base_size,
		.count = 0,
		//.TASK = malloc(sizeof(struct task) * base_size) 
	};
	//if (!h->TASK) _exit(1); // Exit if the memory allocation fails
}

// Inserts element to the heap
void heap_push(struct heap *h, struct task *TASK)
{
	unsigned int index, parent;

	// Resize the heap if it is too small to hold all the data
	if (h->count == h->size)
	{
		h->size <<= 1;
		//h->TASK = realloc(h->TASK, sizeof(struct task) * h->size);
		//if (!h->TASK) _exit(1); // Exit if the memory allocation fails
	}

	// Find out where to put the element and put it
	for(index = h->count++; index; index = parent)
	{
		parent = (index - 1) >> 1;
	//	if CMP(h->data[parent], value) break;
		if CMP(h->TASK[parent]->data, TASK->data) break;
		h->TASK[index] = h->TASK[parent];
	}
	h->TASK[index] = TASK;
}

// Removes the biggest element from the heap
void heap_pop(struct heap *h)
{
	unsigned int index, swap, other;
	struct task *temp;
	// Remove the biggest element
	temp= h->TASK[--h->count];

	// Resize the heap if it's consuming too much memory
	if ((h->count <= (h->size >> 2)) && (h->size > base_size))
	{
		h->size >>= 1;
		//h->TASK = realloc(h->TASK, sizeof(struct task) * h->size);
		//if (!h->TASK) _exit(1); // Exit if the memory allocation fails
	}

	// Reorder the elements
	for(index = 0; 1; index = swap)
	{
		// Find the child to swap with
		swap = (index << 1) + 1;
		if (swap >= h->count) break; // If there are no children, the heap is reordered
		other = swap + 1;
		if ((other < h->count) && CMP(h->TASK[other]->data, h->TASK[swap]->data)) swap = other;
		if CMP(temp->data, h->TASK[swap]->data) break; // If the bigger child is less than or equal to its parent, the heap is reordered

		h->TASK[index] = h->TASK[swap];
	}
	h->TASK[index] = temp;
} 
/*
int heap_pop(struct heap *h)
{
	unsigned int index, swap, other,left,right;
	int min;
	struct task *temp;
	// Remove the biggest element
	min = h->TASK[0]->data;
	h->TASK[0]->data = h->TASK[0]->period + min ;
	
   
        for(index = 0; index*2 + 1 < h->count; index = swap)
   	{
		left = index*2 + 1;
		right = index*2 + 2;
	        if( right < h->count && h->TASK[right]->data < h->TASK[left]->data  )
		{
			swap = right;
		}
		else
		{
			swap = left;
		}
		if( h->TASK[swap]->data < h->TASK[index]->data )
		{
			temp = h->TASK[index];
			h->TASK[index] = h->TASK[swap];
			h->TASK[swap] = temp; 
		}
	}
	return min;
		
}
*/