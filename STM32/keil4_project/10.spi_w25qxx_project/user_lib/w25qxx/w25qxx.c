#include "w25qxx.h"
#include "spi.h"
#include "delay.h"

#define W25QXX_WRITE_ENABLE							0x06
#define W25QXX_WRITE_DISABLE 						0x04
#define W25QXX_WRITE_STATUS_REGISTER		0x01
#define W25QXX_READ_STATUS_REGISTER			0x05
#define W25QXX_READ_DATA								0x03
#define W25QXX_FAST_READ_DATA						0x0B
#define W25QXX_FAST_READ_DUAL						0x3B
#define W25QXX_PAGE_PROGRAM							0x02
#define W25QXX_BALOCK_ERASE							0xD8
#define W25QXX_SECTOR_ERASE							0x20
#define W25QXX_CHIP_ERASE								0xC7
#define W25QXX_POWER_DOWN								0xB9
#define W25QXX_RELEASE_POWER_DOWN				0xAB 
#define W25QXX_DEVICE_ID								0xAB
#define W25QXX_MANUFACT_DEVICE_ID				0x90
#define W25QXX_JEDEC_DEVICE_ID					0x9F



unsigned char w25qxx_read_state_register(void)   
{  
	u8 byte=0;   
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	spi_read_write_byte(W25QXX_READ_STATUS_REGISTER); 
	byte = spi_read_write_byte(0Xff); 
	GPIO_SetBits(GPIOB,GPIO_Pin_12);   
	return byte;   
}

void w25qxx_write_state_register(unsigned char state_register)   
{   
	GPIO_ResetBits(GPIOB,GPIO_Pin_12); 
	spi_read_write_byte(W25QXX_WRITE_STATUS_REGISTER);   
	spi_read_write_byte(state_register); 
	GPIO_SetBits(GPIOB,GPIO_Pin_12);  	      
} 

void w25qxx_write_enable(void)   
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);   
  spi_read_write_byte(W25QXX_WRITE_ENABLE); 
	GPIO_SetBits(GPIOB,GPIO_Pin_12);     	      
}

void w25qxx_write_disable(void)   
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);   
  spi_read_write_byte(W25QXX_WRITE_DISABLE); 
	GPIO_SetBits(GPIOB,GPIO_Pin_12);     	      
}

void w25qxx_wait_busy(void)   
{   
	while((w25qxx_read_state_register()&0x01)==0x01);  		// µÈ´ýBUSYÎ»Çå¿Õ
} 

unsigned int w25qxx_read_id(void)
{
	u16 Temp = 0;	  
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);				    
	spi_read_write_byte(W25QXX_MANUFACT_DEVICE_ID);	    
	spi_read_write_byte(0x00); 	    
	spi_read_write_byte(0x00); 	    
	spi_read_write_byte(0x00); 	 			   
	Temp |= spi_read_write_byte(0xFF)<<8;  
	Temp |= spi_read_write_byte(0xFF);	 
	GPIO_SetBits(GPIOB,GPIO_Pin_12);			    
	return Temp;
}

void w25qxx_read(unsigned char *pBuffer, unsigned int ReadAddr, unsigned int NumByteToRead)   
{ 
 	unsigned int i;   										    
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);  
	spi_read_write_byte(W25QXX_READ_DATA); 
	spi_read_write_byte((unsigned char)((ReadAddr)>>16));   
	spi_read_write_byte((unsigned char)((ReadAddr)>>8));   
	spi_read_write_byte((unsigned char)ReadAddr);   
	for(i = 0; i < NumByteToRead; i++) { 
			pBuffer[i] = spi_read_write_byte(0XFF);
	}
	GPIO_SetBits(GPIOB,GPIO_Pin_12); 				    	      
} 

void w25qxx_write_page(unsigned char *pBuffer,unsigned int WriteAddr,unsigned int NumByteToWrite)
{
 	unsigned int i;  
  w25qxx_write_enable();
	GPIO_ResetBits(GPIOB,GPIO_Pin_12); 
  spi_read_write_byte(W25QXX_PAGE_PROGRAM);
  spi_read_write_byte((unsigned char)((WriteAddr)>>16));
  spi_read_write_byte((unsigned char)((WriteAddr)>>8));   
  spi_read_write_byte((unsigned char)WriteAddr);   
  for(i=0;i<NumByteToWrite;i++) {
		spi_read_write_byte(pBuffer[i]);
	}		
	GPIO_SetBits(GPIOB,GPIO_Pin_12);	 
	w25qxx_wait_busy();
} 

