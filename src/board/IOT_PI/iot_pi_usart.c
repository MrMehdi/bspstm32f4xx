/*********************************************************************************************************
**
**                                ���������Ϣ�������޹�˾
**
**                                  ΢�Ͱ�ȫʵʱ����ϵͳ
**
**                                      MS-RTOS(TM)
**
**                               Copyright All Rights Reserved
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**
** ��   ��   ��: iot_pi_usart.c
**
** ��   ��   ��: Yu.kangzhi
**
** �ļ���������: 2020 �� 04 �� 07 ��
**
** ��        ��: IoT Pi USART ����
*********************************************************************************************************/
#include "ms_config.h"
#include "ms_rtos.h"
#include "includes.h"
#include "iot_pi.h"

UART_HandleTypeDef Usart1Handle;

/**
  * @brief UART MSP Initialization
  * @param channel: UART channel
  * @param channel: UART irq pointer
  * @param channel: UART handler pointer pointer
  * @retval error code; 0, success; other, failed
  */
ms_err_t stm32_uart_get_hw_info(ms_uint8_t channel, IRQn_Type *irq, UART_HandleTypeDef **handler)
{
    if (!irq || !handler) {
        return MS_ERR;
    }

    switch (channel) {
    case 1:
        Usart1Handle.Instance = USART1;
        *irq = USART1_IRQn;
        *handler = &Usart1Handle;
        break;

    default:
        return MS_ERR;
    }

    return MS_ERR_NONE;
}

/**
  * @brief UART MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  *           - NVIC configuration for UART interrupt request enable
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    GPIO_InitTypeDef GPIO_Initure;

    if (huart->Instance == USART1) {

        /* USART1_TX: PA9, USART1_RX: PA10 */

        /* ##-1- Enable peripherals and GPIO Clocks */

        /* Enable GPIO TX/RX clock */
        __HAL_RCC_GPIOA_CLK_ENABLE();

        /* Enable USARTx clock */
        __HAL_RCC_USART1_CLK_ENABLE();

        /*##-2- Configure peripheral GPIO */

        /* UART TX RX GPIO pin configuration  */
        GPIO_Initure.Pin       = GPIO_PIN_9 | GPIO_PIN_10;
        GPIO_Initure.Mode      = GPIO_MODE_AF_PP;
        GPIO_Initure.Pull      = GPIO_PULLUP;
        GPIO_Initure.Speed     = GPIO_SPEED_HIGH;
        GPIO_Initure.Alternate = GPIO_AF7_USART1;
        HAL_GPIO_Init(GPIOA, &GPIO_Initure);

    } else {
        ms_printk(MS_PK_ERR, "this uart not support now!\n\r");
    }
}

/**
  * @brief UART MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO and NVIC configuration to their default state
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1) {
        __HAL_RCC_USART1_FORCE_RESET();
        __HAL_RCC_USART1_RELEASE_RESET();

        /* UART TX GPIO pin configuration  */
        HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9 | GPIO_PIN_10);

    } else {
        ms_printk(MS_PK_ERR, "this uart not support now!\n\r");
    }
}
/*********************************************************************************************************
   END
*********************************************************************************************************/
