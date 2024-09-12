#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "uart.h"
#include "adc.h"


SPI_HandleTypeDef hspi1;

DMA_HandleTypeDef hdma_spi1_rx;
DMA_HandleTypeDef hdma_spi1_tx;

void spi1_init(void);

uint8_t  tx_buffer[10]={10,20,20,40,50,60,70,90,90,100};
uint8_t  rx_buffer[10];




int main()
{

  HAL_Init();
  spi1_init();


  HAL_SPI_TransmitReceive_DMA(&hspi1,tx_buffer,rx_buffer,10);


  while(1)
  {



  }
}


void spi1_init(void)
{
   GPIO_InitTypeDef GPIO_InitStruct = {0};
   __HAL_RCC_SPI1_CLK_ENABLE();
   __HAL_RCC_GPIOA_CLK_ENABLE();

   /* PA5     ------> SPI1_SCK
      PA6     ------> SPI1_MISO
      PA7     ------> SPI1_MOSI */

   GPIO_InitStruct.Pin  = GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
   GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
   GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
   GPIO_InitStruct.Pull = GPIO_NOPULL;
   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
   HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

   //Configure SPI module

   hspi1.Instance =  SPI1;
   hspi1.Init.Mode = SPI_MODE_MASTER;
   hspi1.Init.Direction = SPI_DIRECTION_2LINES;
   hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
   hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
   hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
   hspi1.Init.NSS = SPI_NSS_SOFT;
   hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
   hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
   hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
   hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;

   HAL_SPI_Init(&hspi1);

   // Configure DMA
   __HAL_RCC_DMA2_CLK_ENABLE();


   //Configure rx

   hdma_spi1_rx.Instance = DMA2_Stream0;
   hdma_spi1_rx.Init.Channel = DMA_CHANNEL_3;
   hdma_spi1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
   hdma_spi1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
   hdma_spi1_rx.Init.MemInc = DMA_MINC_ENABLE;
   hdma_spi1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
   hdma_spi1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
   hdma_spi1_rx.Init.Mode = DMA_NORMAL;
   hdma_spi1_rx.Init.Priority = DMA_PRIORITY_LOW;
   hdma_spi1_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
   HAL_DMA_Init(&hdma_spi1_rx);

   hspi1.hdmarx = &hdma_spi1_rx;


   HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
   HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);


   //Configure tx

   hdma_spi1_tx.Instance = DMA2_Stream2;
   hdma_spi1_tx.Init.Channel = DMA_CHANNEL_2;
   hdma_spi1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
   hdma_spi1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
   hdma_spi1_tx.Init.MemInc = DMA_MINC_ENABLE;
   hdma_spi1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
   hdma_spi1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
   hdma_spi1_tx.Init.Mode = DMA_NORMAL;
   hdma_spi1_tx.Init.Priority = DMA_PRIORITY_LOW;
   hdma_spi1_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
   HAL_DMA_Init(&hdma_spi1_tx);

   hspi1.hdmatx = &hdma_spi1_tx;

   HAL_NVIC_SetPriority(DMA2_Stream2_IRQn, 0, 0);
   HAL_NVIC_EnableIRQ(DMA2_Stream2_IRQn);


}

void DMA2_Stream0_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_spi1_rx);
}

void DMA2_Stream2_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&hdma_spi1_tx);

}


void  SysTick_Handler(void)
{
	HAL_IncTick();
}



