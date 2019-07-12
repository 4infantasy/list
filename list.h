
//
// list.h
//


#ifndef __LIST_H__
#define __LIST_H__


#ifdef __cplusplus
extern "C" {
#endif


#include <stdio.h>
#include <stdlib.h>


#define LIST_MAX	32


#ifndef LIST_MALLOC
#define LIST_MALLOC	malloc
#endif


#ifndef LIST_FREE
#define LIST_FREE	free
#endif




typedef struct list_node {

	struct list_node *next;
	void   *val;

} list_node_t ;





#ifdef __cplusplus
}
#endif


#endif