#ifndef INC_FREERTOS_H
#define INC_FREERTOS_H

#include <stdint.h>

#define pvPortMalloc malloc
#define vPortFree free

// lib/include/private/projdefs.h
typedef void *TaskFunction_t( void *p );

#define pdFALSE			( 0 )
#define pdTRUE			( 1 )

#define pdPASS			( pdTRUE )
#define pdFAIL			( pdFALSE )
#define errQUEUE_EMPTY	( ( BaseType_t ) 0 )
#define errQUEUE_FULL	( ( BaseType_t ) 0 )

/* FreeRTOS error definitions. */
#define errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY	( -1 )
#define errQUEUE_BLOCKED						( -4 )
#define errQUEUE_YIELD							( -5 )

// lib/FreeRTOS/portable/ThirdParty/GCC/Xtensa_ESP32/include/portmacro.h
#define portCHAR		int8_t
#define portFLOAT		float
#define portDOUBLE		double
#define portLONG		int32_t
#define portSHORT		int16_t
#define portSTACK_TYPE	uint8_t
#define portBASE_TYPE	int
#define portUSING_MPU_WRAPPERS 0

typedef portSTACK_TYPE			StackType_t;

/*@
predicate StackType_pred(uint8_t *array, int size) =
    uchars(array, size, _)
    &*& malloc_block_uchars(array, size);
@*/

typedef portBASE_TYPE			BaseType_t;
typedef unsigned portBASE_TYPE	UBaseType_t;

typedef uint32_t TickType_t;
#define portMAX_DELAY ( TickType_t ) 0xffffffffUL

#define portTASK_FUNCTION_PROTO( vFunction, pvParameters ) void vFunction( void *pvParameters )
#define portTASK_FUNCTION( vFunction, pvParameters ) void vFunction( void *pvParameters )

#define PRIVILEGED_FUNCTION
#define PRIVILEGED_DATA
#define portSTACK_GROWTH (-1)
#define portCRITICAL_NESTING_IN_TCB 1

// demos/espressif/esp32_devkitc_esp_wrover_kit/common/config_files/FreeRTOSConfig.h
#define configUSE_PREEMPTION 1
#define configMAX_PRIORITIES 7
#define configUSE_16_BIT_TICKS 0
#define configUSE_TRACE_FACILITY 0 /* xxx Should be 1 */
#define configCHECK_FOR_STACK_OVERFLOW 0
#define INCLUDE_uxTaskGetStackHighWaterMark 0
#define INCLUDE_vTaskSuspend 0 /* xxx Should be 1 */
#define INCLUDE_xTaskGetSchedulerState 1
#define configUSE_TIMERS 1
#define INCLUDE_xTaskGetIdleTaskHandle 1
#define INCLUDE_xTaskGetCurrentTaskHandle 1
#define configUSE_MUTEXES 0 /* xxx Should be 1 */
#define INCLUDE_xTaskAbortDelay 1
#define configGENERATE_RUN_TIME_STATS 1
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS 0
#define configUSE_APPLICATION_TASK_TAG 0
#define configUSE_IDLE_HOOK 0
#define configUSE_TICK_HOOK 0
#define configUSE_NEWLIB_REENTRANT 0 /* xxx Should be 1 */
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 1
#define configIDLE_SHOULD_YIELD 0
#define configUSE_STATS_FORMATTING_FUNCTIONS 1
#define INCLUDE_uxTaskPriorityGet 1
#define INCLUDE_vTaskDelayUntil 1
#define INCLUDE_vTaskDelay 1
#define INCLUDE_vTaskDelete 1
#define INCLUDE_vTaskPrioritySet 1

// lib/include/private/portable.h
// portBYTE_ALIGNMENT=4
#define portBYTE_ALIGNMENT_MASK	( 0x0003 )

StackType_t *pxPortInitialiseStack( StackType_t *pxTopOfStack, TaskFunction_t pxCode, void *pvParameters );
    //@ requires true;
    //@ ensures true;

