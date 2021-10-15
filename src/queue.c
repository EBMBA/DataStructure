/**
 * @file queue.c
 * @author Kubilay KAPLAN & Emile METRAL
 * @brief 
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
 * @brief Init queue
 * 
 * @param s : queue to init
 */
void init_queue(Queue *s){
    s->index=0;
    for (int i = 0; i < QUEUE_MAX_SIZE ; i++)
    {
        s->data[i] = 0.0;     
    }
}

/**
 * @brief add value
 * 
 * @param q queue to use
 * @param value value to add
 */
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

/**
 * @brief delete first value and return it
 * 
 * @param q queue a retourner
 * @return float 
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
 * @brief si queue est vide ou pas
 * 
 * @param q queue a traiter
 * @return true 
 * @return false 
 */
bool is_queue_empty(Queue *q){
    return q->index == 0;
}

/**
 * @brief affiche la premiere valeur de queue
 * 
 * @param q queue a traiter
 * @return float 
 */
float front(Queue *q){
    float val = q->data[0];
    return val;
}

/**
 * @brief reinitialise queue
 * 
 * @param q queue a traiter
 */
void clear_queue(Queue *q){
    init_queue(q);
}