/**
 * @file main.c
 * @author Kubilay KAPLAN & Emile METRAL
 * @brief 
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
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

void test_Stack(){
    Stack stackVar;
    init_stack(&stackVar);
    assert(stackVar.index == 0);

    push(&stackVar, 5);
    assert(stackVar.data[0] == 5);
    
    bool empty = is_stack_empty(&stackVar);
    assert(empty == false);


    float varStack = peek(&stackVar);
    assert(varStack == 5);

    push(&stackVar, 19);
    varStack = pop(&stackVar);
    assert(varStack==19);
    
    dump(&stackVar);
    varStack = peek(&stackVar);
    assert(varStack == 5);
    
    clear(&stackVar);
    assert(stackVar.index == 0);
}
*/
int test_cleanup(void)
{
	return 0;
}

int test_init(void)
{
	return 0;
}

/**
 * @brief test de la data structure queue
 * 
 */

void test_Queue(){
    Queue *q = (Queue *) malloc(sizeof(Queue));
    init_queue(q);
    CU_ASSERT(q->index ==0);
    // assert(q->index ==0);
    // assert(q->data[0] == 0.0);
    CU_ASSERT(q->data[0] == 0.0);
    enqueue(q,2.5);
    enqueue(q,1.5);
    enqueue(q,4.5);
    CU_ASSERT(q->data[0] == 2.5);
    CU_ASSERT(q->data[1] == 1.5);
    CU_ASSERT(q->data[2] == 4.5);
    // assert(q->data[0] == 2.5);
    // assert(q->data[1] == 1.5);
    // assert(q->data[2] == 4.5);
    // assert(dequeue(q) == 2.5);
    CU_ASSERT(dequeue(q) == 2.5);
    // assert(q->data[0] == 1.5);
    CU_ASSERT(q->data[0] == 1.5);
    clear_queue(q);
    // assert(q->index ==0);
    // assert(q->data[0] == 0.0);
    CU_ASSERT(q->data[0] == 0.0);
    CU_ASSERT(q->index == 0);
    
}

void test_Array_List(){
    Array_list list;

    init_array_list(&list);
    assert(list.index == 0);

    add(&list, 85);
    assert(list.data[0] == 85);
    add(&list, 85);
    add(&list, 85);

    insert_at(&list, 1, 4);
    assert(list.data[1] == 4);
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
    
    
    //test_Queue();
    CU_initialize_registry();
	CU_pSuite *suite = CU_add_suite("test", test_init, test_cleanup);
	//CU_add_test(suite, "test_list", test_array_list);
	CU_add_test(suite, "test_Queue", test_Queue);
	//CU_add_test(suite, "test_queue", test_stack);
	//CU_add_test(suite, "test_heap", test_heap);
	CU_basic_run_tests();

    float varGet = get_at(&list, 0);
    assert(varGet == 4);

    clear_list(&list);
    assert(list.index == 0);
}

/*
 * 
 */
int main(int argc, char** argv) {

    
    //test_Stack();
    //test_Queue();
    //test_Array_List();
    return (EXIT_SUCCESS);
	return (0);
}