void w25qxx_write_no_check(unsigned char *pBuffer,unsigned int WriteAddr,unsigned int NumByteToWrite)   
{ 			 		 
	unsigned int pageremain;	   
	pageremain = 256 - WriteAddr % 256;	    
	if(NumByteToWrite<=pageremain) {
		pageremain = NumByteToWrite;
	}
	while(1)
	{	   
		w25qxx_write_page(pBuffer, WriteAddr, pageremain);
		if(NumByteToWrite == pageremain)
			break;
	 	else
		{
			pBuffer += pageremain;
			WriteAddr += pageremain;	
			NumByteToWrite -= pageremain;
			if(NumByteToWrite>256)
				pageremain = 256;
			else 
				pageremain = NumByteToWrite;
		}
	};	    
} 

unsigned char w25qxx_buffer[4096];		 
void w25qxx_write(unsigned char *pBuffer,unsigned int WriteAddr,unsigned int NumByteToWrite)   
{ 
	unsigned int secpos;
	unsigned int secoff;
	unsigned int secremain;	   
 	unsigned int i;    
	unsigned char *W25QXX_BUF;	  
  W25QXX_BUF = w25qxx_buffer;	     
 	secpos = WriteAddr / 4096;
	secoff = WriteAddr % 4096;
	secremain = 4096 - secoff;
 	if(NumByteToWrite <= secremain)
		secremain = NumByteToWrite;
	while(1) 
	{	
		w25qxx_read(W25QXX_BUF,secpos*4096,4096);
		for(i = 0; i < secremain; i++)
		{
			if(W25QXX_BUF[secoff+i] != 0XFF)
				break;
		}
		if(i < secremain)
		{
			w25qxx_erase_sector(secpos);
			for(i = 0; i < secremain; i++)
			{
				W25QXX_BUF[i+secoff] = pBuffer[i];	  
			}
			w25qxx_write_no_check(W25QXX_BUF,secpos*4096,4096);
		}
		else 
			w25qxx_write_no_check(pBuffer,WriteAddr,secremain);				   
		if(NumByteToWrite == secremain)
			break;
		else
		{
			secpos++;
			secoff = 0; 
		  pBuffer += secremain;
			WriteAddr += secremain;  
		  NumByteToWrite -= secremain;
			if(NumByteToWrite>4096)
				secremain = 4096;
			else 
				secremain = NumByteToWrite;
		}	 
	};	 
}

void w25qxx_erase_chip(void)   
{                                   
	w25qxx_write_enable();
	w25qxx_wait_busy();   
	GPIO_ResetBits(GPIOB,GPIO_Pin_12); 
	spi_read_write_byte(W25QXX_CHIP_ERASE);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);    	      
	w25qxx_wait_busy();
}

void w25qxx_erase_sector(unsigned int Dst_Addr)   
{  
 	Dst_Addr*=4096;
	w25qxx_write_enable();
	w25qxx_wait_busy();   
  GPIO_ResetBits(GPIOB,GPIO_Pin_12);  
	spi_read_write_byte(W25QXX_SECTOR_ERASE);
	spi_read_write_byte((u8)((Dst_Addr)>>16));  
	spi_read_write_byte((u8)((Dst_Addr)>>8));   
	spi_read_write_byte((u8)Dst_Addr);  
	GPIO_SetBits(GPIOB,GPIO_Pin_12);    	      
	w25qxx_wait_busy();
}

void w25qxx_power_down(void)   
{ 
  GPIO_ResetBits(GPIOB,GPIO_Pin_12);  
  spi_read_write_byte(W25QXX_POWER_DOWN);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);       	      
  delay_us(3); 
}

void w25qxx_wakeup(void)   
{  
  GPIO_ResetBits(GPIOB,GPIO_Pin_12); 
  spi_read_write_byte(W25QXX_RELEASE_POWER_DOWN);  
	GPIO_SetBits(GPIOB,GPIO_Pin_12);     	      
  delay_us(3);
}
