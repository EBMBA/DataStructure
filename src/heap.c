/**
 * @file heap.c
 * @author Kubilay KAPLAN & Emile METRAL
 * @brief functions for heap
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/heap.h"

/**
 * @brief initialize a new heap
 * 
 * @param h  Heap address to initialized
 */
void init_heap(Heap *h){
    h->index = 0;
    
    for (int i = 0; i < HEAP_MAX_SIZE ; i++)
    {
        h->data[i] = 0.0;     
    }
}

/**
 * @brief test if heap is empty or not
 * 
 * @param h Heap address to be treated
 * @return heap is empty
 * @return heap is not empty
 */
bool is_heap_empty(Heap *h){
    return h->index == 0;
}


/**
 * @brief Get the Parent Index 
 * 
 * @param childIndex 
 * @return int 
 */
int getParentIndex(int childIndex){
    return (childIndex - 1) / 2;
}

/**
 * @brief Get the Left Child Index 
 * 
 * @param parentIndex 
 * @return int 
 */
int getLeftChildIndex(int parentIndex){
    return 2 * parentIndex +1;
}

/**
 * @brief Get the Right Child Index 
 * 
 * @param parentIndex 
 * @return int 
 */
int getRightChildIndex(int parentIndex){
    return 2 * parentIndex + 2;
}

/**
 * @brief Swap two values ​​in the heap
 * 
 * @param h Table
 * @param index1 Value to be exchanged
 * @param index2 Value to be exchanged
 */
void swap_heap(Heap *h, int index1, int index2){
    float temp = h->data[index1];
    h->data[index1] = h->data[index2];
    h->data[index2] = temp;
}

/**
 * @brief Rearrange starting from the end
 * 
 * @param h Heap adressto be treated
 */
void heapifyUp(Heap *h){
    int index = h->index - 1;

    while(  getParentIndex(index) >= 0 && h->data[getParentIndex(index)] > h->data[index] ){
        swap_heap(h,getParentIndex(index),index);
        index = getParentIndex(index);
    }
}

/**
 * @brief Reorganized from the beginning
 * 
 * @param h Heap adress to be treated
 */
void heapifyDown(Heap *h){
    int index  = 0;

    while (getLeftChildIndex(index) < h->index)
    {
        int smallerChildIndex = getLeftChildIndex(index);
        int rightChildIndex = getRightChildIndex(index);
        int leftChildIndex = getLeftChildIndex(index);

        if ( rightChildIndex < h->index && h->data[rightChildIndex] < h->data[leftChildIndex])
        {
            smallerChildIndex = rightChildIndex;
        }

        if (h->data[index] < h->data[smallerChildIndex])
        {
           break;
        }
        else{
            swap_heap(h, index, smallerChildIndex);
        }

        index = smallerChildIndex;
    }
    
}

/**
 * @brief remove the first element
 * 
 * @param h Heap adress to be treated
 * @return float : element deleted
 */
float pop_heap(Heap *h){
    float items = 0.0;
    if (is_heap_empty(h))
    {
        printf("Error : heap is empty \n");
    }
    else{
        items = h->data[0];
        // printf(" %d in function %f \n",h->index, items);
        int index = (h->index)-1 ;
        // printf(" %d in function index -1\n",index);
        h->data[0] = h->data[index] ;
        // printf(" %d in function %f \n",h->index, h->data[0]);
        h->index --;
        // printf(" %d in function %f \n",h->index, h->data[0]);
        heapifyDown(h);
    }

    return items; 
}

/**
 * @brief add value
 * 
 * @param h Heap adress to be treated
 * @param value value to be added to the heap
 */
void push_heap(Heap *h, float value){
    int index = h->index;
    h->data[index] = value;
    //printf(" %d in function %f ",h->index, h->data[h->index]);
    h->index++;
    heapifyUp(h);
}

/**
 * @brief return the first value of a heap and replace it by a new value
 * 
 * @param h Heap adress to be treated
 * @param value replaced value
 * @return float 
 */
float replace(Heap *h, float value){
    float itemsRemoved = pop_heap(h);
    push_heap(h,value);
    return itemsRemoved;
}

/**
 * @brief return the first value of heap
 * 
 * @param h Heap adress to be treated
 * @return float 
 */
float peek_heap(Heap *h){
    return  h->data[0] ;
}

/**
 * @brief clear heap
 * 
 * @param h Heap adress to be treated
 */
void clear_heap(Heap *h){
    init_heap(h);
}

/**
void heapify(Heap *s, float array[], size_t array_size){
    int j = 2*noeud;
    while (j <= longueur)
    {
        if ((j < longueur) && (tableauATamiser[j] < tableauATamiser[j+1]))
        {
            j++;
        }
        else if (tableauATamiser[noeud] < tableauATamiser[j])
        {
            float temp = tableauATamiser[noeud];
            tableauATamiser[noeud] = tableauATamiser[j];
            tableauATamiser[j] = temp;
            noeud = j;
            j = 2*noeud;
        }
        else {
            j = longueur+1;
        }         
    }
}
*/