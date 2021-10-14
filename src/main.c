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
/*
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
*/
    Queue *q = (Queue *) malloc(sizeof(Queue));
    
    init_queue(q);
    assert(q->index == 0);
    enqueue(q,2.5);
    enqueue(q,1.5);
    enqueue(q,4.5);
    printf("\nAvant dequeu%.2f / %d",q->data[0], q->index);
    float r = dequeue(q);
    printf("\n1ere Valeur apres dequeu%.2f",q->data[0]);
    printf("\n%.2f",r);
    printf("\nfront : %.2f",front(q));
    clear_queue(q);
    printf("\nApres clear%.2f / %d\n",q->data[0], q->index);
    return (EXIT_SUCCESS);
}

