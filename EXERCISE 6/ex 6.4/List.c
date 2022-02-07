#include"List.h"
#include<stdio.h>
#include <stdlib.h>

typedef int ListDataType;
typedef struct Node_t Node;
typedef struct List_t List;


struct Node_t {
	ListDataType data;
	Node* next;
};

struct List_t {
	Node* head;
};



List* CreateList()
{
	List* list;
	list->head = NULL;



	return list;
}

void FreeList(List* list)
{
	free(list);
}

size_t GetListSize(List* list)
{
	size_t SIZE = 0;
	Node* node = list->head;

	while (node != NULL)
	{
		++SIZE;
	}

	return SIZE;
}

Node* GetListHead(List* list)
{
	return list->head;
}

Node* GetNextNode(Node* currentNode)
{
	return currentNode->next;
}

ListDataType GetValue(Node* node)
{
	return node->data;
}

Node* Insert(Node* after, ListDataType newValue)
{
	/*1. check if the given prev_node is NULL */
	if (after == NULL)
	{
		printf("the given previous node cannot be NULL");
		return;
	}

	/* 2. allocate new node */
	Node* new_node = (Node*)malloc(sizeof(Node));

	/* 3. put in the data */
	new_node->data = newValue;

	/* 4. Make next of new node as next of prev_node */
	new_node->next = after->next;

	/* 5. move the next of prev_node as new_node */
	after->next = new_node;
}

Node* PushFront(List* list, ListDataType newValue)
{
	/* 1. allocate node */
	Node* new_node = (Node*)malloc(sizeof(Node));

	/* 2. put in the data  */
	new_node->data = newValue;

	/* 3. Make next of new node as head */
	new_node->next = list->head;

	/* 4. move the head to point to the new node */
	list->head = new_node;
}

Node* PushBack(List* list, ListDataType newValue)
{
	/* 1. allocate node */
	Node* new_node = (Node*)malloc(sizeof(Node));

	Node* last = list->head;  /* used in step 5*/

	/* 2. put in the data  */
	new_node->data = newValue;

	/* 3. This new node is going to be the last node, so make next
		  of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new node as head */
	if (list->head == NULL)
	{
		list->head = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;
	return;
}

ListDataType PopFront(List* list)
{
	ListDataType deletedData = list->head->data;
	list->head = list->head->next;

	return deletedData;
}

ListDataType PopBack(List* list)
{
	Node* node = list->head;
	ListDataType deletedData;

	while (node->next->next != NULL)
	{
		node = node->next;
	}

	deletedData = node->next->data;
	node->next = NULL;

	return deletedData;
}

void DeleteListNode(List* list, Node* target)
{
	// Store head node
	Node* temp = list->head, * prev;

	// If head node itself holds the key to be deleted
	if (temp != NULL && temp->data == target->data && temp->next == target->next) {
		list->head = temp->next; // Changed head
		free(temp); // free old head
		return prev;
	}

	// Search for the key to be deleted, keep track of the
	// previous node as we need to change 'prev->next'
	while (temp != NULL && (temp->data != target->data || temp->next != target->next)) {
		prev = temp;
		temp = temp->next;
	}

	// If key was not present in linked list
	if (temp == NULL)
		return list->head;

	// Unlink the node from linked list
	prev->next = temp->next;

	free(temp); // Free memory
}

Node* DeleteListValue(List* list, ListDataType value)
{
	// Store head node
	Node* temp = list->head, * prev;

	// If head node itself holds the key to be deleted
	if (temp != NULL && temp->data == value) {
		list->head = temp->next; // Changed head
		free(temp); // free old head
		return prev;
	}

	// Search for the key to be deleted, keep track of the
	// previous node as we need to change 'prev->next'
	while (temp != NULL && temp->data != value) {
		prev = temp;
		temp = temp->next;
	}

	// If key was not present in linked list
	if (temp == NULL)
		return list->head;

	// Unlink the node from linked list
	prev->next = temp->next;

	free(temp); // Free memory
}

Node* FindInList(List* list, ListDataType value)
{
	Node* node = list->head;

	while (node->data != value)
	{
		node = node->next;
	}

	return node;
}

