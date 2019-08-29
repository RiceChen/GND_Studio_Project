/***************************************************
 *         Author: Hoky GUAN                       *
 *         Date  : 2019/7/25                       *
 *         Last  : 2019/7/25                       *
 *         Notes : iic.h                           *
 **************************************************/
#ifndef _IIC_H_
#define _IIC_H_

#include <reg52.h>

void IIC_Start();

void IIC_Stop();

void IIC_Enable(char enable);

void IIC_Write_Byte(unsigned char IIC_Byte);

#endif
