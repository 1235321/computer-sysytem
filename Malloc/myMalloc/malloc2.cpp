#include "malloc2.h"
void *global_base = NULL;

MyMalloc::MyMalloc()
{

}

block_meta *find_free_block(block_meta **last, size_t size)
{
    block_meta *current = (block_meta *)global_base;
    //printf("aaaaaaa:%d", current);
    while (current && !(current->free && current->size >= size))
    {
        *last = current;
        current = current->next;
    }
    return current;
}

block_meta *request_space(block_meta* last, size_t size)
{
    block_meta *block;
    block = (block_meta *)sbrk(0);
    void *request = sbrk(size + META_SIZE);
    assert((void*)block == request);
    if (request == (void*) -1)
    {
        return NULL; // sbrk failed.
    }

    if (last)   // NULL on first request.
    {
        last->next = block;
    }

    block->next = NULL;
    block->size = size;
    block->free = 0;

    return block;
}

void *MyMalloc::my_malloc(size_t size)
{
    block_meta *block;

    if (size <= 0)
    {
        return NULL;
    }

    if (!global_base)
    {
        // First call.
        block = request_space(NULL, size);
        if (!block)
        {
            return NULL;
        }
        global_base = block;
    }
    else
    {
        block_meta *last = (block_meta *)global_base;
        block = find_free_block(&last, size);
        if (!block)
        {
            // Failed to find free block.
            block = request_space(last, size);
            if (!block)
            {
                return NULL;
            }
        }
        else
        {
            // Found free block
            block_meta * next_block = block -> next;
            if((block->size - size) > META_SIZE)
            {
                /*split*/
                next_block = (block_meta*)((char*)block + META_SIZE + size);
                next_block -> free = 1;
                next_block -> next = block -> next;
                next_block -> size = (block -> size) - size - META_SIZE;
            }
            block->size = size;
            block->next = next_block;
            block->free = 0;
        }
    }

    return(block+1);
}

block_meta *get_block_ptr(void *ptr)
{
    return (block_meta*)ptr - 1;
}

void MyMalloc::my_free(void *ptr)
{
    if (!ptr)
    {
        return;
    }


    block_meta* block_ptr = get_block_ptr(ptr);
    block_meta* next_ptr = block_ptr->next;

    assert(block_ptr->free == 0);

    /*MERGE*/
    int add_size = 0;
    while(next_ptr&&next_ptr->free==1)
    {
        add_size += (META_SIZE+next_ptr->size);
    }
    block_ptr->free = 1;
    block_ptr->next = next_ptr;
    block_ptr->size = block_ptr->size + add_size;
}

void *MyMalloc::my_realloc(void *ptr, size_t size)
{
    if (!ptr)
    {
        // NULL ptr. realloc should act like malloc.
        return my_malloc(size);
    }

    block_meta* block_ptr = get_block_ptr(ptr);
    if (block_ptr->size >= size)
    {
        // We have enough space. Could free some once we implement split.
        return ptr;
    }

    // Need to really realloc. Malloc new space and free old space.
    // Then copy old data to new space.
    void *new_ptr;
    new_ptr = my_malloc(size);
    if (!new_ptr)
    {
        return NULL;
    }
    memcpy(new_ptr, ptr, block_ptr->size);
    my_free(ptr);
    return new_ptr;
}
