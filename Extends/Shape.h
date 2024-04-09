#ifndef __SHAPE_H

#include <iostream>
using namespace std;

class Shape
{
public:
	Shape() {}
	virtual ~Shape() {}
	void GetInfo() const {
		cout << "这是一个";
		Show();
		cout << endl << "它的面积是" << Area();
		cout << endl << "它的周长是" << Perimeter();
	}
	virtual void Show()const = 0;
	virtual double Area()const = 0;
	virtual double Perimeter()const = 0;
};

#endif // !__SHAPE_H
