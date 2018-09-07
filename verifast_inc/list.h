#ifndef LIST_H
#define LIST_H

#include "FreeRTOS.h"

#define configLIST_VOLATILE

struct xLIST_ITEM
{
	configLIST_VOLATILE TickType_t xItemValue;
	void * pvOwner;
};
typedef struct xLIST_ITEM ListItem_t;

typedef struct xLIST
{
} List_t;

#define listSET_LIST_ITEM_OWNER( pxListItem, pxOwner )		( ( pxListItem )->pvOwner = ( void * ) ( pxOwner ) )

#define listSET_LIST_ITEM_VALUE( pxListItem, xValue )	( ( pxListItem )->xItemValue = ( xValue ) )

void vListInitialiseItem( ListItem_t * const pxItem );
    //@ requires true;
    //@ ensures true;

void vListInsertEnd( List_t * const pxList, ListItem_t * const pxNewListItem );
    //@ requires true;
    //@ ensures true;

#endif
