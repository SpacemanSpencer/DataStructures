/*
Author : Spencer Stair
Date : 10/25/18 - 11/4/18

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerFile.h"

//Inserts a Node at Tail of Doubly linked list
void TailInsertion(int x)
{
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);

	if(head == NULL)
	{
		head = newNode;
		return;
	}

	while(temp -> next != NULL)
	{
		temp = temp -> next; // Go To last Node
	}

	temp -> next = newNode;
	newNode -> prev = temp;
	Z++;
}
