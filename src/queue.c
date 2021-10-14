/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/queue.h"


void init_queue(Queue *s){
    s->index=0;
    for (int i = 0; i < QUEUE_MAX_SIZE ; i++)
    {
        s->data[i] = 0.0;     
    }
}

void enqueue(Queue *q, float value){

    for (int i = 0; i < QUEUE_MAX_SIZE ; i++)
    {
        if (q->data[i] == 0.0)
        {
            q->data[i] = value;
            q->index++;
            break;
        }
    }
}

float dequeue(Queue *q){
    float tampon = q->data[0];
    for (int i = 0; i < QUEUE_MAX_SIZE ; i++)
    {
        
        q->data[i] = q->data[i+1];
    }
    return tampon;
}

bool is_queue_empty(Queue *q){
    return q->index == 0;
}

float front(Queue *q){
    float val = q->data[0];
    return val;
}
void clear_queue(Queue *q){
    init_queue(q);
}