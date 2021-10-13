/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/stack.h"

void init_stack(Stack *s){
    s->index = 0;
    for (int i = 0; i < STACK_MAX_SIZE; i++)
    {
        s->data[i] = 0.0;
    }   
}

void push(Stack *s, float value){
    s->data[s->index] = value;
    s->index ++;
}

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

bool is_stack_empty(Stack *s){
    bool empty = true;
    
    if (s->index != 0)
    {
        empty = false;
    }

    return empty; 
}

float peek(Stack *s){
    float lastElement = 0.0;
    if (s->index > 0)
    {
        lastElement = s->data[s->index-1];
    }    
    return lastElement;
}

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

void swap(Stack *s){
    if (s->index > 0)
    {
        float tempVal = s->data[s->index-1];
        s->data[s->index-1] = s->data[s->index-2];
        s->data[s->index-2] = tempVal;
    }
}

void clear(Stack *s){
    do
    {
        s->data[s->index] = 0.0;
        s->index --;
    } while (s->index > 0);
}