#ifndef LIST_QUEUE_H_
#define LIST_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Struct representing a node in
 * in the linked list
 */
typedef struct queue_node {

	int value;
	struct queue_node * next;

} queue_node;

/* 
 * Struct representing a linked list 
 */
typedef struct queue {

	int length;
	queue_node * head;
	queue_node * tail;

} queue;

/**
 * Add an item to the list
 */
void enqueue(queue * queue, int value); 

/**
 * Remove the next item from the list
 */
int dequeue(queue * queue); 

/**
 * Is the list empty
 */
bool empty(queue * queue);



#endif 

