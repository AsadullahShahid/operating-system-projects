/* ---Queue.cpp------------------------------------------------------------------
   An implementation file for the Queue class 
   Operations are:
	
   Written by: Tyler Frye			Tennessee Technological University
   Written for: CSC 2110			Written on: March 05, 2010
   ---------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;
#include "Queue.h"
Queue::Queue() {
	first = NULL;
	last = NULL;	
}
void Queue::enqueue() {
	NodePointer nPtr = new Node(1);
	NodePointer predPtr = first;
	
	if (first == NULL) { //Insert if queue is empty
		nPtr->next = first;
		nPtr->prev = first;
		first = nPtr;
	} else {
		while (predPtr->next != NULL) {
			predPtr = predPtr->next;
		}
		nPtr->prev = predPtr;
		nPtr->next = predPtr->next;
		predPtr->next = nPtr;
	}
	
	last = nPtr; //Set last to new pointer
}
void Queue::dequeue() {
	NodePointer dPtr = first;
	first = first->next;
}
ElementType Queue::front() {
	NodePointer ptr = first;
	return ptr->data;
}
int Queue::getSize() {
	int mySize = 0;
	NodePointer ptr = first;
	while (ptr != NULL) {
		ptr = ptr->next;
		mySize++;
	}
	return mySize;
}
