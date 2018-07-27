#ifndef INC_FREERTOS_H
#define INC_FREERTOS_H

#include <stdint.h>

// lib/include/private/projdefs.h
typedef void *TaskFunction_t( void *p );

#define pdFALSE			( ( BaseType_t ) 0 )
#define pdTRUE			( ( BaseType_t ) 1 )

// lib/FreeRTOS/portable/ThirdParty/GCC/Xtensa_ESP32/include/portmacro.h
#define portCHAR		int8_t
#define portFLOAT		float
#define portDOUBLE		double
#define portLONG		int32_t
#define portSHORT		int16_t
#define portSTACK_TYPE	uint8_t
#define portBASE_TYPE	int
#define portUSING_MPU_WRAPPERS 1

typedef portSTACK_TYPE			StackType_t;
typedef portBASE_TYPE			BaseType_t;
typedef unsigned portBASE_TYPE	UBaseType_t;

typedef uint32_t TickType_t;
#define portMAX_DELAY ( TickType_t ) 0xffffffffUL

#define portTASK_FUNCTION_PROTO( vFunction, pvParameters ) void vFunction( void *pvParameters )
#define portTASK_FUNCTION( vFunction, pvParameters ) void vFunction( void *pvParameters )

#define PRIVILEGED_FUNCTION
#define PRIVILEGED_DATA

typedef struct {
} xMPU_SETTINGS;

#define portSTACK_GROWTH (-1)
#define portCRITICAL_NESTING_IN_TCB 1

// demos/espressif/esp32_devkitc_esp_wrover_kit/common/config_files/FreeRTOSConfig.h
#define configUSE_PREEMPTION 1
#define configMAX_PRIORITIES 7
#define configUSE_16_BIT_TICKS 0
#define configUSE_TRACE_FACILITY 0 /* xxx Should be 1 */
#define configCHECK_FOR_STACK_OVERFLOW 0
#define INCLUDE_uxTaskGetStackHighWaterMark 1
#define INCLUDE_vTaskSuspend 0 /* xxx Should be 1 */
#define INCLUDE_xTaskGetSchedulerState 1
#define configUSE_TIMERS 1
#define INCLUDE_xTaskGetIdleTaskHandle 1
#define INCLUDE_xTaskGetCurrentTaskHandle 1
#define configUSE_MUTEXES 0 /* xxx Should be 1 */
#define INCLUDE_xTaskAbortDelay 1

// lib/include/FreeRTOS.h
#define configMAX_TASK_NAME_LEN 16
#define configINITIAL_TICK_COUNT 0
#define configINCLUDE_FREERTOS_TASK_C_ADDITIONS_H 0
#define configUSE_STATS_FORMATTING_FUNCTIONS 0
#define configSTACK_DEPTH_TYPE uint16_t
#define configSUPPORT_DYNAMIC_ALLOCATION 1
#define configSUPPORT_STATIC_ALLOCATION 1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0
#define configRECORD_STACK_HIGH_ADDRESS 0
#define INCLUDE_xTaskResumeFromISR 1
#define INCLUDE_xTaskGetHandle 0

typedef struct xSTATIC_TCB
{
} StaticTask_t;

#endif /* INC_FREERTOS_H */
