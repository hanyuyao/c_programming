#include <stdio.h>
#include <stdlib.h>

// linked list
 
typedef struct _node {
	//_node: temporary name
    int x;
    struct _node *next;
} Node;

int main(void)
{
    Node head;

    head.x = 0;
    head.next = NULL;   //have to = NULL, or we don't know what it will be

    head.next = (Node *) malloc (sizeof(Node));

    (head.next)->x = 1;
    (head.next)->next = NULL;   

    printf("%d %d\n", head.x, (head.next)->x);

    free(head.next);

    return 0;
}
