/**
 * @file heap.h
 * @author Kubilay KAPLAN & Emile METRAL
 * @brief 
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdbool.h>


#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>
#include <stdio.h>

#define HEAP_MAX_SIZE 100

typedef struct {
    float data[HEAP_MAX_SIZE];
    int index;
} Heap;


#endif /* HEAP_H */

void init_heap(Heap *h);
bool is_heap_empty(Heap *h);
float pop_heap(Heap *h); //pop the root value
void push_heap(Heap *h, float value);
float replace(Heap *h, float value); // pop root and push a new key.
float peek_heap(Heap *h); // return root value but dont remove it
void clear_heap(Heap *h);
//En option
void heapify(Heap *s, float array[], size_t array_size); //create Heap from array
void merge(Heap *dest, Heap *src); //merge src into dest

