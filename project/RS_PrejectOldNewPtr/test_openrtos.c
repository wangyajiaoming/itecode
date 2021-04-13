#include <pthread.h>
#include "openrtos/FreeRTOS.h"
#include "openrtos/task.h"
//#include "uart1.h"

#define TEST_STACK_SIZE 1024000

#ifdef CFG_DBG_UART0
#undef CFG_UART0_INTR
#undef CFG_UART0_DMA
#undef CFG_UART0_FIFO
#endif
#ifdef CFG_DBG_UART1
#undef CFG_UART1_INTR
#undef CFG_UART1_DMA
#undef CFG_UART1_FIFO
#endif

#if defined(CFG_UART0_INTR) || defined(CFG_UART1_INTR)\
	|| defined(CFG_UART2_INTR) || defined(CFG_UART3_INTR)\
	|| defined(CFG_UART4_INTR) || defined(CFG_UART5_INTR)
#define VERIFY_INTR_MODE
#endif

#if defined(CFG_UART0_DMA) || defined(CFG_UART1_DMA)\
	|| defined(CFG_UART2_DMA) || defined(CFG_UART3_DMA)\
	|| defined(CFG_UART4_DMA) || defined(CFG_UART5_DMA)
#define VERIFY_DMA_MODE
#endif

#if defined(CFG_UART0_FIFO) || defined(CFG_UART1_FIFO)\
	|| defined(CFG_UART2_FIFO) || defined(CFG_UART3_FIFO)\
	|| defined(CFG_UART4_FIFO) || defined(CFG_UART5_FIFO)
#define VERIFY_FIFO_MODE
#endif

#if defined(VERIFY_INTR_MODE)
extern void* TestFuncUseINTR(void* arg);
#elif defined(VERIFY_DMA_MODE)
extern void* TestFuncUseDMA(void* arg);
#elif defined(VERIFY_FIFO_MODE)
extern void* TestFuncUseFIFO(void* arg);
#endif
extern void* TestFunc(void* arg);

extern void* uart_dataprocess(void);

void TextUartInit(void)
{
	pthread_t task;
	pthread_t Tx_task;

	pthread_create(&Tx_task, NULL, uart_dataprocess, NULL);
	
	#if defined(VERIFY_INTR_MODE)
		pthread_create(&task, NULL, TestFuncUseINTR, NULL);
	#elif defined(VERIFY_DMA_MODE)
		pthread_create(&task, NULL, TestFuncUseDMA, NULL);
	#elif defined(VERIFY_FIFO_MODE)
		pthread_create(&task, NULL, TestFuncUseFIFO, NULL);
	#endif
}



