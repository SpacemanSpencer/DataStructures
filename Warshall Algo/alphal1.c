/*
Author : Spencer Stair
Date : 9/14 - 9/20, Final touches : 9/27
*/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int max = 9;

void MyWarshall(int[][max], int[][max], int);

int main()
{
	FILE *inFile;
	char fileInName[21] = { 'm','a','t', 'r', 'i', 'x', 'i','n', 'p', 'u', 't', '.', 't', 'x', 't'};
	FILE *outFile;
	char fileOutName[21] = { 'm','a','t', 'r', 'i', 'x', 'o', 'u', 't', 'p', 'u', 't', '.', 't', 'x', 't'};

	int matrix_1[max][max], matrix_2[max][max], index, i, j, k;
	char Values[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J' };
	char yes[6] = { 't', 'r', 'u', 'e'};
	char no[6] = { 'f', 'a', 'l', 's', 'e'};

	inFile = fopen(fileInName, "r");
	if(inFile == NULL){
		printf("Input file does not exist! Terminating!\n");
		exit(1);
	}
	outFile = fopen(fileOutName, "w");
	if(outFile == NULL){
		printf("Could not create report! Terminating!\n");
		exit(1);
	}

	for(i = 0 ; i < max ; i++)
	{
		for(j = 0 ; j < max ; j++)
		{
			fscanf(inFile, "%d", &matrix_1[i][j]);
			//scanf("%d", &matrix_1[i][j]);
		}
	}

	MyWarshall(matrix_1, matrix_2, max);

	//printf("   A B C D J K L\n");
	fprintf(outFile, "     A     B     C     D     E     F     G     H 	   J\n");

	for(i = 0 ; i < max ; i++)
	{
		//printf("%c: ", Values[i]);
		fprintf(outFile, "%c: ", Values[i]);

		for(j = 0 ; j < max ; j++)
		{
			//printf("%d ", matrix_2[i][j]);
			//fprintf(outFile, "%d ", matrix_2[i][j]);

			if(matrix_2[i][j])
			{
				fprintf(outFile, "%5s ", yes);
			}else{
				fprintf(outFile, "%5s ", no);
			}
		}

		//printf("\n");
		fprintf(outFile, "\n");
	}
	printf("Process Completed\n");
}

void MyWarshall(int matrix_1[][max], int temp[][max], int n)
{
	
	int i, j, k;

	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n ; j++)
		{
			if(matrix_1[i][j] == 1)
			{
				temp[i][j] = 1;
			}else{
				temp[i][j] = 0;
			}

		}

	}

	for(k = 0 ; k < n ; k++)
	{
		for(i = 0 ; i < n ; i++)
		{
			for(j = 0 ; j < n ; j++)
			{
				temp[i][j] = temp[i][j] || (temp[i][k] && temp[k][j]);
			}
		}
	}
}
