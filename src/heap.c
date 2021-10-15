/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/heap.h"

void init_heap(Heap *h){
    h->index = 0;
    for (int i = 0; i < HEAP_MAX_SIZE ; i++)
    {
        h->data[i] = 0.0;     
    }
}

bool is_heap_empty(Heap *h){
    return h->index == 0;
}

float pop_heap(Heap *h){
    return 0.0; //////
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
void clear_heap(Heap *h){

}