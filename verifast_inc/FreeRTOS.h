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

typedef portSTACK_TYPE			StackType_t;
typedef portBASE_TYPE			BaseType_t;
typedef unsigned portBASE_TYPE	UBaseType_t;

typedef uint32_t TickType_t;
#define portMAX_DELAY ( TickType_t ) 0xffffffffUL

#define portTASK_FUNCTION_PROTO( vFunction, pvParameters ) void vFunction( void *pvParameters )
#define portTASK_FUNCTION( vFunction, pvParameters ) void vFunction( void *pvParameters )

#define PRIVILEGED_FUNCTION
#define PRIVILEGED_DATA

// demos/espressif/esp32_devkitc_esp_wrover_kit/common/config_files/FreeRTOSConfig.h
#define configUSE_PREEMPTION 1
#define configMAX_PRIORITIES 7

// lib/include/FreeRTOS.h
#define configMAX_TASK_NAME_LEN 16
#define configINITIAL_TICK_COUNT 0
#define configINCLUDE_FREERTOS_TASK_C_ADDITIONS_H 0
#define configUSE_STATS_FORMATTING_FUNCTIONS 0

#endif /* INC_FREERTOS_H */
