/*
Author : Spencer Stair
Date : 10/25/18 - 11/4/18

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerFile.h"
/*
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
*/
int main()
{
	head = NULL; // empty list. set head as NULL. 

	printf("Processing...\n");

	// Operations
	HeadInsertion(33);
	HeadInsertion(57);
	TailInsertion(85);
	HeadInsertion(95);
	Print();
	DeleteNode(57, Z);
	DeleteNode(33, Z);
	//Delete(33, Z); 	-- Caused Segmentation Fault 11
	HeadInsertion(22);
	DeleteNode(95, Z);
	Print();

	printf("Process Completed\n");
}