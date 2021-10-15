/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../include/stack.h"

/**
 * @brief Initialise la pile 
 * 
 * @param s Pile à initialiser
 */
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

/**
 * @brief Supprime la dernière valeur de la pile 
 * 
 * @param s Pile 
 * @return float Retourne la valeur supprimé 
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
 * @brief Retourne un booléen, true si la pile est vide 
 * 
 * @param s Pile à traiter
 * @return true  pile vide 
 * @return false pile pas vide
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
 * @brief Renvoi le dernier 
 * 
 * @param s Pile à traiter
 * @return float dernier élément de la pile 
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
 * @brief Supprime le dernier élément 
 * 
 * @param s Pile à traiter 
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
 * @brief Echange le dernier et l'avant dernier 
 * 
 * @param s Pile à traiter 
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
 * @brief 
 * 
 * @param s 
 */
void clear(Stack *s){
    do
    {
        s->data[s->index] = 0.0;
        s->index --;
    } while (s->index > 0);
}