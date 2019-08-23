/*
Author : Spencer Stair
Date : 10/25/18 - 11/4/18

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerFile.h"

//Deletes a Node (based upon its contents) of Doubly linked list
void DeleteNode(int contents, int listSize)
{
    struct Node* current;
    int i;

    current = head;
    for(i = 1; i < listSize && current != NULL; i++)
    {
        current = current -> next;
    }

	if(current != NULL)
    {
        current -> prev -> next = current -> next;
        current -> next -> prev = current -> prev;

        free(current); // Delete the node

        printf("Deleted node that contained %d.\n", contents);
        Z--;
    }
    else
    {
        printf("Node containing %d does not exist!\n", contents);
    }
}
