
/****************************************************************************/
//   File    		: main.c
//---------------------------------------------------------------------------
//   Description 	: Calculate maximum and minimum value among array.
//---------------------------------------------------------------------------
//   Date 			: 2020 / 12 / 29
//   Author 		: Cho Kyusik
//   Version		: V1.0
//   Modification 	: 2021 / 01 / 16
/****************************************************************************/

/*--- Includes (Linkage Defines/Typedefs/Extern Variables/Extern Function)--*/
#include <stdio.h>
#include <stdlib.h>
/*---------------------------- Private Defines: ----------------------------*/
/*---------------------------- Private Typedefs: ---------------------------*/
/*---------------------- Private Statics (Variables): ----------------------*/
/*---------------------- Private Function Prototypes: ----------------------*/
void InputNumber(int *n);
void AllocateMem(int **pptr, int size);
void InputArry(int *arry, int size);
void GetMax(const int *arry, int *max, int size);
void GetMin(const int *arry, int *min, int size);
void PrintResult(const char *msg, int val);
/*---------------------------- Private Functions: --------------------------*/
/*****************************************************************************
Function : main function
------------------------------------------------------------------------------
Desc	: Entry point (MAIN)
Params	: None
Return	: 1. 0 - Exit SUCCESS
		  2. Other value - Exit FAILURE (failure code)
*****************************************************************************/
int main(void)
{
	 
	int number;				// Variable for number(size) of array
	int i;					// Variable for loop control 
	int *pointer;			// Varialbe for pointer-dynamically allocated memory
	int maximun, mininum;	// Varialbe for maxinum and mininum
	char *maxMsg = "max : %d\n"; // Format string for maximum message
	char *minMsg = "min : %d\n"; // Format string for minimun message

	// Input the size of array
	InputNumber(&number);	
	// Allocate memory for array
	AllocateMem(&pointer, sizeof(number*sizeof(int))); 
	// Input the array's elements
	InputArry(pointer, number);
	// Calculate the maximum
	GetMax(pointer, &maximun, number);
	// Calculate the minimum
	GetMin(pointer, &mininum, number);
	// Print the results
	PrintResult(maxMsg, maximun);
	PrintResult(minMsg, mininum);

	// Deallocate the memory no longer used
	free(pointer);
	
	return 0;
}
/*----------------------------- Global Functions: --------------------------*/
/*****************************************************************************
Function : InputNumber
------------------------------------------------------------------------------
Desc	: Get an integer from stdin(Keyboard), this will be used to as a nummber
          of array elemnents.
Params	: int *n - Pointer to storage for input number from stdin
Return	: None
*****************************************************************************/
void InputNumber(int *n)
{
	scanf("%d", n);
}
/*****************************************************************************
Function : AllocateMem
------------------------------------------------------------------------------
Desc	: Allocate memory and store the start address within dynamical 
		  storage area(Heap)                          
Params	: 1. int **pptr - Storage for start memory address to be allocated
    	  2. int size - Number of bytes for memory to be allocated                                        
Return	: None
*****************************************************************************/
void AllocateMem(int **pptr, int size)
{
	// main object - ¡Ú 	: object what i want to be changed within function
	// main func call		: func(&¡Ú);
	// func parameter type 	: *(type¡Ú)
	// ex) ¡Úis int * => func parameter type : int ** (where ¡Ú= int *)
	*pptr = malloc(size);
}
/*****************************************************************************
Function : InputArry
------------------------------------------------------------------------------
Desc	: Get array element's values from stdin(Keyboard)
Params	: 1. int *array - Pointer to the array's first element
		  2. int size - Number of the array's elements
Return	: None
*****************************************************************************/	
void InputArry(int *arry, int size)
{
	int i;
	for(i=0; i<size; i++) {
		scanf("%d", arry+i);
	}
}
/*****************************************************************************
Function : GetMax
------------------------------------------------------------------------------
Desc	: Get the maximum value among array
Params	: 1. const int *arry - Pointer to the array's first element
		  2. int *max - Pointer to the maximum value to be stored
		  3. int size - Number of array's elements
Return	: None
*****************************************************************************/	
void GetMax(const int *arry, int *max, int size)
{	
	int i;
	for(*max=*arry, i=0; i<size; i++) {
		if(*max < *(arry+i)) {
			*max = *(arry+i);
		}
	}
}
/*****************************************************************************
Function : GetMin
------------------------------------------------------------------------------
Desc	: Get the minimum value among array
Params	: 1. const int *arry - Pointer to the array's first element
		  2. int *min - Pointer to the minimum value to be stored
		  3. int size - Number of array's elements
Return	: None
*****************************************************************************/		
void GetMin(const int *arry, int *min, int size)
{	
	int i;
	for(*min=*arry, i=0; i<size; i++) {
		if(*(arry+i) < *min) {
			*min = *(arry+i);
		}
	}
}
/*****************************************************************************
Function : PrintResult
------------------------------------------------------------------------------
Desc	: Print the result message
Params	: 1. const char *msg - Format string for print
  		  2. int val - Value to be printed
Return	: None
*****************************************************************************/
void PrintResult(const char *msg, int val) 
{
	printf(msg, val);
}
/**************************** End of File ***********************************/





