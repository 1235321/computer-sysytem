#include <bits/stdc++.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

struct block_meta {
  size_t size;  //���С
  block_meta *next;  //��һ����
  int free;  //�Ƿ��ǿ��п�
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
