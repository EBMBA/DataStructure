/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aurelio
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include "../include/stack.h"
#include "../include/queue.h"

// float test(int a) {
//     errno = a;
//     assert(a == 5);
//     int errnum = errno;
//     fprintf(stderr, "Value of errno: %d\n", errnum);
//     perror("Error printed by perror");
//     fprintf(stderr, "Error opening file: %s\n", strerror(errnum));

// }

void test_Stack(Stack *s){

}


/*
 * 
 */
int main(int argc, char** argv) {

    Stack stackVar;
    init_stack(&stackVar);
    push(&stackVar, 5.4);
    //printf("%f\n",pop(&stackVar));
    if (is_stack_empty(&stackVar) == true)
    {
        printf("True\n");
    }
    else {
        printf("False\n");
    }
    printf("%f\n",peek(&stackVar));
    push(&stackVar, 7.5);
    printf("%f\n",peek(&stackVar));
    swap(&stackVar);
    printf("%f\n",peek(&stackVar));
    dump(&stackVar);
    printf("%f\n",peek(&stackVar));
    clear(&stackVar);
     if (is_stack_empty(&stackVar) == true)
    {
        printf("True\n");
    }
    else {
        printf("False\n");
    }

    Queue *q = (Queue *) malloc(sizeof(Queue));
    
    init_queue(q);
    enqueue(q,2.5);
    enqueue(q,1.5);
    printf("\n%.2f",q->data[0]);
    float r = dequeue(q);
    printf("\n%.2f",r);
    return (EXIT_SUCCESS);
}

