#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int max = 7;

void MyWarshall(bool[][max], bool[][max], int);

int main()
{
	FILE *inFile;
	char fileInName[21] = { 'm','a','t', 'r', 'i', 'x', 'i' ,' n', 'p', 'u', 't', '.', 't', 'x', 't'};
	FILE *outFile;
	char fileOutName[21] = { 'm','a','t', 'r', 'i', 'x', 'o', 'u', 't', 'p', 'u', 't', '.', 't', 'x', 't'};

	bool matrix_1[max][max], matrix_2[max][max];
	int index, i, j, k;
	char Values[10] = { 'A', 'B', 'C', 'D', 'J', 'K', 'L' };
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
			fscanf(inFile, "%B", &matrix_1[i][j]);
		}
	}

	MyWarshall(matrix_1, matrix_2, max);

	//printf("   A B C D J K L\n");
	fprintf(outFile, "     A     B     C     D     J     K     L\n");

	for(i = 0 ; i < max ; i++)
	{
		//printf("%c: ", Values[i]);
		fprintf(outFile, "%c: ", Values[i]);

		for(j = 0 ; j < max ; j++)
		{
			if(matrix_2[i][j] == yes)
			{
				fprintf(outFile, "%s ", yes);
			}else{
				fprintf(outFile, "%s ", no);
			}


			//printf("%d ", matrix_2[i][j]);
			//fprintf(outFile, "%d ", matrix_2[i][j]);
		}

		//printf("\n");
		fprintf(outFile, "\n");
	}

	fclose(inFile);
	fclose(outFile);	
}

void MyWarshall(bool matrix_1[][max], bool temp[][max], int n)
{
	
	int i, j, k;
	bool y = true;
	bool x = false;

	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n ; j++)
		{
			if(matrix_1[i][j] == y)
			{
				temp[i][j] = y;
			}else{
				temp[i][j] = x;
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
