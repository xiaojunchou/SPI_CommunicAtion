#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "SPI.h"

/**----------------------------------------------------------------------------------------------
  * @brief	初始化GPIO
  * @param  无
  * @retval 无
---------------------------------------------------------------------------------*/
void SPI_INIT(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = SPI_DIN | SPI_CLK | SPI_DC | SPI_CS | SPI_Res ;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
 	GPIO_SetBits(GPIOA,SPI_DIN | SPI_CLK | SPI_DC | SPI_CS | SPI_Res);//将IO口全部初始化为高电平
}

/**----------------------------------------------------------------------------------------------
  * @brief	写入8位数据
  * @param  DATA	发送的数据
  * @retval 无
---------------------------------------------------------------------------------*/
void SPI_W8DATA(uint8_t DATA)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		SPI_CLK0;
		if(DATA & (0x80>>i))
			SPI_DIN1;
		else
			SPI_DIN0;
		SPI_CLK1;
	}
}

/**----------------------------------------------------------------------------------------------
  * @brief	写入命令与数据
  * @param  Cmd	命令
			Bat	数据
  * @retval 无
---------------------------------------------------------------------------------*/
void SPI_W16DATA(uint8_t Cmd,uint8_t Bat)
{
	SPI_CS0;
	SPI_W8DATA(Cmd);
	SPI_W8DATA(Bat);
	SPI_CS1;
}

/**----------------------------------------------------------------------------------------------
  * @brief  写入一个字节数据或者命令
  * @param  Dat	数据
			Cmd 命令选择 0命令，1数据

  * @retval 无
---------------------------------------------------------------------------------*/
void SPI_DATA_or_Cmd(u8 Dat,u8 Cmd)
{
/****数据/命令判断**************************************************************************************************************/	
	if(Cmd){SPI_DC1;}else{SPI_DC0;}

/****开始循环发送一位8bit******************************************************************************************************************/
	SPI_CS0;
	SPI_W8DATA(Dat);
	SPI_CS1;//结束发送
	SPI_DC1;//结束命令发送
}

/**----------------------------------------------------------------------------------------------
  * @brief	写入一个字节数据
  * @param  Dat	数据0x**
  * @retval 无
---------------------------------------------------------------------------------*/
void SPI_WByte(u8 Dat)
{
	SPI_CS0;
	SPI_W8DATA(Dat);
	SPI_CS1;
}

/**----------------------------------------------------------------------------------------------
  * @brief	写入一个字节命令
  * @param  Cmd	命令 0x**
  * @retval 无
----------------------------------------------------------------------------------------------------*/
void SPI_WCmd(u8 Cmd)
{
	SPI_DC0;
	SPI_CS0;
	SPI_W8DATA(Cmd);
	SPI_CS1;
	SPI_DC1;
}
