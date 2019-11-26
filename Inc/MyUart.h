#ifndef _MYUART_
#define _MYUART_
#include "usart.h"
#include <stdint.h>

#define RECEIVELEN 100
#define USART_DMA_SENDING 1//�����б�־λ
#define USART_DMA_SENDOVER 0//������ɱ�־λ

class MyUart {
	public:
		uint8_t receive_flag:1;//���н��ձ��
		uint8_t dmaSend_flag:1;//������ɱ��
		uint16_t rx_len;//���ճ���
		uint8_t usartDMA_rxBuf[RECEIVELEN];//DMA���ջ���
		MyUart(UART_HandleTypeDef*);
		void SendData_DMA(uint8_t *pdata, uint16_t Length);
	private:
		UART_HandleTypeDef* uart;		
};

extern MyUart *Uart1;

void MyUart_Init(MyUart ** uart,UART_HandleTypeDef* inituart);


#endif

