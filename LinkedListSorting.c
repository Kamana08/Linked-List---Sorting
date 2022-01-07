/*******************************************************************************************
* File Name          : KamanaSharma_Assignment.c
* Description        : Prog8130 - Assignment 1: Linked Lists
*					   This program uses linked lists to hold and print a list of words
*					   organized by index number assosciated with each word. Each word can
*					   consist of maximum 30 characters.
*
* Author:            : Kamana Sharma(8697409)
* Date:              : June 9th,2021
********************************************************************************************/

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_DATA_ITEMS   10					// the number of data items to be used in list
int listLen = 0;
// structure/typedef used for holding data
typedef struct {
	char name[30];
	int index;
} inputData;

// definition of linked list data nodes
typedef struct LinkedListNode {
	struct LinkedListNode* ptrNextNode;		// pointer to next node in list (NULL if the end)
	char NameData[30];		// the name to be stored (no need to store index)
} LinkedListNodeDef;

// prototypes
LinkedListNodeDef* AddToLinkedList(LinkedListNodeDef* ptrHead, char* NameData, int DataIndex);
void PrintLinkedList(LinkedListNodeDef* ptrHead);



//LinkedListNodeDef* temp;


// make the data positions the last 5 digits of student number
// for example if my student number ended in 94330 the data will be as supplied


// data used for test
// paste the data here that was created by Prog8130Assign1DataCreator.exe
// Used the following data in your assignment #1
inputData iData[10] = {
		{ "airplane", 8 },
		{ "pickels", 2 },
		{ "butter", 2 },
		{ "carrot", 8 },
		{ "milk", 7 },
		{ "allan", 4 },
		{ "orange", 5 },
		{ "fish", 6 },
		{ "water", 5 },
		{ "chocolate", 2 }
};
//end of data for assignment

// Correct order after inserting into list is:
// 1. airplane
// 2. chocolate
// 3. butter
// 4. pickels
// 5. allan
// 6. water
// 7. orange
// 8. fish
// 9. carrot
// 10. milk

int main() {
	int i;

	// define linked list head
	struct LinkedListNode* ptrHead = NULL;
	//temp = ptrHead;
	// Print out the input data
	printf("Data before Linked List is:\n");
	for (i = 0; i < NUMBER_OF_DATA_ITEMS; i++)
		printf("%s , %d\n", iData[i].name, iData[i].index);

	// insert the data into Linked List
	for (i = 0; i < NUMBER_OF_DATA_ITEMS; i++)
		ptrHead = AddToLinkedList(ptrHead, iData[i].name, iData[i].index);

	// now print out the list in order it is stored starting at head
	PrintLinkedList(ptrHead);
}

// FUNCTION      : AddToLinkedList()
// DESCRIPTION   : This function takes an input of Data of 30 Char word and an index and 
//				   places them in a linked list organized by priority of index number. 
// PARAMETERS    : LinkedListNodeDef *ptrHead	- variable to store address of ptrHead
//				   char *NameData				- Array of Characters with data 
//		           int DataIndex				- Index of data
// RETURNS       : possibly updated pointer to the head of the list
LinkedListNodeDef* AddToLinkedList(LinkedListNodeDef* ptrHead, char* NameData, int DataIndex)
{
	// put code in here to add the item(s) to the linked list
	LinkedListNodeDef* current;			//node current is defined


	listLen++;							//lenght of linked list is incremented

	current = (LinkedListNodeDef*)malloc(sizeof(LinkedListNodeDef));		//malloc memory allocation is assigned to current node
	strcpy_s(current->NameData, NameData);									//the Namedata is copied to current node
	current->ptrNextNode = NULL;											//the next pointer of current node is set to NULL

	if (listLen == 1)														//if just one node is present
	{
		ptrHead = current;													//the head will be the current node
	}
	else
	{
		if (DataIndex == 0 || DataIndex == 1)  //Condition 1
		{
			current->ptrNextNode = ptrHead;
			ptrHead = current;
		}
		else if (DataIndex >= listLen)   //Condition 2
		{
			LinkedListNodeDef* temp = ptrHead;

			while (temp->ptrNextNode != NULL)
			{
				temp = temp->ptrNextNode;
			}
			temp->ptrNextNode = current;
		}
		else                //Condition 3
		{
			int j = 0;
			LinkedListNodeDef* temp2 = ptrHead;
			while (j != DataIndex - 2)
			{
				temp2 = temp2->ptrNextNode;
				j++;
			}

			current->ptrNextNode = temp2->ptrNextNode;
			temp2->ptrNextNode = current;

		}
	}
	return ptrHead;
}

// FUNCTION      : PrintLinkedList()
// DESCRIPTION   : This function takes an input of the head of the linked list, then loops through
//				   and prints each word in the linked list until the ptrNextNode is NULL.
// PARAMETERS    : LinkedListNodeDef *ptrHead 
// RETURNS       : void
void PrintLinkedList(LinkedListNodeDef* ptrHead) {
	// put code in here to print the linked list out

	while (ptrHead != NULL)
	{
		for (int i = 1; i <= NUMBER_OF_DATA_ITEMS; i++)								//traversing the linked list
		{
			printf("%d . %s \n", i, ptrHead->NameData);
			ptrHead = ptrHead->ptrNextNode;											//head will be set as the next  node of that
		}
	}

}
