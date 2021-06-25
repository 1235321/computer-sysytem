#include <bits/stdc++.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

struct block_meta {
  size_t size;  //块大小
  block_meta *next;  //下一个块
  int free;  //是否是空闲块
};

class MyMalloc
{
public:
    MyMalloc();
    //virtual ~MyMalloc();

    block_meta *block;

    void *my_malloc(size_t size);
    void my_free(void *ptr);
    void *my_realloc(void *ptr, size_t size);
private:

};

#define META_SIZE sizeof(struct block_meta)
