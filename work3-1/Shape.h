/**
  ******************************************************************************
  * @file    Shape.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-24
  * @brief   Shape class
  * @encode  GB2312
  ******************************************************************************
  */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __Shape_H
#define __Shape_H

/* Includes ------------------------------------------------------------------*/
#include <iostream>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class Shape {
public:
	virtual ~Shape() {}
	friend ostream& operator<<(ostream& out, const Shape& source);

};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Shape& source);
#endif /* !__Shape_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
