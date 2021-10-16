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
#include "../include/array_list.h"
#include "../include/heap.h"

int test_cleanup(void)
{
	return 0;
}

int test_init(void)
{
	return 0;
}

/**
 * @brief 
 * 
 */
void test_Stack(){
    Stack stackVar;
    init_stack(&stackVar);
    CU_ASSERT(stackVar.index == 0);

    push(&stackVar, 5);
    CU_ASSERT(stackVar.data[0] == 5);
    
    bool empty = is_stack_empty(&stackVar);
    CU_ASSERT(empty == false);


    float varStack = peek(&stackVar);
    CU_ASSERT(varStack == 5);

    push(&stackVar, 19);
    varStack = pop(&stackVar);
    CU_ASSERT(varStack==19);
    
    dump(&stackVar);
    varStack = peek(&stackVar);
    CU_ASSERT(varStack == 5);
    
    clear(&stackVar);
    CU_ASSERT(stackVar.index == 0);
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

/**
 * @brief 
 * 
 */
void test_Array_List(){
    Array_list list;

    init_array_list(&list);
    CU_ASSERT(list.index == 0);

    add(&list, 85);
    CU_ASSERT(list.data[0] == 85);
    add(&list, 85);
    add(&list, 85);

    insert_at(&list, 1, 4);
    CU_ASSERT(list.data[1] == 4);

    float varGet = get_at(&list, 0);
    CU_ASSERT(varGet == 4);

    clear_list(&list);
    CU_ASSERT(list.index == 0);
} 

void test_Heap(){
    Heap heap;
    init_heap(&heap);
    CU_ASSERT(heap.index == 0);

    push_heap(&heap, 5);
    CU_ASSERT(heap.data[0] == 5);    
    push_heap(&heap, 25.0);
    push_heap(&heap, 18.0);
    push_heap(&heap, 2);
    push_heap(&heap, 8);
    //heap.data[0]=5;

    float popedVar = pop_heap(&heap);
    CU_ASSERT(popedVar == 2);
    CU_ASSERT(peek_heap(&heap) == 5 );

    CU_ASSERT(is_heap_empty(&heap) == false);

    CU_ASSERT(replace(&heap, 1) == 5);
    CU_ASSERT(peek_heap(&heap) == 1 );

    clear_heap(&heap);
    CU_ASSERT(heap.index == 0);
    //8 tests
}

int main(int argc, char** argv) {  
    CU_initialize_registry();
    CU_pSuite *suite = CU_add_suite("test", test_init, test_cleanup);
	//CU_add_test(suite, "test_list", test_Array_List);
	//CU_add_test(suite, "test_Queue", test_Queue);
	//CU_add_test(suite, "test_queue", test_Stack);
	CU_add_test(suite, "test_heap", test_Heap);
	CU_basic_run_tests();
	return (0);

    // test_Heap();
   
}
