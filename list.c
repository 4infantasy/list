
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
ListNodeNew(char *str)
{

	list_node_t *node;

	node = LIST_MALLOC(sizeof(list_node_t));

	if ( node == NULL )
		return NULL;

	node->next = NULL;

	node->val = str;

	return node;
}


//
// List loop add node.
//
list_node_t *
ListLoopAddNode(list_t *list, list_node_t *node)
{

	if ( list == NULL || node == NULL )
		return NULL;

	if ( list->len < LIST_MAX ) {

		ListTailPush(list, node);

	} else {

		list_node_t *head;

		head = ListHeadPop(list);

		//LIST_FREE(head->val);
		head->next = NULL;
		LIST_FREE(head);

		ListTailPush(list, node);
	}

}



int main(int argc, char const *argv[])
{

	list_t * list = ListCreate();

	ListLoopAddNode(list, ListNodeNew("abc1"));

	ListLoopAddNode(list, ListNodeNew("def2"));

	ListLoopAddNode(list, ListNodeNew("abc3"));

	ListLoopAddNode(list, ListNodeNew("def4"));

	ListLoopAddNode(list, ListNodeNew("abc5"));

	ListLoopAddNode(list, ListNodeNew("sss6"));

	ListLoopAddNode(list, ListNodeNew("fff7"));

	ListPrint(list);

	list_node_t *node = ListHeadPop(list);

	printf("pop a node : val=%s\n", (char *)node->val);

	LIST_FREE(node);

	ListPrint(list);

	printf("push a new node : val=ggg8\n");

	ListLoopAddNode(list, ListNodeNew("ggg8"));

	ListPrint(list);

	printf("push a new node : val=hhh9\n");

	ListLoopAddNode(list, ListNodeNew("hhh9"));

	ListPrint(list);

	return 0;
}
