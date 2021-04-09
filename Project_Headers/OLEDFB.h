/*
 * OLEDFB.h
 *
 *  Created on: Mar 5, 2021
 *      Author: ª∆”÷”÷
 */

#ifndef OLEDRFB_H_
#define OLEDRFB_H_


#define OLEDFB_BLACK 0
#define OLEDFB_WHITE 1
#define OLEDFB_INVERTED 2
#define OLEDFB_BORDER 3

#include "Types.h"

void OLEDFB_init();
void OLEDFB_clear();
void OLEDF_setPixelColumn(uint8 x,uint8 y,uint8 data);
void OLEDFB_setPixelBlack(uint8 x, uint8 y);
void OLEDFB_setPixelWhite(uint8 x, uint8 y);
void OLEDFB_setPixelInverted(uint8 x, uint8 y);
void OLEDFB_flush();

void OLEDFB_getPixel();

void OLEDFB_drawPixel(uint8 x, uint8 y, uint8 mode);

void OLEDFB_drawBitmap(uint8 x, uint8 y, const uchar* bitmap, uint8 srcWidth, uint8 srcHeight);

void OLEDFB_drawBitmapEx(uint8 x, uint8 y, uint8 width, uint8 height, const uchar* bitmap, uint8 srcWidth, uint8 srcHeight);

void OLEDFB_drawChar(uint8 x, uint8 y, const uchar c);
void OLEDFB_drawCharEx(uint8 x, uint8 y, uint8 charWidth, uint8 charHeight, const uchar c);
void OLEDFB_drawText(uint8 x, uint8 y, const char* str);
void OLEDFB_drawTextEx(uint8 x, uint8 y, uint8 charWidth, uint8 charHeight, const char* str);

void OLEDFB_drawRect(int16 x1, int16 y1, int16 x2, int16 y2, uint16 mode);
void OLEDFB_drawLine(int16 x1, int16 y1, int16 x2, int16 y2);
void OLEDFB_drawCircle(int8 x, int8 y, int8 r, uint8 mode);

#endif /* OLEDRFB_H_ */
