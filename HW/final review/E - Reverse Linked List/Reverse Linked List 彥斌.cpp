#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	node* next;
}Node;

Node* Create_List(Node* head, int data)
{
	Node *x = (Node*)malloc(sizeof(Node));
	x->data = data;
	x->next = head;
	head = x;
	return head;
}

Node* Reverse_List(Node* head)
{
	
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


int main() {
    Node *head = NULL;
    int n, data, i;
    
    scanf("%d", &n);
    for( i=0; i<n; i++ ) {
        scanf("%d", &data);
        head = Create_List( head, data );
    }
    
    head = Reverse_List( head );
    
    Print_List( head );
    Free_List( head );
    
    return 0;
}

