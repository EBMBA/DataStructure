/**
 * @file array_list.c
 * @author Kubilay KAPLAN & Emile METRAL
 * @brief functions for array list
 * @version 0.1
 * @date 2021-10-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/array_list.h"


/**
 * @brief initialize  array list
 * 
 * @param l array list address to be treated
 */
void init_array_list(Array_list *l){
    l->index = 0;

    for (int i = 0; i < ARRAY_LIST_MAX_SIZE; i++)
    {  
        l->data[i] = 0.0;
    }

}

/**
 * @brief Insert value at a define position in array
 * 
 * @param l array list address to be treated
 * @param position Position of the element to add
 * @param value Value to add 
 */
void insert_at(Array_list *l, int position, float value){

    if (position <= l->index)
    {
        Array_list *l2;
        l2 = malloc(ARRAY_LIST_MAX_SIZE * sizeof(float));
        init_array_list(l2);  
        for (int i = position; i < l->index; i++)
        {
            l2->data[l2->index] =  l->data[i];
            l2->index++;
        }

        l->index ++;
        l->data[position] = value;
        int n = 0;

        for (int i = position +1 ; i < l->index; i++)
        {
            l->data[i] = l2->data[n];
            n++;               
        }
    }
    else {
        add(l, value);
    }
}

/**
 * @brief Add a value at the end of the list
 * 
 * @param l array list address to be treated 
 * @param value Value to add
 */
void add(Array_list *l, float value){
    l->data[l->index] = value;
    l->index ++;
}
/**
 * @brief Remove an item from the list at a specific position.
 * 
 * @param l array list address to be treated
 * @param position Position of the element to be deleted
 * @return float Return the deleted item
 */
float remove_at(Array_list *l, int position){
    float valueSuppr = 0.0;
    if (position <= l->index)
    {
        Array_list *l2;
        l2 = malloc(ARRAY_LIST_MAX_SIZE * sizeof(float));
        init_array_list(l2);  
        if (l2)
        {
            for (int i = position+1; i < l->index; i++)
            {
                l2->data[l2->index] =  l->data[i];
                l2->index++;
            }

            valueSuppr = l->data[position];
            l->data[l->index] = 0.0;
            l->index --;
            
            int n = 0;

            for (int i = position ; i < l->index; i++)
            {
                l->data[i] = l2->data[n];
                n++;               
            }
        }
    }
    else {
        printf("Out of range\n");
    }
    return valueSuppr;
}

/**
 * @brief Return the list item to position n
 * 
 * @param l array list address to be treated 
 * @param position Element position
 * @return float Returns the element
 */
float get_at(Array_list *l,int position){
    float valueToGet = 0.0;
    if (position <= l->index)
    {
        int i = l->index;
        while (i != position)
        {
            valueToGet = l->data[i];
            i--;
        }
        
    }
    else {
        printf("Out of range\n");
    }
    return valueToGet;
}

/**
 * @brief Removes all values ​​from the list
 * 
 * @param l array list address to be treated
 */
void clear_list(Array_list *l){
    do
    {
        l->data[l->index] = 0.0;
        l->index--;

    }while (l->index != 0);
    
}