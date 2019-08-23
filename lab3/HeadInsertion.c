/*
Author : Spencer Stair
Date : 10/25/18 - 11/4/18

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerFile.h"

//Inserts a Node at Head of Doubly linked list
void HeadInsertion(int x)
{
	struct Node* newNode = GetNewNode(x);

	if(head == NULL) 
	{
		head = newNode;
		return;
	}

	head -> prev = newNode;
	newNode -> next = head; 
	head = newNode;
	Z++;
}
