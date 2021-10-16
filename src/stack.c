/**
 * @file stack.c
 * @author Kubilay KAPLAN & Emile METRAL
 * @brief functions for stack
 * @version 0.1
 * @date 2021-10-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/stack.h"

/**
 * @brief initialize new stack
 * 
 * @param s Stack address to be treated
 */
void init_stack(Stack *s){
    s->index = 0;
    for (int i = 0; i < STACK_MAX_SIZE; i++)
    {
        s->data[i] = 0.0;
    }   
}

/**
 * @brief add a value to a stack
 * 
 * @param s Stack address to be treated
 * @param value value to be added to the stack 
 */
void push(Stack *s, float value){
    s->data[s->index] = value;
    s->index ++;
}

/**
 * @brief return and remove the last value of a stack
 * 
 * @param s Stack address to be treated
 * @return float Returns the deleted value
 */
float pop(Stack *s){
    float valRemove = 0.0;
    if (s->index > 0)
    {
        valRemove = s->data[s->index-1];
        s->data[s->index-1] = 0.0;
        s->index --;
    }
    else{
        printf("Stack is empty");
    }
    

    return valRemove;
}

/**
 * @brief test if a stack is empty or not
 * 
 * @param s Stack address to be treated
 * @return true  stack is empty 
 * @return false stack is not empty
 */
bool is_stack_empty(Stack *s){
    bool empty = true;
    
    if (s->index != 0)
    {
        empty = false;
    }

    return empty; 
}

/**
 * @brief return the last value of a stack
 * 
 * @param s Stack address to be treated
 * @return float last value of the stack 
 */
float peek(Stack *s){
    float lastElement = 0.0;
    if (s->index > 0)
    {
        lastElement = s->data[s->index-1];
    }    
    return lastElement;
}

/**
 * @brief Remove the last value 
 * 
 * @param s Stack address to be treated 
 */
void dump(Stack *s){
    if (s->index > 0)
    {
        s->data[s->index] = s->data[s->index-1];
        s->index ++; 
    }
    else{
        printf("stack empty\n");
    }
}

/**
 * @brief duplicate the last value of a stack 
 * @param s Stack address to be treated 
 */
void dup_stack(Stack *s){
    push(s,peek(s));
    s->index++;
}


/**
 * @brief swap the last value with the before-last value of a stack 
 * 
 * @param s Stack address to be treated 
 */
void swap(Stack *s){
    if (s->index > 0)
    {
        float tempVal = s->data[s->index-1];
        s->data[s->index-1] = s->data[s->index-2];
        s->data[s->index-2] = tempVal;
    }
}

/**
 * @brief clear Stack
 * 
 * @param s Stack address to be treated
 */
void clear(Stack *s){
    do
    {
        s->data[s->index] = 0.0;
        s->index --;
    } while (s->index > 0);
}