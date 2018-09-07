#ifndef INC_TASK_H
#define INC_TASK_H

#include "list.h"

typedef void * TaskHandle_t;

typedef struct xTIME_OUT
{
} TimeOut_t;

typedef struct xMEMORY_REGION
{
} MemoryRegion_t;

typedef struct xTASK_PARAMETERS
{
} TaskParameters_t;

#define tskIDLE_PRIORITY			( ( UBaseType_t ) 0U )

#define taskYIELD()

#define taskENTER_CRITICAL()
#define taskENTER_CRITICAL_FROM_ISR()

#define taskEXIT_CRITICAL()
#define taskEXIT_CRITICAL_FROM_ISR( x )

#define taskDISABLE_INTERRUPTS()

#define taskENABLE_INTERRUPTS()

#endif /* INC_TASK_H */
