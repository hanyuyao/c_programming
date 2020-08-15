#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* Create_List(Node* head, int data)
{
	Node* current;
	Node* newnode;
	newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;
	
	current = head;  //current & head point to the same memory address
	if(current == NULL) return newnode;
	
	while(current->next != NULL){
		current = current->next;
	}
	current->next = newnode;
	
	return head;
}

Node* Reverse_List(Node* head)
{
	Node* previous = NULL;
	Node* current = head;
	Node* preceding = head->next;
	while(preceding != NULL){
		current->next = previous;
		previous = current;
		current = preceding;
		preceding = preceding->next;
	}
	current->next = previous;
	head = current;
	return head;
}

void Print_List(Node* head)
{
	while(head!=NULL){
		printf("%d", head->data);
		if(head->next != NULL)
			printf("->");
		head = head->next;
	}
	printf("\n");
}

void Free_List(Node* head)
{
	while(head != NULL){
		Node* current = head;
		head = head->next;
		free(current);
	}
}
