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
** ��   ��   ��: iot_pi_irq.c
**
** ��   ��   ��: Jiao.jinxing
**
** �ļ���������: 2020 �� 04 �� 07 ��
**
** ��        ��: IoT Pi �жϷ������
*********************************************************************************************************/
#include "ms_config.h"
#include "ms_rtos.h"
#include "includes.h"

#include "stm32_drv.h"

#if BSP_CFG_ESP8266_UPDATE_FW == 0
/**
 * @brief This function handles USART1 global interrupt.
 */
void USART1_IRQHandler(void)
{
    (void)ms_int_enter();

    stm32_uart_irq_handler(1);

    (void)ms_int_exit();
}
#endif

#if BSP_CFG_SD_EN > 0
extern SD_HandleTypeDef uSdHandle;

/**
 * @brief This function handles SDMMC1 global interrupt.
 */
void SDMMC1_IRQHandler(void)
{
    (void)ms_int_enter();

    HAL_SD_IRQHandler(&uSdHandle);

    (void)ms_int_exit();
}

/**
 * @brief This function handles DMA2 stream3 global interrupt.
 */
void DMA2_Stream3_IRQHandler(void)
{
    (void)ms_int_enter();

    HAL_DMA_IRQHandler(uSdHandle.hdmarx);

    (void)ms_int_exit();
}

/**
 * @brief This function handles DMA2 stream6 global interrupt.
 */
void DMA2_Stream6_IRQHandler(void)
{
    (void)ms_int_enter();

    HAL_DMA_IRQHandler(uSdHandle.hdmatx);

    (void)ms_int_exit();
}
#endif

void I2C1_EV_IRQHandler(void)
{
    (void)ms_int_enter();

    stm32_i2c_ev_irqhandler(1U);

    (void)ms_int_exit();
}

void I2C1_ER_IRQHandler(void)
{
    (void)ms_int_enter();

    stm32_i2c_er_irqhandler(1U);

    (void)ms_int_exit();
}

void I2C2_EV_IRQHandler(void)
{
    (void)ms_int_enter();

    stm32_i2c_ev_irqhandler(2U);

    (void)ms_int_exit();
}

void I2C2_ER_IRQHandler(void)
{
    (void)ms_int_enter();

    stm32_i2c_er_irqhandler(2U);

    (void)ms_int_exit();
}

void I2C3_EV_IRQHandler(void)
{
    (void)ms_int_enter();

    stm32_i2c_ev_irqhandler(3U);

    (void)ms_int_exit();
}

void I2C3_ER_IRQHandler(void)
{
    (void)ms_int_enter();

    stm32_i2c_er_irqhandler(3U);

    (void)ms_int_exit();
}

/*********************************************************************************************************
  END
*********************************************************************************************************/
