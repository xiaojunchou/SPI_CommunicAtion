#ifndef __SPI_H
#define __SPI_H

/****SPI通信引脚定义**********************************************************************************************************************************************************************************************/
#define IOx 		GPIOA		//使用的GPIO
#define SPI_CLK 	GPIO_Pin_0	//时钟（SCL）（D0）
#define SPI_DIN 	GPIO_Pin_1	//数据（SDA）（D1）
#define SPI_Res 	GPIO_Pin_2	//复位（RES）
#define SPI_DC	 	GPIO_Pin_3	//命令（DC）
#define SPI_CS  	GPIO_Pin_4	//片选（CS）

/****模拟SPI信号高低电平**********************************************************************************************************************************************************************************************/
#define SPI_DIN0 GPIO_ResetBits(IOx,SPI_DIN)//0
#define SPI_DIN1 GPIO_SetBits(IOx,SPI_DIN)	//1

#define SPI_CLK0 GPIO_ResetBits(IOx,SPI_CLK)
#define SPI_CLK1 GPIO_SetBits(IOx,SPI_CLK)

#define SPI_CS0 GPIO_ResetBits(IOx,SPI_CS)
#define SPI_CS1 GPIO_SetBits(IOx,SPI_CS)

#define SPI_DC0 GPIO_ResetBits(IOx,SPI_DC)
#define SPI_DC1 GPIO_SetBits(IOx,SPI_DC)

#define SPI_Res0 GPIO_ResetBits(IOx,SPI_Res)
#define SPI_Res1 GPIO_SetBits(IOx,SPI_Res)

void SPI_INIT(void);
void SPI_W8DATA(uint8_t DATA);
void SPI_W16DATA(uint8_t Cmd,uint8_t Bat);

void SPI_DATA_or_Cmd(u8 Dat,u8 Cmd);
void SPI_WByte(u8 Dat);
void SPI_WCmd(u8 Cmd);

#endif