// lib/include/FreeRTOS.h
#define configMAX_TASK_NAME_LEN 16
#define configINITIAL_TICK_COUNT 0
#define configINCLUDE_FREERTOS_TASK_C_ADDITIONS_H 0
#define configUSE_STATS_FORMATTING_FUNCTIONS 0 /* xxx Should be 1 */
#define configSTACK_DEPTH_TYPE uint16_t
#define configSUPPORT_DYNAMIC_ALLOCATION 1
#define configSUPPORT_STATIC_ALLOCATION 1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0
#define configRECORD_STACK_HIGH_ADDRESS 1
#define INCLUDE_xTaskResumeFromISR 1
#define INCLUDE_xTaskGetHandle 0
#define configUSE_TIME_SLICING 1

#define configASSERT( x )
#define configASSERT_DEFINED 0

#define portPRIVILEGE_BIT ( ( UBaseType_t ) 0x00 )
#define portPOINTER_SIZE_TYPE uint32_t
#define mtCOVERAGE_TEST_MARKER()

#define traceSTART()
#define traceEND()
#define traceTASK_SWITCHED_IN()
#define traceINCREASE_TICK_COUNT( x )
#define traceLOW_POWER_IDLE_BEGIN()
#define traceLOW_POWER_IDLE_END()
#define traceTASK_SWITCHED_OUT()
#define traceTASK_PRIORITY_INHERIT( pxTCBOfMutexHolder, uxInheritedPriority )
#define traceTASK_PRIORITY_DISINHERIT( pxTCBOfMutexHolder, uxOriginalPriority )
#define traceBLOCKING_ON_QUEUE_RECEIVE( pxQueue )
#define traceBLOCKING_ON_QUEUE_PEEK( pxQueue )
#define traceBLOCKING_ON_QUEUE_SEND( pxQueue )
#define traceMOVED_TASK_TO_READY_STATE( pxTCB )
#define tracePOST_MOVED_TASK_TO_READY_STATE( pxTCB )
#define traceQUEUE_CREATE( pxNewQueue )
#define traceQUEUE_CREATE_FAILED( ucQueueType )
#define traceCREATE_MUTEX( pxNewQueue )
#define traceCREATE_MUTEX_FAILED()
#define traceGIVE_MUTEX_RECURSIVE( pxMutex )
#define traceGIVE_MUTEX_RECURSIVE_FAILED( pxMutex )
#define traceTAKE_MUTEX_RECURSIVE( pxMutex )
#define traceTAKE_MUTEX_RECURSIVE_FAILED( pxMutex )
#define traceCREATE_COUNTING_SEMAPHORE()
#define traceCREATE_COUNTING_SEMAPHORE_FAILED()
#define traceQUEUE_SEND( pxQueue )
#define traceQUEUE_SEND_FAILED( pxQueue )
#define traceQUEUE_RECEIVE( pxQueue )
#define traceQUEUE_PEEK( pxQueue )
#define traceQUEUE_PEEK_FAILED( pxQueue )
#define traceQUEUE_PEEK_FROM_ISR( pxQueue )
#define traceQUEUE_RECEIVE_FAILED( pxQueue )
#define traceQUEUE_SEND_FROM_ISR( pxQueue )
#define traceQUEUE_SEND_FROM_ISR_FAILED( pxQueue )
#define traceQUEUE_RECEIVE_FROM_ISR( pxQueue )
#define traceQUEUE_RECEIVE_FROM_ISR_FAILED( pxQueue )
#define traceQUEUE_PEEK_FROM_ISR_FAILED( pxQueue )
#define traceQUEUE_DELETE( pxQueue )
#define traceTASK_CREATE( pxNewTCB )
#define traceTASK_CREATE_FAILED()
#define traceTASK_DELETE( pxTaskToDelete )
#define traceTASK_DELAY_UNTIL( x )
#define traceTASK_DELAY()
#define traceTASK_PRIORITY_SET( pxTask, uxNewPriority )
#define traceTASK_SUSPEND( pxTaskToSuspend )
#define traceTASK_RESUME( pxTaskToResume )
#define traceTASK_RESUME_FROM_ISR( pxTaskToResume )
#define traceTASK_INCREMENT_TICK( xTickCount )
#define traceTIMER_CREATE( pxNewTimer )
#define traceTIMER_CREATE_FAILED()
#define traceTIMER_COMMAND_SEND( xTimer, xMessageID, xMessageValueValue, xReturn )
#define traceTIMER_EXPIRED( pxTimer )
#define traceTIMER_COMMAND_RECEIVED( pxTimer, xMessageID, xMessageValue )
#define traceMALLOC( pvAddress, uiSize )
#define traceFREE( pvAddress, uiSize )
#define traceEVENT_GROUP_CREATE( xEventGroup )
#define traceEVENT_GROUP_CREATE_FAILED()
#define traceEVENT_GROUP_SYNC_BLOCK( xEventGroup, uxBitsToSet, uxBitsToWaitFor )
#define traceEVENT_GROUP_SYNC_END( xEventGroup, uxBitsToSet, uxBitsToWaitFor, xTimeoutOccurred ) ( void ) xTimeoutOccurred
#define traceEVENT_GROUP_WAIT_BITS_BLOCK( xEventGroup, uxBitsToWaitFor )
#define traceEVENT_GROUP_WAIT_BITS_END( xEventGroup, uxBitsToWaitFor, xTimeoutOccurred ) ( void ) xTimeoutOccurred
#define traceEVENT_GROUP_CLEAR_BITS( xEventGroup, uxBitsToClear )
#define traceEVENT_GROUP_CLEAR_BITS_FROM_ISR( xEventGroup, uxBitsToClear )
#define traceEVENT_GROUP_SET_BITS( xEventGroup, uxBitsToSet )
#define traceEVENT_GROUP_SET_BITS_FROM_ISR( xEventGroup, uxBitsToSet )
#define traceEVENT_GROUP_DELETE( xEventGroup )
#define tracePEND_FUNC_CALL(xFunctionToPend, pvParameter1, ulParameter2, ret)
#define tracePEND_FUNC_CALL_FROM_ISR(xFunctionToPend, pvParameter1, ulParameter2, ret)
#define traceQUEUE_REGISTRY_ADD(xQueue, pcQueueName)
#define traceTASK_NOTIFY_TAKE_BLOCK()
#define traceTASK_NOTIFY_TAKE()
#define traceTASK_NOTIFY_WAIT_BLOCK()
#define traceTASK_NOTIFY_WAIT()
#define traceTASK_NOTIFY()
#define traceTASK_NOTIFY_FROM_ISR()
#define traceTASK_NOTIFY_GIVE_FROM_ISR()
#define traceSTREAM_BUFFER_CREATE_FAILED( xIsMessageBuffer )
#define traceSTREAM_BUFFER_CREATE_STATIC_FAILED( xReturn, xIsMessageBuffer )
#define traceSTREAM_BUFFER_CREATE( pxStreamBuffer, xIsMessageBuffer )
#define traceSTREAM_BUFFER_DELETE( xStreamBuffer )
#define traceSTREAM_BUFFER_RESET( xStreamBuffer )
#define traceBLOCKING_ON_STREAM_BUFFER_SEND( xStreamBuffer )
#define traceSTREAM_BUFFER_SEND( xStreamBuffer, xBytesSent )
#define traceSTREAM_BUFFER_SEND_FAILED( xStreamBuffer )
#define traceSTREAM_BUFFER_SEND_FROM_ISR( xStreamBuffer, xBytesSent )
#define traceBLOCKING_ON_STREAM_BUFFER_RECEIVE( xStreamBuffer )
#define traceSTREAM_BUFFER_RECEIVE( xStreamBuffer, xReceivedLength )
#define traceSTREAM_BUFFER_RECEIVE_FAILED( xStreamBuffer )
#define traceSTREAM_BUFFER_RECEIVE_FROM_ISR( xStreamBuffer, xReceivedLength )

typedef struct xSTATIC_TCB
{
} StaticTask_t;

#endif /* INC_FREERTOS_H */
