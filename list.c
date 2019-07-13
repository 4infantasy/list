
//
// list.c
// 


#include "list.h"


//
// Create a new list.
//
list_t *
ListCreate(void)
{

	list_t * list;

	list = LIST_MALLOC(sizeof(list_t));

	if ( list == NULL )
		return NULL;

	list->head = NULL;
	list->tail = NULL;

	list->len = 0;

	return list;
}


//
// Delete a list.
//
void
ListDelete(list_t *list)
{

	list_node_t * curr = NULL;

	while ( list->len-- ) {

		curr = list->head;

		list->head = list->head->next;

		curr->next = NULL;

		LIST_FREE(curr->val);

		LIST_FREE(curr);
	}

	LIST_FREE(list);

}


//
// Print a list.
//
void 
ListPrint(list_t *list)
{

	int i = 0;

	list_node_t *curr = list->head;

	for ( i=0; i<list->len; i++ ) {

		printf("Node-%d val=%s\n", i+1, (char *)curr->val);

		curr = curr->next; 
	}
}


//
// Push a node.
//
list_node_t *
ListTailPush(list_t *list, list_node_t *node)
{

	if ( node == NULL )
		return NULL;

	if ( list->len ) {

		list->tail->next = node;
		list->tail = node;

		node->next = NULL;

	} else {

		list->head = node;
		list->tail = node;

		node->next = NULL;

	}

	list->len++;

	return node;
}


//
// Pop a node.
//
list_node_t *
ListHeadPop(list_t *list)
{

	if ( list->len == 0 )
		return NULL;

	list_node_t *node = list->head;

	if ( --list->len ) {

		list->head = list->head->next;

	} else {

		list->head = list->tail = NULL;

	}

	node->next = NULL;

	return node;

}


//
// New a node.
//
list_node_t *



int main(int argc, char const *argv[])
{
	printf("list test.\n");

	return 0;
}
