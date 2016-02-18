// WARNING: Requires C99 compatible compiler

typedef int type;

struct task{
	type data;
        type period;
	OS_TCB *p_tcb;
};

struct heap
{
	unsigned int size; // Size of the allocated memory (in number of items)
	unsigned int count; // Count of the elements in the heap
	struct task *TASK[50]; // Array with the elements
};

void heap_init(struct heap *h);
void heap_push(struct heap *h, struct task *TASK);
void heap_pop(struct heap *h);

// Returns the biggest element in the heap
#define heap_front(h) (*(h)->TASK)

// Frees the allocated memory
#define heap_term(h) (free((h)->TASK))

void heapify(type data[], unsigned int count);
