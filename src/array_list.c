/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/array_list.h"


/**
 * @brief Initialise la liste
 * 
 * @param l liste à initialiser 
 */
void init_array_list(Array_list *l){
    l->index = 0;

    for (int i = 0; i < ARRAY_LIST_MAX_SIZE; i++)
    {  
        l->data[i] = 0.0;
    }

}

/**
 * @brief Ajouter un élément à la liste à une position précise.
 * 
 * @param l liste 
 * @param position Position de l'élément à ajouter
 * @param value Valeur à ajouter 
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
 * @brief Ajouter une valeur à la fin de la liste 
 * 
 * @param l liste 
 * @param value Valeur à ajouter
 */
void add(Array_list *l, float value){
    l->data[l->index] = value;
    l->index ++;
}
/**
 * @brief Supprimer un élément à la liste à une position précise.
 * 
 * @param l liste
 * @param position Position de l'élément à supprimer
 * @return float Renvoi l'élément supprimé
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
 * @brief Retourner l'élément de la liste à la position n
 * 
 * @param l Liste 
 * @param position Position de l'élément
 * @return float Retourne l'élément
 */
float get_at(Array_list *l,int position){
    float valueToGet = 0.0;
    if (position <= l->index)
    {
        int i = l->index - 1;
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
 * @brief Supprime toutes les valeurs de la liste
 * 
 * @param l liste 
 */
void clear_list(Array_list *l){
    do
    {
        l->data[l->index] = 0.0;
        l->index--;

    }while (l->index != 0);
    
}