/**
 * @file stack.h
 * @author Kubilay KAPLAN & Emile METRAL
 * @brief 
 * @version 0.1
 * @date 2021-10-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdbool.h>
#include <stdio.h>

#ifndef STACK_H
#define STACK_H

#define STACK_MAX_SIZE 100

typedef struct {
    float data[STACK_MAX_SIZE];
    int index;
} Stack;

#endif /* STACK_H */

void init_stack(Stack *s);
void push(Stack *s, float value);
float pop(Stack *s);
bool is_stack_empty(Stack *s);
float peek(Stack *s); // aka top or front
void dump(Stack *s);
void swap(Stack *s);
void clear(Stack *s);

