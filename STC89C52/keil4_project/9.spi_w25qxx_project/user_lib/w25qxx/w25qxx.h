/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/15                       *
 *         Last  : 2019/7/15                       *
 *         Notes : w25qxx.h                        *
 **************************************************/
#ifndef _W25QXX_H_
#define _W25QXX_H_

#include <reg52.h>

#define W25Q80 	0XEF13 	
#define W25Q16 	0XEF14
#define W25Q32 	0XEF15
#define W25Q64 	0XEF16
#define W25Q128	0XEF17

#define FLASH_SIZE 4096

unsigned char w25qxx_read_state_register(void);
void w25qxx_write_state_register(unsigned char state_register);
void w25qxx_write_enable(void);
void w25qxx_write_disable(void);
void w25qxx_wait_busy(void);
unsigned int w25qxx_read_id(void);
void w25qxx_read(unsigned char *pBuffer, unsigned int ReadAddr, unsigned int NumByteToRead);
void w25qxx_write_page(unsigned char *pBuffer,unsigned int WriteAddr,unsigned int NumByteToWrite);
void w25qxx_write_no_check(unsigned char *pBuffer,unsigned int WriteAddr,unsigned int NumByteToWrite);
void w25qxx_write(unsigned char *pBuffer,unsigned int WriteAddr,unsigned int NumByteToWrite);
void w25qxx_erase_chip(void);
void w25qxx_erase_sector(unsigned int Dst_Addr);

#endif


