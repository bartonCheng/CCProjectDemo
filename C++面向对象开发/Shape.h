#pragma once //系统设定的防止重复引用类
#ifndef SHAPE_H 
//如果未定义 才定义此类
/*
* 说明 ： shape类计算形状的属性
* 1. Protected 修饰的变量和方法，可以被本类和继承的派生类访问。
* 2. Private 修饰的变量和方法，仅本类可以访问。作为权限屏蔽。
* 3. Public 修饰的变量和方法，属于公开的访问，无权限限制。
*/

class Shape
{
protected: //仅本类和派生类可用
	double shape_width{ 0 };
	double shape_length{ 0 };
	double shape_height{ 0 };
	double height{ 0 }; //高度
	double width{ 0 }; //宽度
public:
	//本类的构造方法
	//Shape() = delete;
	//本类的析构方法
	//~Shape();
	//显式初始化构造函数
	Shape(int i) : shape_width(i), shape_length(i), shape_height(i) {}

	double Volume(int i);

private:

};



#endif // !SHAPE_H 

