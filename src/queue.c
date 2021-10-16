/**
 * @file queue.c
 * @author Kubilay KAPLAN & Emile METRAL
 * @brief functions for queue
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/queue.h"

/**
 * @brief initialize a new queue
 * 
 * @param s : queue address to init
 */
void init_queue(Queue *s){
    s->index=0;
    for (int i = 0; i < QUEUE_MAX_SIZE ; i++)
    {
        s->data[i] = 0.0;     
    }
}

/**
 * @brief add value to queue
 * 
 * @param q queue address to be treated
 * @param value value to add
 */
void enqueue(Queue *q, float value){
    q->index = QUEUE_MAX_SIZE;
    for (int i = 0; i < QUEUE_MAX_SIZE ; i++)
    {
        if (q->data[i] == 0.0)
        {
            q->data[i] = value;
            
            break;
        }
    }
}

/**
 * @brief delete first value and return it
 * 
 * @param q queue address to be treated
 * @return float return deleted value
 */
float dequeue(Queue *q){
    float tampon = q->data[0];
    for (int i = 0; i < QUEUE_MAX_SIZE ; i++)
    {
        q->data[i] = q->data[i+1];
    }
    return tampon;
}

/**
 * @brief queue is empty or not
 * 
 * @param q queue address to be treated
 * @return true : queue is empty
 * @return false : queue is not empty
*/
bool is_queue_empty(Queue *q){
    return q->index == 0;
}

/**
 * @brief display the first queue value
 * 
 * @param q queue address to be treated
 * @return float 
 */
float front(Queue *q){
    float val = q->data[0];
    return val;
}

/**
 * @brief clear queue
 * 
 * @param q queue address to be treated
 */
void clear_queue(Queue *q){
    init_queue(q);
}