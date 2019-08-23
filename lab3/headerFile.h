#ifndef HEADERFILE02_H_   /* Include guard */
#define HEADERFILE02_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.
int Z = 0; // global variable - size of list.

//Creates a new Node and returns pointer to it. 
struct Node* GetNewNode(int x)
{
	struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));

	newNode -> data = x;
	newNode -> prev = NULL;
	newNode -> next = NULL;
	return newNode;
}


//subprogram to Delete a Node (based upon its contents) of a Doubly linked list
void DeleteNode(int contents, int listSize);

//subprogram to Insert a Node at Head of a Doubly linked list
void HeadInsertion(int x);

//subprogram to Insert a Node at Tail of a Doubly linked list
void TailInsertion(int x);

//subprogram to Print all of the elements in a Doubly linked list
void Print();

#endif