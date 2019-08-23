/*
Author : Spencer Stair
Date : 10/25/18 - 11/4/18

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerFile.h"

//Prints all the elements in linked list
void Print()
{
	struct Node* temp = head;
	printf("List: ");

	while(temp != NULL)
	{
		printf("%d ", temp -> data);
		temp = temp -> next;
	}

	printf("\n");
}
