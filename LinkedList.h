/* ---LinkedList.h------------------------------------------------------------------
   A header file for the Queue class 
   Operations are:
	
   Written by: Tyler Frye			Tennessee Technological University
   Written for: CSC 2110			Written on: March 05, 2010
   ---------------------------------------------------------------------------------*/
   
#ifndef QUEUE
#define QUEUE
#include <iostream>
using namespace std; 
typedef int ElementType;
class Queue {
	
	public:
		
		//Default constructor
		Queue();
		
		//Add to the back of the queue
		void enqueue();
		
		//Remove from the front of the queue
		void dequeue();
	
		//Returns the front of the queue
		ElementType front();
		
		//Return size of the queue
		int getSize();
		
	private:
		
		class Node {
		
			public:
			
				ElementType data;
				Node *next, *prev;				 
				Node(ElementType i) { // Node constructor
					data = i;
					next = NULL;
					prev = NULL;
				}
		}; //--- end of Node class
		
		typedef Node *NodePointer;
		
		Node *first;
		Node *last;
		
}; //--- end of Queue class
//Operator overload statements here
#endif
