#ifndef __HASH__H__
#define __HASH__H__

typedef struct set set_t;

struct set
{
  int key;      // مفتاح
  int data;     // قيمة
  set_t *next;  // مؤشر التالي
};


void init_array(set_t **array, int *size);

void insert(set_t **arr, int key, int data, int size);

void print_ht(set_t *arr, int size);

int hash_func(int key, int size);

#endif
