/*
Author : Spencer Stair
Date : 10/1 - 10/7, Final touches : 10/13-
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void MyInsert(int [], int [], int [], int, int);
void MyDelete(int [], int [], int [], int, int);
void MyMoveStack(int [], int [], int [], int [], int);
void MyReallocate(int [], int [], int [], int [], int [], int, int);

int main()
{
	FILE *inFile;
	char fileInName[21] = { 'i','n','p', 'u', 't', '0', '0',' 2', '.', 't', 'x', 't'};
	FILE *outFile;
	char fileOutName[21] = { 'o', 'u', 't', 'p', 'u', 't', '0', '0',' 2', '.', 't', 'x', 't'};

	int max, numStacks, zed = 0;

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

	printf("How much memory would you like to use?\n");
	scanf("%d", &max);
	char multiStack[max][10];
	fprintf(outFile, "How much memory would you like to use?\n");
	fprintf(outFile, "%d\n", max);

	printf("How many stacks would you like to use?\n");
	scanf("%d", &numStacks);
	fprintf(outFile, "How many stacks would you like to use?\n");
	fprintf(outFile, "%d\n", numStacks);

	for(int J = 1; J <= numStacks; J++)
	{
		Base[J] = Top[J] = floor( (J - 1) / numStacks * max ) + zed;

	}

	printf("Processing...\n");
	fprintf(outFile, "Processing...\n");

	printf("Process Completed\n");
	fprintf(outFile, "Process Completed\n");

	fclose(inFile);
	fclose(outFile);
}


void MyInsert(int Top[], int Base[], int StackSpace[], int X, int K)
{
	Top[K] = Top[K] + 1;
	if(Top[K] > Base[K + 1])
	{
		printf("Overflow\n");
		/*report overflow; {Algorithm Reallocate should be used to determine if
		 additional space can be made available by taking it from another stack.}*/
	}
	else
	{
		StackSpace[ Top[K] ] = X[]; //{Insert value of X into the stack.}
	}
}


void MyDelete(int Top[], int Base[], int StackSpace[], int X, int K)
{
	if(Top[K] == Base[K])
	{
		printf("Underflow\n");
		//report underflow;
	}
	else
	{
		X = StackSpace[ Top[K] ];  //{Remove top item in stack and assign to X.}
		Top[K] = Top[K] - 1;
	}
}

void MyMoveStack(int StackSpace[], int Top[], int NewBase[], int Base[], int numStacks)
{
	int J, Delta;
//MoA1:	{Moves all stacks down first.  While not obvious, some thought should convenience you this can be done without overlapping any stacks.}
	for(J = 2; J < numStacks; J++)
	{
		if(NewBase[J] < Base[J])
		{
			Delta = Base[J] - NewBase[J];
			for( ; ; ) //For L in (Base[J] + 1), (Base[J] + 2) .. Top[J] Loop
			{
				StackSpace[L - Delta] = StackSpace[L];
			}
			Base[J] = NewBase[J];
			Top[J] = Top[J] - Delta;
		}
	}
//MoA2:	{Move all stacks up without overlapping any stacks}
	for(J = numStacks; J > 2; J--)
	{
		if(NewBase[J] > Base[J])
		{
			Delta = NewBase[] - Base[J];
			for( ; ; ) //For L in Top[J], (Top[J] - 1), ... (Base[J] + 1) Loop
			{
				StackSpace[L + Delta] = StackSpace[L];
			}
			Base[J] = NewBase[J];
			Top[J] = Top[J] + Delta;
		}
	}	
}

void MyReallocate(int Top[], int OldTop[], int Growth[], int Base[], int NewBase[], int MinSpace, int numStacks)
{
//	ReA1:	{Find the amount of available space for reallocation.  TotalInc is the total growth since the last time memory overflowed.}  
	int AvailSpace = M - L0 ( || Base[numStacks + 1] - Base[0]);
	int TotalInc = 0;
	int J = numStacks;
	while(J > 0)
	{
		AvailSpace = AvailSpace - (Top[J] - Base[J]);
		if(Top[J] > OldTop[J])
		{
			Growth[J] = Top[J] - OldTop[J];
			TotalInc = TotalInc + Growth[J];
		}
		else
		{
			Growth[J] = 0;
		}
		J = J - 1;
	}
//ReA2:{Please note that when memory overflowed, space for the new request has already been reserved at the location pointed to by Top[K].  If AvailSpace = 0, then there is exactly one unit of space available.  If AvailSpace < 0, we are truly out of memory.}
	if(AvailSpace < (MinSpace - 1) )
	{
		report insufficient memory for re-packing to occur and terminate.
	}
//ReA3: {EqualAllocate must be represented as a decimal fraction, e.g., 0.15 would imply 15% of available memory to be allocated equally between all N stacks}
		//{EqualAllocate * AvailSpace is the amount of memory to be divided equally between the stacks.  Each stack gets 1/N of this space.  Alpha is a real number and must be computed to a reasonable number of digits to the right of the decimal point.}
	int GrowthAllocate = 1 - EqualAllocate;
	int Alpha = EqualAllocate * AvailSpace / numStacks;
//ReA4: {TotalGrowthSpace := GrowthAllocate * AvailSpace is the amount of memory to be allocated based on growth.  Beta := TotalGrowthSpace / TotalInc is the amount of space to allocate a stack for each unit it has increased in size since the last time memory overflowed.  This algorithm does not penalize for a stack shrinking in size.  There is simply no growth allocation, only the equal allocation represented by Alpha.  Beta is a real number and must be computed to reasonable accuracy}
	int Beta = GrowthAllocate * AvailSpace / TotalInc;
//ReA5: {NewBase[J] is the sum of the preceding base location (Base[j-1]) plus the size of the preceding stack (Top[J-1] - Base[J-1]) plus the growth allocation for the preceding stack (floor(Tau)) minus floor(Sigma)).  The “floor” operator means to take the integer part of the number without rounding.  For example:  floor(0.345) = 0;  floor(8.43) = 8; and floor(8.999999) = 8.  When this step is complete, NewBase[J] represents the location of the new base for each stack J after re-packing.}
	NewBase[1] = Base[1];
	int Sigma = 0;
	for(int J = 2; J < numStacks; J++)
	{
	int Tau = Sigma + Alpha + Growth[J - 1] * Beta;
		NewBase[J] = NewBase[J - 1] + ( Top[J - 1] - Base[J - 1] ) + floor(Tau) - floor(Sigma);
		Sigma = Tau;
	}
//ReA6:	{It is time to re-pack the stacks.  Recall that space for a new element was allocated in a stack pointed to by Top[K] when overflow occurred.  We must adjust for this prior to re-packing by subtracting one from K.  After re-packing is complete, we must add one back to K prior to returning to the program requesting the reallocation.  The program that requested reallocation of memory may then store the desired datum in the stack location  pointed to by Top[K].}
	Top[K] = Top[K] - 1;
	MyMoveStack();
	Top[K] = Top[K] + 1;
//Insert item causing the over flow at location Top[K];
	for( J = 1; J < numStacks; J++)
	{
		OldTop[J] = Top[J];
	}
}






